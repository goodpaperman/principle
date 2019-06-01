// DictCtrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_MEAN_AND_LEAN 
#include <windows.h> 
#include <stdio.h> 
#include <comutil.h> 
#include "..\\includeex\\IDictionary.h" 
#include "..\\includeex\\ISpellCheck.h" 

HMODULE hModule = NULL; 
int main(int argc, char* argv[])
{
    hModule = NULL; 
    IUnknown* pUnknown; 
    IDictionary* pDictionary; 
    ISpellCheck* pSpellCheck = NULL; 
    String stringResult; 
    BOOL bResult; 
    HRESULT hResult; 

    if(CoInitialize(NULL) != S_OK)
    {
        printf("Initialize COM library failed!\n"); 
        return -1; 
    }

    GUID dictionaryCLSID; 
    hResult = ::CLSIDFromProgID(L"Dictionary.Object", &dictionaryCLSID); 
    if(hResult != S_OK)
    {
        printf("Can't find the dictionary CLSID!\n"); 
        return -2; 
    }

    hResult = CoCreateInstance(dictionaryCLSID, NULL, 
        CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pUnknown); 
    if(hResult != S_OK)
    {
        printf("Create object failed!\n"); 
        return -2; 
    }

    hResult = pUnknown->QueryInterface(IID_IDictionary, (void**)&pDictionary); 
    if(hResult != S_OK)
    {
        pUnknown->Release(); 
        printf("QueryInterface IDictionary failed!\n"); 
        return -2; 
    }

    bResult = pDictionary->LoadLibrary(L"..\\bin\\animal.dict"); 
    if(bResult)
    {
        bResult = pDictionary->LookupWord(L"tiger", &stringResult); 
        if(bResult)
        {
            char* pTiger = _com_util::ConvertBSTRToString(stringResult); 
            printf("find the word \"tiger\" -- %s\n", pTiger); 
            delete pTiger; 
        }

        pDictionary->InsertWord(L"elephant", L"Ïó"); 
        bResult = pDictionary->LookupWord(L"elephant", &stringResult); 
        if(bResult)
        {
            pDictionary->RestoreLibrary(L"animal1.dict"); 
        }
    }
    else 
    {
        printf("Load Library \"animal.dict\"\n"); 
        return -2; 
    }
    
    hResult = pDictionary->QueryInterface(IID_ISpellCheck, (void**)&pSpellCheck); 
    pDictionary->Release(); 
    if(hResult != S_OK)
    {
        pUnknown->Release(); 
        printf("QueryInterface ISpellCheck failed!\n"); 
        return -2; 
    }
    
    bResult = pSpellCheck->CheckWord(L"lion", &stringResult); 
    if(bResult)
    {
        printf("Word \"lion\" spelling right.\n");
    }
    else 
    {
        char* pLion = _com_util::ConvertBSTRToString(stringResult); 
        printf("Word \"lion\" spelling is wrong. Maybe it is %s.\n", pLion); 
        delete pLion; 
    }
    
    bResult = pSpellCheck->CheckWord(L"dot", &stringResult); 
    if(bResult)
        printf("Word \"dot\" spelling right.\n"); 
    else 
    {
        char* pDot = _com_util::ConvertBSTRToString(stringResult); 
        printf("Word \"dot\" spelling is wrong. Maybe it is %s.\n", pDot); 
        delete pDot; 
    }
    
    pSpellCheck->Release(); 
    if(pUnknown->Release() == 0)
        printf("The reference count of dictionary object is 0"); 

    CoUninitialize(); 
	return 0;
}


