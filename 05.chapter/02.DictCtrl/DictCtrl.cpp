// DictCtrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_MEAN_AND_LEAN 
#include <windows.h> 
#include <stdio.h> 
#include <comutil.h> 
#include "..\\include\\IDictionary.h" 
#include "..\\include\\ISpellCheck.h" 

int main(int argc, char* argv[])
{
    IUnknown* pUnknown; 
    IDictionary* pDictionary; 
    ISpellCheck* pSpellCheck = NULL; 
    String stringResult = NULL; 
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
        CoUninitialize(); 
        return -2; 
    }

    hResult = CoCreateInstance(dictionaryCLSID, NULL, 
        CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pUnknown); 
    if(FAILED(hResult))
    {
        printf("Create object failed!\n"); 
        CoUninitialize(); 
        return -2; 
    }

    hResult = pUnknown->QueryInterface(IID_IDictionary, (void**)&pDictionary); 
    if(FAILED(hResult))
    {
        pUnknown->Release(); 
        printf("QueryInterface IDictionary failed!\n"); 
        CoUninitialize(); 
        return -3; 
    }

	char strDirectory[256];
	::GetCurrentDirectory(200, strDirectory);
	strcat(strDirectory, "\\animal.dict");
    String dictFile = _com_util::ConvertStringToBSTR(strDirectory); 
    hResult = pDictionary->LoadLibrary(dictFile); //L"animal.dict"); 
    //delete dictFile; 
    if(SUCCEEDED(hResult))
    {
        hResult = pDictionary->LookupWord(L"tiger", &stringResult); 
        if(SUCCEEDED(hResult))
        {
            char* pTiger = _com_util::ConvertBSTRToString(stringResult); 
            printf("find the word \"tiger\" -- %s\n", pTiger); 
            delete pTiger; 
        }

        pDictionary->InsertWord(L"elephant", L"Ïó"); 
        hResult = pDictionary->LookupWord(L"elephant", &stringResult); 
        if(SUCCEEDED(hResult))
        {
            pDictionary->RestoreLibrary(L"animal1.dict"); 
        }
    }
    else 
    {
        printf("Load Library \"animal.dict\"\n"); 
        pUnknown->Release(); 
        CoUninitialize(); 
        return -4; 
    }
    
    hResult = pDictionary->QueryInterface(IID_ISpellCheck, (void**)&pSpellCheck); 
    pDictionary->Release(); 
    if(FAILED(hResult))
    {
        pUnknown->Release(); 
        printf("QueryInterface ISpellCheck failed!\n"); 
        CoUninitialize(); 
        return -5; 
    }
    
    hResult = pSpellCheck->CheckWord(L"lion", &stringResult); 
    if(SUCCEEDED(hResult))
    {
        printf("Word \"lion\" spelling right.\n");
    }
    else 
    {
        char* pLion = _com_util::ConvertBSTRToString(stringResult); 
        printf("Word \"lion\" spelling is wrong. Maybe it is %s.\n", pLion); 
        delete pLion; 
    }
    
    hResult = pSpellCheck->CheckWord(L"dot", &stringResult); 
    if(SUCCEEDED(hResult))
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


