
#include "stdafx.h" 
#include "factory.h" 
#include "PointDisp.h" 

CPointFactory::CPointFactory()
{
    m_nRef = 0; 
}

CPointFactory::~CPointFactory()
{
}

HRESULT CPointFactory::QueryInterface(const IID& iid, void** ppv)
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

ULONG CPointFactory::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CPointFactory::Release()
{
    m_nRef --; 
    if(m_nRef == 0)
    {
        delete this; 
    }

    return (ULONG)m_nRef; 
}

HRESULT CPointFactory::CreateInstance(IUnknown* pUnknownOuter, const IID& iid, void** ppv)
{
    CPointDisp* pObj; 
    HRESULT hr = E_OUTOFMEMORY; 
    *ppv = NULL; 
    if(pUnknownOuter != NULL)
        return CLASS_E_NOAGGREGATION; 

    // g_DictionaryNumber ++ in Constructor
    pObj = new CPointDisp(); 
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

HRESULT CPointFactory::LockServer(BOOL bLock)
{
    if(bLock)
        g_LockNumber++; 
    else 
        g_LockNumber--; 

    return NOERROR; 
}