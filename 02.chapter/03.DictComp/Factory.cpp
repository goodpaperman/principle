
#include "stdafx.h" 
#include "factory.h" 
#include "Dictionary.h" 

CDictionaryFactory::CDictionaryFactory()
{
    m_nRef = 0; 
}

CDictionaryFactory::~CDictionaryFactory()
{
}

HRESULT CDictionaryFactory::QueryInterface(const IID& iid, void** ppv)
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

ULONG CDictionaryFactory::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CDictionaryFactory::Release()
{
    m_nRef --; 
    if(m_nRef == 0)
    {
        delete this; 
    }

    return (ULONG)m_nRef; 
}

HRESULT CDictionaryFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    CDictionary* pObj; 
    HRESULT hr = E_OUTOFMEMORY; 
    *ppv = NULL; 
    if(pUnknownOuter != NULL)
        return CLASS_E_NOAGGREGATION; 

    // g_DictionaryNumber ++ in Constructor
    pObj = new CDictionary(); 
    if(pObj == NULL)
        return hr; 

    hr = pObj->QueryInterface(iid, ppv); 
    if(hr != S_OK)
    {
        // g_DictionaryNumber-- in Destructor
        delete pObj; 
    }

    return hr; 
}

HRESULT CDictionaryFactory::LockServer(BOOL bLock)
{
    if(bLock)
        g_LockNumber++; 
    else 
        g_LockNumber--; 

    return NOERROR; 
}