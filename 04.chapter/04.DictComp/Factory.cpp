
#include "stdafx.h" 
#include "factory.h" 
#include "Dictionary.h" 

CDictionaryFactory* CDictionaryFactory::theFactory = NULL; 
DWORD CDictionaryFactory::dwRegister = 0; 

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
    int ret = m_nRef; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)ret; 
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
    {
        g_LockNumber--; 
        if(CanUnloadNow())
            ::PostThreadMessage(dwMainThreadID, WM_QUIT, 0, 0); 
    }

    return NOERROR; 
}

BOOL CDictionaryFactory::CanUnloadNow()
{
    if(g_LockNumber == 0 && g_DictionaryNumber == 0)
        return TRUE; 
    else 
        return FALSE; 
}

BOOL CDictionaryFactory::RegisterFactory()
{
    theFactory = new CDictionaryFactory(); 
    theFactory->AddRef(); 
    IUnknown* pUnk = (IUnknown*)theFactory; 
    HRESULT hr = ::CoRegisterClassObject(
        CLSID_Dictionary, 
        pUnk, 
        CLSCTX_LOCAL_SERVER, 
        REGCLS_MULTIPLEUSE, 
        &dwRegister); 

    if(FAILED(hr))
    {
        theFactory->Release();
        return FALSE; 
    }

    return TRUE; 
}

BOOL CDictionaryFactory::UnregisterFactory()
{
    HRESULT hr = E_FAIL; 
    if(dwRegister != 0)
        hr = ::CoRevokeClassObject(dwRegister); 

    if(theFactory != NULL)
        theFactory->Release(); 

    return !FAILED(hr); 
}

