
#include "stdafx.h" 
#include "ComponentA.h" 
#include <stdio.h> 

ULONG g_ANumber = 0; 
ULONG g_LockNumber = 0; 

CA::CA()
{
    m_nRef = 0; 
    g_ANumber ++; 
}

CA::~CA()
{
    g_ANumber--; 
}

ULONG CA::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CA::Release()
{
    m_nRef--; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)m_nRef; 
}

HRESULT CA::QueryInterface(const IID& iid, void** ppv)
{
    if(iid == IID_IUnknown)
    {
        *ppv = (IUnknown*)this; 
        ((IUnknown*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_ISomeInterface)
    {
        *ppv = (ISomeInterface*)this; 
        ((ISomeInterface*)(*ppv))->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    return S_OK; 
}

void CA::SomeFunction()
{
    printf("CA::SomeFunction called\n"); 
}