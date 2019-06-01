// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define WIN32_MEAN_AND_LEAN 
#include <windows.h> 
#include <stdio.h> 
#include "..\\include\\ISomeInterface.h" 
#include "..\\include\\IOtherInterface.h" 

int main(int argc, char* argv[])
{
    IUnknown* pUnknown; 
    ISomeInterface* pSome = NULL; 
    IOtherInterface* pOther = NULL; 
    HRESULT hResult; 

    if(CoInitialize(NULL) != S_OK)
    {
        printf("Initialize COM library failed!\n"); 
        return -1; 
    }

    GUID bCLSID; 
    hResult = ::CLSIDFromProgID(L"B.Object", &bCLSID); 
    if(hResult != S_OK)
    {
        printf("Can't find the ComponentB CLSID!\n"); 
        return -2; 
    }

    printf("START:\n"); 
    hResult = CoCreateInstance(bCLSID, NULL, 
        CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pUnknown); 
    if(hResult != S_OK)
    {
        printf("Create object failed!\n"); 
        return -2; 
    }

    printf("\ntry to query ISomeInterface\n"); 
    hResult = pUnknown->QueryInterface(IID_ISomeInterface, (void**)&pSome); 
    if(hResult != S_OK)
    {
        pUnknown->Release(); 
        printf("QueryInterface ISomeInterface failed!\n"); 
        return -2; 
    }

    pSome->SomeFunction();     
    printf("\ntry to query IOtherInterface\n"); 
    hResult = pSome->QueryInterface(IID_IOtherInterface, (void**)&pOther); 
    pSome->Release(); 
    if(hResult != S_OK)
    {
        pUnknown->Release(); 
        printf("QueryInterface IOtherInterface failed!\n"); 
        return -2; 
    }
    
    pOther->OtherFunction(); 
    pOther->Release(); 
    int n = pUnknown->Release(); 
    printf("The reference count of component B object is %d\n", n); 
    CoUninitialize(); 
	return 0;
}
