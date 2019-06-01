/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jun 30 21:15:48 2011
 */
/* Compiler settings for E:\codes\mfc\11.Panaiming.COM principle & apply\11.chapter\02.PointComp\PointComp.odl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __IPoint_h__
#define __IPoint_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPoint_FWD_DEFINED__
#define __IPoint_FWD_DEFINED__
typedef interface IPoint IPoint;
#endif 	/* __IPoint_FWD_DEFINED__ */


#ifndef __IPointDisp_FWD_DEFINED__
#define __IPointDisp_FWD_DEFINED__
typedef interface IPointDisp IPointDisp;
#endif 	/* __IPointDisp_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __PointComp_LIBRARY_DEFINED__
#define __PointComp_LIBRARY_DEFINED__

/* library PointComp */
/* [version][uuid] */ 


DEFINE_GUID(LIBID_PointComp,0x57FE7127,0x74B9,0x46DE,0xAC,0xCD,0x54,0x71,0x10,0xEB,0x0C,0x9A);

#ifndef __IPoint_INTERFACE_DEFINED__
#define __IPoint_INTERFACE_DEFINED__

/* interface IPoint */
/* [object][helpstring][uuid] */ 


DEFINE_GUID(IID_IPoint,0x3C591B25,0x1F13,0x101B,0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE0);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C591B25-1F13-101B-B826-00DD01103DE0")
    IPoint : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_x( 
            /* [retval][out] */ int __RPC_FAR *retval) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_x( 
            /* [in] */ int Value) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_y( 
            /* [retval][out] */ int __RPC_FAR *retval) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_y( 
            /* [in] */ int Value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ int newX,
            /* [in] */ int newY) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPointVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPoint __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPoint __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPoint __RPC_FAR * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_x )( 
            IPoint __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *retval);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_x )( 
            IPoint __RPC_FAR * This,
            /* [in] */ int Value);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_y )( 
            IPoint __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *retval);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_y )( 
            IPoint __RPC_FAR * This,
            /* [in] */ int Value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveTo )( 
            IPoint __RPC_FAR * This,
            /* [in] */ int newX,
            /* [in] */ int newY);
        
        END_INTERFACE
    } IPointVtbl;

    interface IPoint
    {
        CONST_VTBL struct IPointVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPoint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPoint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPoint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPoint_get_x(This,retval)	\
    (This)->lpVtbl -> get_x(This,retval)

#define IPoint_put_x(This,Value)	\
    (This)->lpVtbl -> put_x(This,Value)

#define IPoint_get_y(This,retval)	\
    (This)->lpVtbl -> get_y(This,retval)

#define IPoint_put_y(This,Value)	\
    (This)->lpVtbl -> put_y(This,Value)

#define IPoint_MoveTo(This,newX,newY)	\
    (This)->lpVtbl -> MoveTo(This,newX,newY)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPoint_get_x_Proxy( 
    IPoint __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *retval);


void __RPC_STUB IPoint_get_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPoint_put_x_Proxy( 
    IPoint __RPC_FAR * This,
    /* [in] */ int Value);


void __RPC_STUB IPoint_put_x_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE IPoint_get_y_Proxy( 
    IPoint __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *retval);


void __RPC_STUB IPoint_get_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE IPoint_put_y_Proxy( 
    IPoint __RPC_FAR * This,
    /* [in] */ int Value);


void __RPC_STUB IPoint_put_y_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IPoint_MoveTo_Proxy( 
    IPoint __RPC_FAR * This,
    /* [in] */ int newX,
    /* [in] */ int newY);


void __RPC_STUB IPoint_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPoint_INTERFACE_DEFINED__ */


#ifndef __IPointDisp_DISPINTERFACE_DEFINED__
#define __IPointDisp_DISPINTERFACE_DEFINED__

/* dispinterface IPointDisp */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IPointDisp,0x3C591B21,0x1F13,0x101B,0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE0);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3C591B21-1F13-101B-B826-00DD01103DE0")
    IPointDisp : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPointDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IPointDisp __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IPointDisp __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IPointDisp __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IPointDisp __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IPointDisp __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IPointDisp __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IPointDisp __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IPointDispVtbl;

    interface IPointDisp
    {
        CONST_VTBL struct IPointDispVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPointDisp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPointDisp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPointDisp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPointDisp_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPointDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPointDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPointDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPointDisp_DISPINTERFACE_DEFINED__ */

#endif /* __PointComp_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
