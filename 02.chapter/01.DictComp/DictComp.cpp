// DictComp.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Dictionary.h" 

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

extern "C" BOOL _declspec(dllexport) CreateObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    if(clsid == CLSID_Dictionary)
    {
        CDictionary* pObject = new CDictionary; 
        HRESULT result = pObject->QueryInterface(iid, ppv); 
        if(result != S_OK)
        {
            delete pObject; 
            return FALSE; 
        }
        else 
            return TRUE; 
    }

    return FALSE; 
}

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

