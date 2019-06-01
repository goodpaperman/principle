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
        printf("Can't find the ComponentA CLSID!\n"); 
        return -2; 
    }

    hResult = CoCreateInstance(bCLSID, NULL, 
        CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pUnknown); 
    if(hResult != S_OK)
    {
        printf("Create object failed!\n"); 
        return -2; 
    }

    hResult = pUnknown->QueryInterface(IID_ISomeInterface, (void**)&pSome); 
    if(hResult != S_OK)
    {
        pUnknown->Release(); 
        printf("QueryInterface ISomeInterface failed!\n"); 
        return -2; 
    }

    pSome->SomeFunction();     
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
    if(pUnknown->Release() == 0)
        printf("The reference count of dictionary object is 0"); 

    CoUninitialize(); 
	return 0;
}
