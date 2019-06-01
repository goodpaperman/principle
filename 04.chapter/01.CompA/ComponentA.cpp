
#include "stdafx.h" 
#include "ComponentA.h" 

ULONG g_ANumber = 0; 
ULONG g_LockNumber = 0; 

CA::CA(IUnknown* pUnknownOuter)
{
    printf("enter CA::CA\n"); 
    m_nRef = 0; 
    m_pUnknownOuter = pUnknownOuter; 
    g_ANumber ++; 
    //printf("leave CA::CA\n"); 
}

CA::~CA()
{
    printf("enter CA::~CA\n"); 
    g_ANumber--; 
    //printf("leave CA::~CA\n"); 
}

ULONG CA::AddRef()
{
    printf("enter CA::AddRef\n"); 
    if(m_pUnknownOuter)
        return m_pUnknownOuter->AddRef(); 
    else 
        return NondelegatingAddRef(); 
}

ULONG CA::Release()
{
    printf("enter CA::Release\n"); 
    if(m_pUnknownOuter)
        return m_pUnknownOuter->Release(); 
    else 
        return NondelegatingRelease(); 
}

HRESULT CA::QueryInterface(const IID& iid, void** ppv)
{
    printf("enter CA::QueryInterface\n"); 
    if(m_pUnknownOuter)
        return m_pUnknownOuter->QueryInterface(iid, ppv); 
    else 
        return NondelegatingQueryInterface(iid, ppv); 
}

void CA::SomeFunction()
{
    printf("CA::SomeFunction called\n"); 
}

ULONG CA::NondelegatingAddRef()
{
    m_nRef ++; 
    printf("enter CA::NondelegatingAddRef, m_nRef = %d\n", m_nRef); 
    //printf("leave CA::NondelegatingAddRef, m_nRef = %d\n", m_nRef); 
    return (ULONG)m_nRef; 
}

ULONG CA::NondelegatingRelease()
{    
    m_nRef--; 
    int ret = m_nRef; 
    printf("enter CA::NondelegatingRelease, m_nRef = %d\n", m_nRef); 
    if(m_nRef == 0)
        delete this; 

    //printf("leave CA::NondelegatingRelease\n"); 
    return (ULONG)ret; 
}

HRESULT CA::NondelegatingQueryInterface(const IID& iid, void** ppv)
{
    printf("enter CA::NondelegatingQueryInterface\n"); 
    if(iid == IID_IUnknown)
    {
        *ppv = (INondelegatingUnknown*)this; 
        ((INondelegatingUnknown*)(*ppv))->NondelegatingAddRef(); 
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

    //printf("leave CA::NondelegatingQueryInterface\n"); 
    return S_OK; 
}