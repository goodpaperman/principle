/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jun 29 20:01:12 2011
 */
/* Compiler settings for di_point.odl:
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

const IID LIBID_Point = {0x3C591B20,0x1F13,0x101B,{0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE1}};


const IID IID_IPoint = {0x3C591B25,0x1F13,0x101B,{0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE1}};


const IID DIID_Point = {0x3C591B21,0x1F13,0x101B,{0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE1}};


#ifdef __cplusplus
}
#endif

