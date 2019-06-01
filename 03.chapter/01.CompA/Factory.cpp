
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

    return S_OK; 
}

ULONG CAFactory::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CAFactory::Release()
{
    m_nRef --; 
    if(m_nRef == 0)
    {
        delete this; 
    }

    return (ULONG)m_nRef; 
}

HRESULT CAFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    CA* pObj; 
    HRESULT hr = E_OUTOFMEMORY; 
    *ppv = NULL; 
    if(pUnknownOuter != NULL)
        return CLASS_E_NOAGGREGATION; 

    // g_ANumber ++ in Constructor
    pObj = new CA(); 
    if(pObj == NULL)
        return hr; 

    hr = pObj->QueryInterface(iid, ppv); 
    if(hr != S_OK)
    {
        // g_ANumber-- in Destructor
        delete pObj; 
    }

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