
#include "stdafx.h" 
#include "Dictionary.h" 

CDictionary::CDictionary()
{
    m_nRef = 0; 
}

CDictionary::~CDictionary()
{
}

ULONG CDictionary::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CDictionary::Release()
{
    m_nRef--; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)m_nRef; 
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

BOOL CDictionary::Initialize()
{
    return TRUE; 
}

BOOL CDictionary::LoadLibrary(String filename)
{
    char* pFileName = _com_util::ConvertBSTRToString(filename); 
    FILE* fp = fopen(pFileName, "rt"); 
    if(fp == NULL)
    {
        printf("Open dictionary file: %s failed.\n", pFileName); 
        delete pFileName; 
        return FALSE; 
    }

    if(feof(fp))
    {
        printf("Is is a null file!\n"); 
        fclose(fp); 
        delete pFileName; 
        return FALSE; 
    }

    char LineBuffer[128]; 
    if(fgets(LineBuffer, 128, fp) == NULL)
    {
        printf("Read TotalNumber failed!\n"); 
        fclose(fp);
        delete pFileName; 
        return FALSE; 
    }

    int nTotalNumber = 0; 
    sscanf(LineBuffer, "%d", &nTotalNumber); 
    if((nTotalNumber < 1) || (nTotalNumber > 5000))
    {
        printf("The Number of words is invalid!\n"); 
        fclose(fp); 
        delete pFileName; 
        return FALSE; 
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
    return TRUE; 
}

BOOL CDictionary::InsertWord(String lang1, String lang2)
{
    if(m_nWordNumber > m_nStructNumber - 1)
        return FALSE; 

    char* pWord1 = _com_util::ConvertBSTRToString(lang1); 
    char* pWord2 = _com_util::ConvertBSTRToString(lang2); 
    strcpy(m_pData[m_nWordNumber].wordForLang1, pWord1); 
    strcpy(m_pData[m_nWordNumber].wordForLang2, pWord2); 
    m_nWordNumber++; 
    delete pWord1; 
    delete pWord2; 
    return TRUE; 
}

void CDictionary::DeleteWord(String word)
{
}

BOOL CDictionary::LookupWord(String word, String* resultWord)
{
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpperWord = strupr(pWord); 
    for(int i=0; i < m_nWordNumber; i++)
    {
        char* tmpWord = strupr(m_pData[i].wordForLang1); 
        if(strcmp(tmpWord, pUpperWord) == 0)
        {
            *resultWord = _com_util::ConvertStringToBSTR(m_pData[i].wordForLang2); 
            delete pWord; 
            return TRUE; 
        }
    }

    *resultWord = NULL; 
    delete pWord; 
    return FALSE; 
}

BOOL CDictionary::RestoreLibrary(String filename)
{
    return TRUE; 
}

void CDictionary::FreeLibrary()
{
}

BOOL CDictionary::CheckWord(String word, String* resultWord)
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
            return TRUE; 
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

    *resultWord = NULL; 
    if(nMinIndex != -1)
        *resultWord = _com_util::ConvertStringToBSTR(m_pData[nMinIndex].wordForLang1); 
    else if(nMaxIndex != -1)
        *resultWord = _com_util::ConvertStringToBSTR(m_pData[nMaxIndex].wordForLang1); 

    delete pWord; 
    return FALSE; 
}