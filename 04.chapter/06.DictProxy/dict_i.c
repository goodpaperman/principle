/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue May 31 19:33:52 2011
 */
/* Compiler settings for dict.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IDictionary = {0x001A7733,0xAD05,0x4009,{0xBF,0x22,0x79,0x8B,0xA9,0xD5,0x20,0x36}};


const IID IID_ISpellCheck = {0x20A839D6,0x125D,0x43a4,{0xBA,0x89,0x09,0xDB,0x67,0x69,0xDD,0xD9}};


#ifdef __cplusplus
}
#endif

