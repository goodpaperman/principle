// DictCtrl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WIN32_MEAN_AND_LEAN 
#include <windows.h> 
#include <stdio.h> 
#include <comutil.h> 
#include "..\\include\\IDictionary.h" 
#include "..\\include\\ISpellCheck.h" 

HMODULE hModule = NULL; 

char* __stdcall _com_util::ConvertBSTRToString(BSTR pSrc)// throw(_com_error)
{
    // we want to convert an Wide string in lpszA
    int nLen = WideCharToMultiByte(CP_ACP, 0, pSrc, -1, NULL, 0, NULL, NULL);
    LPSTR lpszA = new CHAR[nLen];
    WideCharToMultiByte(CP_ACP, 0, pSrc, -1, lpszA, nLen, NULL, NULL);
    return lpszA; 
}


BSTR __stdcall _com_util::ConvertStringToBSTR(const char* pSrc)// throw(_com_error)
{
    // we want to convert an MBCS string in lpszA
    int nLen = MultiByteToWideChar(CP_ACP, 0,pSrc, -1, NULL, NULL);
    LPWSTR lpszW = new WCHAR[nLen];
    MultiByteToWideChar(CP_ACP, 0, 
        pSrc, -1, lpszW, nLen);

    return lpszW; 
}



BOOL CreateObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    hModule = LoadLibrary("DictComp.dll"); 
    if(hModule == NULL)
        return FALSE; 

    typedef BOOL (* MyFunctionType)(const CLSID& clsid, const IID& iid, void** ppv); 
    MyFunctionType fnCreateObject = (MyFunctionType)GetProcAddress(hModule, "CreateObject"); 
    if(fnCreateObject == NULL)
    {
        FreeLibrary(hModule); 
        return FALSE; 
    }

    return fnCreateObject(clsid, iid, ppv); 
}

int main(int argc, char* argv[])
{
    hModule = NULL; 
    IMyUnknown* pMyUnknown; 
    IDictionary* pDictionary; 
    ISpellCheck* pSpellCheck = NULL; 
    String stringResult; 
    BOOL bResult; 
    HRESULT hResult; 

    bResult = CreateObject(CLSID_Dictionary, IID_IUnknown, (void**)&pMyUnknown); 
    if(bResult == FALSE)
    {
        printf("Create object failed!\n"); 
        return -1; 
    }

    hResult = pMyUnknown->QueryInterface(IID_IDictionary, (void**)&pDictionary); 
    if(hResult != S_OK)
    {
        pMyUnknown->Release(); 
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
        pMyUnknown->Release(); 
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
    if(pMyUnknown->Release() == 0)
        FreeLibrary(hModule); 

	return 0;
}


