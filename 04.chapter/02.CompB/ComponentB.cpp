
#include "stdafx.h" 
#include "ComponentB.h" 

ULONG g_ANumber = 0; 
ULONG g_LockNumber = 0; 

CB::CB()
{
    printf("enter CB::CB\n"); 
    m_nRef = 0; 
    g_ANumber ++; 
    m_pUnknownInner = NULL; 
    m_pSomeInterface = NULL; 
    //printf("leave CB::CB\n"); 
}

CB::~CB()
{
    printf("enter CB::~CB\n"); 
    g_ANumber--; 
    if(m_pUnknownInner != NULL)
        m_pUnknownInner->Release(); 
    //printf("leave CB::~CB\n"); 
}

ULONG CB::AddRef()
{
    m_nRef ++; 
    printf("enter CB::AddRef, m_nRef = %d\n", m_nRef); 
    //printf("leave CB::AddRef, m_nRef = %d\n", m_nRef); 
    return (ULONG)m_nRef; 
}

ULONG CB::Release()
{
    m_nRef--; 
    int ret = m_nRef; 
    printf("enter CB::Release, m_nRef = %d\n", m_nRef); 
    if(m_nRef == 1)
    {
        if(m_pSomeInterface)
            ret = m_pSomeInterface->Release(); 
    }
    else if(m_nRef == 0)
    {
        delete this; 
    }

    //printf("leave CB::Release\n"); 
    return (ULONG)ret; 
}

HRESULT CB::QueryInterface(const IID& iid, void** ppv)
{
    printf("enter CB::QueryInterface\n"); 
    if(iid == IID_IUnknown)
    {
        *ppv = (IUnknown*)this; 
        ((IUnknown*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IOtherInterface)
    {
        *ppv = (IOtherInterface*)this; 
        ((IOtherInterface*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_ISomeInterface)
    {
        *ppv = m_pSomeInterface; 
        m_pSomeInterface->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    //printf("leave CB::QueryInterface\n"); 
    return S_OK; 
}

HRESULT CB::Init()
{
    printf("enter CB::Init\n"); 
    HRESULT result = ::CoCreateInstance(CLSID_ComponentA, (IUnknown*)this, 
        CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&m_pUnknownInner); 
    if(FAILED(result))
    {
        return E_FAIL; 
    }

    result = m_pUnknownInner->QueryInterface(IID_ISomeInterface, (void**)&m_pSomeInterface); 
    if(FAILED(result))
    {
        m_pUnknownInner->Release(); 
        m_pUnknownInner = NULL; 
        return E_FAIL; 
    }

    // if success, m_nRef = 2 now.
    printf("CB::m_nRef = %d after Init\n", m_nRef);
    //printf("leave CB::Init\n"); 
    return result; 
}

void CB::OtherFunction()
{
    printf("CB::OtherFunction called\n"); 
}