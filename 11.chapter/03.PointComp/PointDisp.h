
#ifndef __POINTDISP_H__
#define __POINTDISP_H__

#include "IPoint.h" 

class CPointObj : public IPoint
{
public:
    CPointObj(); 
    ~CPointObj(); 
    BOOL Init(IUnknown* pUnkOuter); 

public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** pv); 
    virtual ULONG _stdcall AddRef(); 
    virtual ULONG _stdcall Release(); 
    
    STDMETHOD(GetTypeInfoCount)(unsigned int*);
    STDMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**);
    STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, unsigned int, LCID, DISPID*);
    STDMETHOD(Invoke)(DISPID, REFIID, LCID, unsigned short, DISPPARAMS*,
						  VARIANT*, EXCEPINFO*, unsigned int*);
    
    virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_x( 
        /* [retval][out] */ int __RPC_FAR *retval)
    {
        *retval = m_x; 
        return S_OK; 
    }
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_x( 
        /* [in] */ int Value)
        {
            m_x = Value; 
            return S_OK; 
        }
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_y( 
        /* [retval][out] */ int __RPC_FAR *retval)
        {
            *retval = m_y; 
            return S_OK; 
        }
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_y( 
        /* [in] */ int Value)
        {
            m_y = Value; 
            return S_OK; 
        }
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveTo( 
        /* [in] */ int newX,
        /* [in] */ int newY)
        {
            m_x = newX; 
            m_y = newY; 
            return S_OK; 
        }

private:
    long m_x; 
    long m_y; 
    long m_nRef; 
    ITypeInfo* m_pITINeutral; 
    IUnknown* m_pIUnkStdDisp; 
}; 

#endif // __POINTDISP_H__