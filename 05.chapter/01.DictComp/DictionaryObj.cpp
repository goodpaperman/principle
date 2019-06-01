// DictionaryObj.cpp : implementation file
//

#include "stdafx.h"
#include "DictComp.h"
#include "DictionaryObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDictionaryObj

IMPLEMENT_DYNCREATE(CDictionaryObj, CCmdTarget)
// {C2702DF3-ECF4-47e9-A25F-54A386AD929E}
IMPLEMENT_OLECREATE(CDictionaryObj, "Dictionary.Object", 
0xc2702df3, 0xecf4, 0x47e9, 0xa2, 0x5f, 0x54, 0xa3, 0x86, 0xad, 0x92, 0x9e);

CDictionaryObj::CDictionaryObj()
{
    m_pData = NULL; 
    m_nWordNumber = 0; 
    m_nStructNumber = 0; 
}

CDictionaryObj::~CDictionaryObj()
{
    if(m_pData)
        delete[] m_pData; 
}


BEGIN_MESSAGE_MAP(CDictionaryObj, CCmdTarget)
	//{{AFX_MSG_MAP(CDictionaryObj)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_INTERFACE_MAP(CDictionaryObj, CCmdTarget)
    INTERFACE_PART(CDictionaryObj, IID_IDictionary, Dictionary) 
    INTERFACE_PART(CDictionaryObj, IID_ISpellCheck, SpellCheck) 
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDictionaryObj message handlers

STDMETHODIMP_(ULONG) CDictionaryObj::XDictionary::AddRef()
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary)
    return pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CDictionaryObj::XDictionary::Release()
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary)
    return pThis->ExternalRelease(); 
}

STDMETHODIMP CDictionaryObj::XDictionary::QueryInterface(REFIID iid, void** ppvObj)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary)
    return pThis->ExternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP_(ULONG) CDictionaryObj::XSpellCheck::AddRef()
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, SpellCheck)
    return pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CDictionaryObj::XSpellCheck::Release()
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, SpellCheck)
    return pThis->ExternalRelease(); 
}

STDMETHODIMP CDictionaryObj::XSpellCheck::QueryInterface(REFIID iid, void** ppvObj)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, SpellCheck)
    return pThis->ExternalQueryInterface(&iid, ppvObj); 
}



STDMETHODIMP CDictionaryObj::XDictionary::Initialize()
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
    pThis->m_nWordNumber = 0; 
    pThis->m_nStructNumber = 0; 
    if(pThis->m_pData)
        delete[] pThis->m_pData; 

    pThis->m_pData = NULL; 
    return S_OK; 
}

STDMETHODIMP CDictionaryObj::XDictionary::LoadLibrary(LPOLESTR filename)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
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
    pThis->m_nStructNumber = nTotalNumber + 100; 
    pThis->m_pData = new DictWord[pThis->m_nStructNumber]; 
    pThis->m_nWordNumber = 0; 
    while(!feof(fp))
    {
        if(fgets(LineBuffer, MaxWordLength, fp) == NULL)
        {
            printf("Read the first string failed!\n"); 
            break; 
        }

        sscanf(LineBuffer, "%s", pThis->m_pData[pThis->m_nWordNumber].wordForLang1); 
        if(fgets(LineBuffer, MaxWordLength, fp) == NULL)
        {
            printf("Read the second string failed!\n"); 
            break; 
        }

        sscanf(LineBuffer, "%s", pThis->m_pData[pThis->m_nWordNumber].wordForLang2); 
        pThis->m_nWordNumber ++; 
        if(pThis->m_nWordNumber == nTotalNumber)
            break; 
        if(pThis->m_nWordNumber > pThis->m_nStructNumber - 1)
            break; 
    }

    fclose(fp); 
    delete pFileName; 
    return S_OK; 
}

STDMETHODIMP CDictionaryObj::XDictionary::InsertWord(LPOLESTR lang1, LPOLESTR lang2)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
    if(pThis->m_nWordNumber > pThis->m_nStructNumber - 1)
        return E_FAIL; 

    char* pWord1 = _com_util::ConvertBSTRToString(lang1); 
    char* pWord2 = _com_util::ConvertBSTRToString(lang2); 
    strcpy(pThis->m_pData[pThis->m_nWordNumber].wordForLang1, pWord1); 
    strcpy(pThis->m_pData[pThis->m_nWordNumber].wordForLang2, pWord2); 
    pThis->m_nWordNumber++; 
    delete pWord1; 
    delete pWord2; 
    return S_OK; 
}

STDMETHODIMP CDictionaryObj::XDictionary::DeleteWord(LPOLESTR word)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpper = strupr(pWord); 
    for(int i=0; i<pThis->m_nWordNumber; i++)
    {
        char* pTmp = strupr(pThis->m_pData[i].wordForLang1); 
        if(strcmp(pTmp, pWord) == 0)
        {
            for(int j=i+1; j<pThis->m_nWordNumber; j++)
            {
                strcpy(pThis->m_pData[j].wordForLang1, pThis->m_pData[j+1].wordForLang1); 
                strcpy(pThis->m_pData[j].wordForLang2, pThis->m_pData[j+1].wordForLang2); 
            }

            pThis->m_nWordNumber--; 
            break; 
        }
    }

    delete pWord; 
    return S_OK; 
}

STDMETHODIMP CDictionaryObj::XDictionary::LookupWord(LPOLESTR word, LPOLESTR* resultWord)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpperWord = strupr(pWord); 
    for(int i=0; i < pThis->m_nWordNumber; i++)
    {
        char* tmpWord = strupr(pThis->m_pData[i].wordForLang1); 
        if(strcmp(tmpWord, pUpperWord) == 0)
        {
            *resultWord = _com_util::ConvertStringToBSTR(pThis->m_pData[i].wordForLang2); 
            delete pWord; 
            return S_OK; 
        }
    }

    *resultWord = NULL; 
    delete pWord; 
    return E_FAIL; 
}

STDMETHODIMP CDictionaryObj::XDictionary::RestoreLibrary(LPOLESTR filename)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, Dictionary) 
    char* pFilename = _com_util::ConvertBSTRToString(filename); 
    FILE* fp = fopen(pFilename, "wt"); 
    if(fp == NULL)
    {
        printf("Open dictionary file: %s failed.\n", pFilename); 
        delete pFilename; 
        return E_FAIL; 
    }

    char LineBuffer[128]; 
    sprintf(LineBuffer, "%d\n", pThis->m_nWordNumber); 
    if(fputs(LineBuffer, fp) == EOF)
    {
        printf("Write TotalNumber failed!\n"); 
        fclose(fp); 
        delete pFilename; 
        return E_FAIL; 
    }
    
    for(int i=0; i<pThis->m_nWordNumber; i++)
    {
        if(fputs(pThis->m_pData[i].wordForLang1, fp) == EOF)
        {
            printf("Write the first string failed!\n"); 
            fclose(fp); 
            delete pFilename; 
            return E_FAIL; 
        }

        fputs("\n", fp); 
        if(fputs(pThis->m_pData[i].wordForLang2, fp) == EOF)
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

STDMETHODIMP CDictionaryObj::XDictionary::FreeLibrary()
{
    Initialize(); 
    return S_OK; 
}

STDMETHODIMP CDictionaryObj::XSpellCheck::CheckWord(LPOLESTR word, LPOLESTR* resultWord)
{
    METHOD_PROLOGUE_EX_(CDictionaryObj, SpellCheck) 
    char* pWord = _com_util::ConvertBSTRToString(word); 
    char* pUpperWord = strupr(pWord); 
    char* pMinMaxWord, *pMaxMinWord; 
    int nMinIndex = -1, nMaxIndex = -1; 
    pMinMaxWord = pMaxMinWord = NULL; 
    for(int i=0; i<pThis->m_nWordNumber; i++)
    {
        char* tmpWord = strupr(pThis->m_pData[i].wordForLang1); 
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
        *resultWord = _com_util::ConvertStringToBSTR(pThis->m_pData[nMinIndex].wordForLang1); 
    else if(nMaxIndex != -1)
        *resultWord = _com_util::ConvertStringToBSTR(pThis->m_pData[nMaxIndex].wordForLang1); 

    delete pWord; 
    return E_FAIL; 
}