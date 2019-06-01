
#include "stdafx.h" 
#include "ComponentB.h" 
#include <stdio.h> 

ULONG g_ANumber = 0; 
ULONG g_LockNumber = 0; 

CB::CB()
{
    m_nRef = 0; 
    g_ANumber ++; 
    m_pSomeInterface = NULL; 
}

CB::~CB()
{
    g_ANumber--; 
    if(m_pSomeInterface != NULL)
        m_pSomeInterface->Release(); 
}

ULONG CB::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CB::Release()
{
    m_nRef--; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)m_nRef; 
}

HRESULT CB::QueryInterface(const IID& iid, void** ppv)
{
    if(iid == IID_IUnknown)
    {
        *ppv = (ISomeInterface*)this; 
        ((ISomeInterface*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_ISomeInterface)
    {
        *ppv = (ISomeInterface*)this; 
        ((ISomeInterface*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IOtherInterface)
    {
        *ppv = (IOtherInterface*)this; 
        ((IOtherInterface*)(*ppv))->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    return S_OK; 
}

HRESULT CB::Init()
{
    HRESULT result = ::CoCreateInstance(CLSID_ComponentA, NULL, 
        CLSCTX_INPROC_SERVER, IID_ISomeInterface, (void**)&m_pSomeInterface); 
    return result; 
}

void CB::SomeFunction()
{
    printf("CB::SomeFunction called\n"); 
    if(m_pSomeInterface)
        m_pSomeInterface->SomeFunction(); 
}

void CB::OtherFunction()
{
    printf("CB::OtherFunction called\n"); 
}