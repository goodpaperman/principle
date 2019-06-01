/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jun 05 20:51:55 2011
 */
/* Compiler settings for E:\codes\mfc\11.Panaiming.COM principle & apply\05.chapter\03.DictComp\DictComp.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "DictComp.h"

#define TYPE_FORMAT_STRING_SIZE   15                                
#define PROC_FORMAT_STRING_SIZE   231                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDictionary, ver. 0.0,
   GUID={0x001A7733,0xAD05,0x4009,{0xBF,0x22,0x79,0x8B,0xA9,0xD5,0x20,0x36}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDictionary_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IDictionary_FormatStringOffsetTable[] = 
    {
    0,
    22,
    50,
    84,
    112,
    146,
    174
    };

static const MIDL_SERVER_INFO IDictionary_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IDictionary_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IDictionary_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IDictionary_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IDictionaryProxyVtbl = 
{
    &IDictionary_ProxyInfo,
    &IID_IDictionary,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* IDictionary::Initialize */ ,
    (void *)-1 /* IDictionary::LoadLibrary */ ,
    (void *)-1 /* IDictionary::InsertWord */ ,
    (void *)-1 /* IDictionary::DeleteWord */ ,
    (void *)-1 /* IDictionary::LookupWord */ ,
    (void *)-1 /* IDictionary::RestoreLibrary */ ,
    (void *)-1 /* IDictionary::FreeLibrary */
};

const CInterfaceStubVtbl _IDictionaryStubVtbl =
{
    &IID_IDictionary,
    &IDictionary_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ISpellCheck, ver. 0.0,
   GUID={0x20A839D6,0x125D,0x43a4,{0xBA,0x89,0x09,0xDB,0x67,0x69,0xDD,0xD9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISpellCheck_ServerInfo;

#pragma code_seg(".orpc")

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ISpellCheck_FormatStringOffsetTable[] = 
    {
    196
    };

static const MIDL_SERVER_INFO ISpellCheck_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISpellCheck_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISpellCheck_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISpellCheck_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(4) _ISpellCheckProxyVtbl = 
{
    &ISpellCheck_ProxyInfo,
    &IID_ISpellCheck,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ISpellCheck::CheckWord */
};

const CInterfaceStubVtbl _ISpellCheckStubVtbl =
{
    &IID_ISpellCheck,
    &ISpellCheck_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Initialize */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 16 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadLibrary */

/* 22 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 24 */	NdrFcLong( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x4 ),	/* 4 */
#ifndef _ALPHA_
/* 30 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter __MIDL_0015 */

/* 38 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 40 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 42 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 44 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InsertWord */

/* 50 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 52 */	NdrFcLong( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x5 ),	/* 5 */
#ifndef _ALPHA_
/* 58 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x8 ),	/* 8 */
/* 64 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter __MIDL_0016 */

/* 66 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 70 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter __MIDL_0017 */

/* 72 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 76 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteWord */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x6 ),	/* 6 */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter __MIDL_0018 */

/* 100 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 102 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 104 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LookupWord */

/* 112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 120 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter __MIDL_0019 */

/* 128 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 130 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 132 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter __MIDL_0020 */

/* 134 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 138 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RestoreLibrary */

/* 146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 154 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter __MIDL_0021 */

/* 162 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 164 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 166 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FreeLibrary */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 182 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 192 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckWord */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/* 204 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter __MIDL_0022 */

/* 212 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 216 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter __MIDL_0023 */

/* 218 */	NdrFcShort( 0x200b ),	/* Flags:  must size, must free, in, srv alloc size=8 */
#ifndef _ALPHA_
/* 220 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 222 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 226 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 12 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _DictComp_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDictionaryProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ISpellCheckProxyVtbl,
    0
};

const CInterfaceStubVtbl * _DictComp_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDictionaryStubVtbl,
    ( CInterfaceStubVtbl *) &_ISpellCheckStubVtbl,
    0
};

PCInterfaceName const _DictComp_InterfaceNamesList[] = 
{
    "IDictionary",
    "ISpellCheck",
    0
};


#define _DictComp_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _DictComp, pIID, n)

int __stdcall _DictComp_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _DictComp, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _DictComp, 2, *pIndex )
    
}

const ExtendedProxyFileInfo DictComp_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _DictComp_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _DictComp_StubVtblList,
    (const PCInterfaceName * ) & _DictComp_InterfaceNamesList,
    0, // no delegation
    & _DictComp_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
