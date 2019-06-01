
#include "stdafx.h" 
#include "factory.h" 
#include "ComponentA.h" 

CAFactory::CAFactory()
{
    m_nRef = 0; 
}

CAFactory::~CAFactory()
{
}

HRESULT CAFactory::QueryInterface(const IID& iid, void** ppv)
{
    printf("enter CAFactory::QueryInterface\n"); 
    if(iid == IID_IUnknown)
    {
        *ppv = (IUnknown*)this; 
        ((IUnknown*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IClassFactory)
    {
        *ppv = (IClassFactory*)this; 
        ((IClassFactory*)(*ppv))->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    //printf("leave CAFactory::QueryInterface\n"); 
    return S_OK; 
}

ULONG CAFactory::AddRef()
{
    m_nRef ++; 
    printf("enter CAFactory::AddRef, m_nRef = %d\n", m_nRef); 
    //printf("leave CAFactory::AddRef, m_nRef = %d\n", m_nRef); 
    return (ULONG)m_nRef; 
}

ULONG CAFactory::Release()
{
    m_nRef --; 
    int ret = m_nRef; 
    printf("enter CAFactory::Release, m_nRef = %d\n", m_nRef); 
    if(m_nRef == 0)
    {
        delete this; 
    }

    //printf("leave CAFactory::Release\n"); 
    return (ULONG)ret; 
}

HRESULT CAFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    printf("enter CAFactory::CreateInstance\n"); 
    CA* pObj; 
    HRESULT hr = E_OUTOFMEMORY; 
    *ppv = NULL; 
    if(pUnknownOuter != NULL && iid != IID_IUnknown)
        return CLASS_E_NOAGGREGATION; 

    // g_ANumber ++ in Constructor
    pObj = new CA(pUnknownOuter); 
    if(pObj == NULL)
        return hr; 

    hr = pObj->NondelegatingQueryInterface(iid, ppv); 
    if(hr != S_OK)
    {
        // g_ANumber-- in Destructor
        delete pObj; 
    }

    //printf("leave CAFactory::CreateInstance\n"); 
    return hr; 
}

HRESULT CAFactory::LockServer(BOOL bLock)
{
    if(bLock)
        g_LockNumber++; 
    else 
        g_LockNumber--; 

    return NOERROR; 
}