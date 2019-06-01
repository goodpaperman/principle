/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Jul 02 22:02:57 2011
 */
/* Compiler settings for E:\codes\mfc\11.Panaiming.COM principle & apply\11.chapter\03.PointComp\PointComp.odl:
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

const IID LIBID_PointComp = {0x57FE7127,0x74B9,0x46DE,{0xAC,0xCD,0x54,0x71,0x10,0xEB,0x0C,0x9C}};


const IID IID_IPoint = {0x3C591B25,0x1F13,0x101B,{0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE2}};


const CLSID CLSID_Point = {0x3C591B21,0x1F13,0x101B,{0xB8,0x26,0x00,0xDD,0x01,0x10,0x3D,0xE2}};


#ifdef __cplusplus
}
#endif

