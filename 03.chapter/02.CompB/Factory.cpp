
#include "stdafx.h" 
#include "factory.h" 
#include "ComponentB.h" 

CBFactory::CBFactory()
{
    m_nRef = 0; 
}

CBFactory::~CBFactory()
{
}

HRESULT CBFactory::QueryInterface(const IID& iid, void** ppv)
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

ULONG CBFactory::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CBFactory::Release()
{
    m_nRef --; 
    if(m_nRef == 0)
    {
        delete this; 
    }

    return (ULONG)m_nRef; 
}

HRESULT CBFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    CB* pObj; 
    HRESULT hr = E_OUTOFMEMORY; 
    *ppv = NULL; 
    if(pUnknownOuter != NULL)
        return CLASS_E_NOAGGREGATION; 

    // g_ANumber ++ in Constructor
    pObj = new CB(); 
    if(pObj == NULL)
        return hr; 

    hr = pObj->Init(); 
    if(FAILED(hr))
    {
        delete pObj; 
        return  hr; 
    }

    hr = pObj->QueryInterface(iid, ppv); 
    if(hr != S_OK)
    {
        // g_ANumber-- in Destructor
        delete pObj; 
    }

    return hr; 
}

HRESULT CBFactory::LockServer(BOOL bLock)
{
    if(bLock)
        g_LockNumber++; 
    else 
        g_LockNumber--; 

    return NOERROR; 
}