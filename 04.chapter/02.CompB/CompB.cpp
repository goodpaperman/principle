// CompA.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "ComponentB.h" 
#include "Factory.h" 
#include "Registry.h" 

HMODULE g_hModule; 
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    if(ul_reason_for_call == DLL_PROCESS_ATTACH)
        g_hModule = (HMODULE)hModule; 
    return TRUE;
}

extern "C" HRESULT _stdcall DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
    printf("enter CompB::DllGetClassObject\n"); 
    if(clsid == CLSID_ComponentB)
    {
        CBFactory* pFactory = new CBFactory; 
        if(pFactory == NULL) 
            return E_OUTOFMEMORY; 

        HRESULT result = pFactory->QueryInterface(iid, ppv); 
        return result; 
    }
    else 
        return CLASS_E_CLASSNOTAVAILABLE; 
}

extern "C" HRESULT _stdcall DllCanUnloadNow()
{
    printf("enter CompB::DllCanUnloadNow\n"); 
    if((g_ANumber == 0) && (g_LockNumber == 0))
        return S_OK; 
    else 
        return S_FALSE; 
}

extern "C" HRESULT _stdcall DllRegisterServer()
{
    char szModule[1024]; 
    DWORD dwResult = ::GetModuleFileName((HMODULE)g_hModule, szModule, 1024); 
    if(dwResult == 0)
        return SELFREG_E_CLASS; 

    return RegisterServer(CLSID_ComponentB, 
        szModule, 
        "B.Object", 
        "B Component", 
        NULL); 
}

extern "C" HRESULT _stdcall DllUnregisterServer()
{
    return UnregisterServer(CLSID_ComponentB, 
        "B.Object", 
        NULL); 
}