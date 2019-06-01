// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__92D3808F_B565_462B_B4AD_2E0C9C8B72E0__INCLUDED_)
#define AFX_STDAFX_H__92D3808F_B565_462B_B4AD_2E0C9C8B72E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Insert your headers here
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <wtypes.h> 
#include <unknwn.h> 
#include <comutil.h> 
#include <stdio.h> 
#include <olectl.h> 
#include "PointComp_i.c" 

extern ULONG g_LockNumber; 
extern ULONG g_PointNumber; 

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__92D3808F_B565_462B_B4AD_2E0C9C8B72E0__INCLUDED_)
