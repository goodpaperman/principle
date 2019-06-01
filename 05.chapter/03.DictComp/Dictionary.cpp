// Dictionary.cpp : Implementation of CDictionary
#include "stdafx.h"
#include "DictComp.h"
#include "Dictionary.h"

/////////////////////////////////////////////////////////////////////////////
// CDictionary


STDMETHODIMP CDictionary::Initialize()
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CDictionary::LoadLibrary(LPOLESTR filename)
{
	// TODO: Add your implementation code here
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

STDMETHODIMP CDictionary::InsertWord(LPOLESTR lang1, LPOLESTR lang2)
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

STDMETHODIMP CDictionary::DeleteWord(LPOLESTR word)
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

STDMETHODIMP CDictionary::LookupWord(LPOLESTR word, LPOLESTR* resultWord)
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
            return S_OK; 
        }
    }

    *resultWord = NULL; 
    delete pWord; 
    return E_FAIL; 
}

STDMETHODIMP CDictionary::RestoreLibrary(LPOLESTR filename)
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

STDMETHODIMP CDictionary::FreeLibrary()
{
    Initialize(); 
    return S_OK; 
}

STDMETHODIMP CDictionary::CheckWord(LPOLESTR word, LPOLESTR* resultWord)
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
        *resultWord = _com_util::ConvertStringToBSTR(m_pData[nMinIndex].wordForLang1); 
    else if(nMaxIndex != -1)
        *resultWord = _com_util::ConvertStringToBSTR(m_pData[nMaxIndex].wordForLang1); 

    delete pWord; 
    return E_FAIL; 
}
