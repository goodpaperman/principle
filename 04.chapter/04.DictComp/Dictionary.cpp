
#include "stdafx.h" 
#include "Dictionary.h" 
#include "Factory.h" 

CDictionary::CDictionary()
{
    m_nRef = 0; 
    m_pData = NULL; 
    m_nWordNumber = 0; 
    m_nStructNumber = 0; 
    g_DictionaryNumber ++; 
}

CDictionary::~CDictionary()
{
    g_DictionaryNumber--; 
    if(m_pData)
        delete[] m_pData; 

    if(CDictionaryFactory::CanUnloadNow())
        ::PostThreadMessage(dwMainThreadID, WM_QUIT, 0, 0); 
}

ULONG CDictionary::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CDictionary::Release()
{
    int ret = -- m_nRef; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)ret; 
}

HRESULT CDictionary::QueryInterface(const IID& iid, void** ppv)
{
    if(iid == IID_IUnknown)
    {
        *ppv = (IDictionary*)this; 
        ((IDictionary*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IDictionary)
    {
        *ppv = (IDictionary*)this; 
        ((IDictionary*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_ISpellCheck)
    {
        *ppv = (ISpellCheck*)this; 
        ((ISpellCheck*)(*ppv))->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    return S_OK; 
}

HRESULT CDictionary::Initialize()
{
    m_nWordNumber = 0; 
    m_nStructNumber = 0; 
    if(m_pData)
        delete[] m_pData; 

    m_pData = NULL; 
    return S_OK; 
}

HRESULT CDictionary::LoadLibrary(String filename)
{
    char* pFileName = _com_util::ConvertBSTRToString(filename); 
    FILE* fp = fopen(pFileName, "rt"); 
    if(fp == NULL)
    {
        printf("Open dictionary file: %s failed.\n", pFileName); 
        delete pFileName; 
        return E_FAIL; 
    }

    if(feof(fp))
    {
        printf("Is is a null file!\n"); 
        fclose(fp); 
        delete pFileName; 
        return E_FAIL; 
    }

    char LineBuffer[128]; 
    if(fgets(LineBuffer, 128, fp) == NULL)
    {
        printf("Read TotalNumber failed!\n"); 
        fclose(fp);
        delete pFileName; 
        return E_FAIL; 
    }

    int nTotalNumber = 0; 
    sscanf(LineBuffer, "%d", &nTotalNumber); 
    if((nTotalNumber < 1) || (nTotalNumber > 5000))
    {
        printf("The Number of words is invalid!\n"); 
        fclose(fp); 
        delete pFileName; 
        return E_FAIL; 
    }

    Initialize(); 
    m_nStructNumber = nTotalNumber + 100; 
    m_pData = new DictWord[m_nStructNumber]; 
    m_nWordNumber = 0; 
    while(!feof(fp))
    {
        if(fgets(LineBuffer, MaxWordLength, fp) == NULL)
        {
            printf("Read the first string failed!\n"); 
            break; 
        }

        sscanf(LineBuffer, "%s", m_pData[m_nWordNumber].wordForLang1); 
        if(fgets(LineBuffer, MaxWordLength, fp) == NULL)
        {
            printf("Read the second string failed!\n"); 
            break; 
        }

        sscanf(LineBuffer, "%s", m_pData[m_nWordNumber].wordForLang2); 
        m_nWordNumber ++; 
        if(m_nWordNumber == nTotalNumber)
            break; 
        if(m_nWordNumber > m_nStructNumber - 1)
            break; 
    }

    fclose(fp); 
    delete pFileName; 
    return S_OK; 
}

HRESULT CDictionary::InsertWord(String lang1, String lang2)
{
    if(m_nWordNumber > m_nStructNumber - 1)
        return E_FAIL; 

    char* pWord1 = _com_util::ConvertBSTRToString(lang1); 
    char* pWord2 = _com_util::ConvertBSTRToString(lang2); 
    strcpy(m_pData[m_nWordNumber].wordForLang1, pWord1); 
    strcpy(m_pData[m_nWordNumber].wordForLang2, pWord2); 
    m_nWordNumber++; 
    delete pWord1; 
    delete pWord2; 
    return S_OK; 
}

HRESULT CDictionary::DeleteWord(String word)
{
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpper = strupr(pWord); 
    for(int i=0; i<m_nWordNumber; i++)
    {
        char* pTmp = strupr(m_pData[i].wordForLang1); 
        if(strcmp(pTmp, pWord) == 0)
        {
            for(int j=i+1; j<m_nWordNumber; j++)
            {
                strcpy(m_pData[j].wordForLang1, m_pData[j+1].wordForLang1); 
                strcpy(m_pData[j].wordForLang2, m_pData[j+1].wordForLang2); 
            }

            m_nWordNumber--; 
            break; 
        }
    }

    delete pWord; 
    return S_OK; 
}

HRESULT CDictionary::LookupWord(String word, String resultWord)
{
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpperWord = strupr(pWord); 
    for(int i=0; i < m_nWordNumber; i++)
    {
        char* tmpWord = strupr(m_pData[i].wordForLang1); 
        if(strcmp(tmpWord, pUpperWord) == 0)
        {
            wcscpy(resultWord, _com_util::ConvertStringToBSTR(m_pData[i].wordForLang2)); 
            delete pWord; 
            return S_OK; 
        }
    }

    *resultWord = NULL; 
    delete pWord; 
    return E_FAIL; 
}

HRESULT CDictionary::RestoreLibrary(String filename)
{
    char* pFilename = _com_util::ConvertBSTRToString(filename); 
    FILE* fp = fopen(pFilename, "wt"); 
    if(fp == NULL)
    {
        printf("Open dictionary file: %s failed.\n", pFilename); 
        delete pFilename; 
        return E_FAIL; 
    }

    char LineBuffer[128]; 
    sprintf(LineBuffer, "%d\n", m_nWordNumber); 
    if(fputs(LineBuffer, fp) == EOF)
    {
        printf("Write TotalNumber failed!\n"); 
        fclose(fp); 
        delete pFilename; 
        return E_FAIL; 
    }
    
    for(int i=0; i<m_nWordNumber; i++)
    {
        if(fputs(m_pData[i].wordForLang1, fp) == EOF)
        {
            printf("Write the first string failed!\n"); 
            fclose(fp); 
            delete pFilename; 
            return E_FAIL; 
        }

        fputs("\n", fp); 
        if(fputs(m_pData[i].wordForLang2, fp) == EOF)
        {
            printf("Write the second string failed!\n"); 
            fclose(fp); 
            delete pFilename; 
            return E_FAIL; 
        }
        fputs("\n", fp); 
    }

    fclose(fp); 
    delete pFilename; 
    return S_OK; 
}

HRESULT CDictionary::FreeLibrary()
{
    Initialize(); 
    return S_OK; 
}

HRESULT CDictionary::CheckWord(String word, String resultWord)
{
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpperWord = strupr(pWord); 
    char* pMinMaxWord, *pMaxMinWord; 
    int nMinIndex = -1, nMaxIndex = -1; 
    pMinMaxWord = pMaxMinWord = NULL; 
    for(int i=0; i<m_nWordNumber; i++)
    {
        char* tmpWord = strupr(m_pData[i].wordForLang1); 
        if(strcmp(tmpWord, pWord) == 0)
        {
            delete pWord; 
            return S_OK; 
        }
        else if(strcmp(tmpWord, pWord) < 0)
        {
            if((pMinMaxWord == NULL) || (strcmp(tmpWord, pMinMaxWord) > 0))
            {
                pMinMaxWord = tmpWord; 
                nMinIndex = i; 
            }
        }
        else 
        {
            if((pMaxMinWord == NULL) || (strcmp(tmpWord, pMaxMinWord) < 0))
            {
                pMaxMinWord = tmpWord; 
                nMaxIndex = i; 
            }
        }
    }

    if(nMinIndex != -1)
        wcscpy(resultWord, _com_util::ConvertStringToBSTR(m_pData[nMinIndex].wordForLang1)); 
    else if(nMaxIndex != -1)
        wcscpy(resultWord, _com_util::ConvertStringToBSTR(m_pData[nMaxIndex].wordForLang1)); 

    delete pWord; 
    return E_FAIL; 
}