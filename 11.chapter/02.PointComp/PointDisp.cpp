
#include "stdafx.h" 
#include "PointDisp.h" 

ULONG g_PointNumber = 0; 
ULONG g_LockNumber = 0; 



CPointObj::CPointObj()
{
    m_nRef = 0; 
    m_x = m_y = 0; 
    m_pITINeutral = NULL; 
    m_pIUnkStdDisp = NULL; 
}

CPointObj::~CPointObj()
{
    if(m_pITINeutral)
        m_pITINeutral->Release(); 
}

BOOL CPointObj::Init(IUnknown* pUnkOuter)
{
    LPUNKNOWN pIUnknown = this; 
    ITypeLib* pITypeLib; 
    HRESULT hr; 

    if(pUnkOuter != NULL) 
        pIUnknown = pUnkOuter; 

    if(FAILED(LoadRegTypeLib(LIBID_PointComp, 1, 0, LANG_NEUTRAL, &pITypeLib)))
    {
        if(FAILED(LoadTypeLib(L"PointComp.TLB", &pITypeLib)))
            return FALSE; 
    }

    hr = pITypeLib->GetTypeInfoOfGuid(DIID_IPointDisp, &m_pITINeutral); 
    pITypeLib->Release(); 
    if(FAILED(hr))
        return FALSE; 

    hr = CreateStdDispatch(pIUnknown, (IPoint*)this, m_pITINeutral, &m_pIUnkStdDisp); 
    if(FAILED(hr))
        return FALSE; 

    return TRUE; 
}

ULONG CPointObj::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CPointObj::Release()
{
    m_nRef--; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)m_nRef; 
}

HRESULT CPointObj::QueryInterface(const IID& iid, void** ppv)
{
    if(iid == IID_IUnknown || iid == IID_IPoint)
    {
        *ppv = (IPoint*)this; 
        ((IPoint*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IDispatch || iid == DIID_IPointDisp)
    {
        return m_pIUnkStdDisp->QueryInterface(IID_IDispatch, ppv); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    return S_OK; 
}




CPointDisp::CPointDisp()
{
    m_nRef = 0; 
    m_pITI = NULL; 
    m_pObj = new CPointObj;
    m_pObj->Init(this); 
    g_PointNumber ++; 
}

CPointDisp::~CPointDisp()
{
    if(m_pITI)
        m_pITI->Release(); 
    if(m_pObj)
        m_pObj->Release(); 
    g_PointNumber--; 
}

ULONG CPointDisp::AddRef()
{
    m_nRef ++; 
    return (ULONG)m_nRef; 
}

ULONG CPointDisp::Release()
{
    m_nRef--; 
    if(m_nRef == 0)
        delete this; 

    return (ULONG)m_nRef; 
}

HRESULT CPointDisp::QueryInterface(const IID& iid, void** ppv)
{
    if(iid == IID_IUnknown)
    {
        *ppv = (IPointDisp*)this; 
        ((IPointDisp*)(*ppv))->AddRef(); 
    }
    else if(iid == IID_IDispatch)
    {
        *ppv = (IPointDisp*)this; 
        ((IPointDisp*)(*ppv))->AddRef(); 
    }
    else 
    {
        *ppv = NULL; 
        return E_NOINTERFACE; 
    }

    return S_OK; 
}

STDMETHODIMP CPointDisp::GetTypeInfoCount(
	unsigned int* pctInfo)
{
    *pctInfo = 1; 
	return S_OK;
}

STDMETHODIMP CPointDisp::GetTypeInfo(
	unsigned int itInfo, LCID lcid, ITypeInfo** ppITypeInfo)
{
    HRESULT hr; 
    ITypeLib* pITypeLib; 
    ITypeInfo** ppITI = NULL; 
    if(itInfo != 0)
        return TYPE_E_ELEMENTNOTFOUND; 

    if(ppITypeInfo == NULL)
        return E_POINTER; 

    *ppITypeInfo = NULL; 
    ppITI = &m_pITI; 
    if(*ppITI == NULL)
    {
        hr = LoadRegTypeLib(LIBID_PointComp, 1, 0, lcid, &pITypeLib); 
        if(FAILED(hr))
        {
            hr = LoadTypeLib(L"PointComp.TLB", &pITypeLib); 
        }

        if(FAILED(hr))
            return hr; 

        hr = pITypeLib->GetTypeInfoOfGuid(DIID_IPointDisp, ppITI); 
        pITypeLib->Release(); 
        if(FAILED(hr))
            return hr; 
    }

    (*ppITI)->AddRef(); 
    *ppITypeInfo = *ppITI; 
	return S_OK;
}

STDMETHODIMP CPointDisp::GetIDsOfNames(
	REFIID riid, LPOLESTR* rgszNames, unsigned int cNames, LCID lcid, DISPID* rgDispID)
{
    HRESULT hr; 
    ITypeInfo* pTI; 
    if(riid != IID_NULL)
        return DISP_E_UNKNOWNINTERFACE; 

    hr = GetTypeInfo(0, lcid, &pTI); 
    if(SUCCEEDED(hr))
    {
        hr = pTI->GetIDsOfNames(rgszNames, cNames, rgDispID); 
        pTI->Release(); 
    }

    // or 
    //DispGetIDsOfNames(pTI, rgszNames, cNames, rgDispID); 
	return hr; 
}

STDMETHODIMP CPointDisp::Invoke(
	DISPID dispid, REFIID riid, LCID lcid, unsigned short wFlags,
	DISPPARAMS* pDispParams, VARIANT* pvarResult,
	EXCEPINFO* pExcepInfo, unsigned int* puArgError)
{
    HRESULT hr; 
    ITypeInfo* pTI; 
    if(riid != IID_NULL)
        return DISP_E_UNKNOWNINTERFACE; 

    hr = GetTypeInfo(0, lcid, &pTI); 
    if(FAILED(hr))
        return hr; 

    hr = pTI->Invoke((IPoint*)m_pObj, dispid, wFlags, 
        pDispParams, pvarResult, pExcepInfo, puArgError); 
    pTI->Release(); 
    return hr; 
}