// DictComp.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "registry.h" 
#include "factory.h" 
#include "dictionary.h" 

ULONG g_LockNumber = 0; 
ULONG g_DictionaryNumber = 0; 
DWORD dwMainThreadID; 

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
    HRESULT hr = CoInitialize(NULL); 
    if(FAILED(hr))
        return 0; 

    int retVal = 0; 
    BOOL bExit = FALSE; 
    char szTokens[] = "-/"; 
    dwMainThreadID = ::GetCurrentThreadId(); 

    char* szToken = strtok(lpCmdLine, szTokens); 
    while(szToken != NULL)
    {
        if(_stricmp(szToken, "RegServer") == 0)
        {
            char szModule[1024]; 
            DWORD dwResult = ::GetModuleFileName((HMODULE)hInstance, szModule, 1024); 
            if(dwResult == 0)
                retVal = SELFREG_E_CLASS; 

            retVal = RegisterServer(CLSID_Dictionary, 
                FALSE, 
                szModule, 
                "Dictionary.Object", 
                "Dictionary Component", 
                NULL); 

            bExit = TRUE; 
        }
        else if(_stricmp(szToken, "UnregServer") == 0)
        {
            retVal = UnregisterServer(CLSID_Dictionary, 
                "Dictionary.Object", NULL); 
            bExit = TRUE; 
        }
        else if(_stricmp(szToken, "Embedding") == 0)
        {
            bExit = FALSE; 
            break; 
        }

        szToken = strtok(NULL, szTokens); 
    }

    if(!bExit)
    {
        CDictionaryFactory::RegisterFactory(); 
        MSG msg; 
        while(::GetMessage(&msg, 0, 0, 0))
            ::DispatchMessage(&msg); 
        CDictionaryFactory::UnregisterFactory(); 
    }

    CoUninitialize(); 
	return 0;
}



