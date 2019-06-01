#if !defined(AFX_STOCKING_H__5CBE19AC_2BC7_4602_8A9B_122E5E238AA7__INCLUDED_)
#define AFX_STOCKING_H__5CBE19AC_2BC7_4602_8A9B_122E5E238AA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Stocking.h : main header file for STOCKING.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStockingApp : See Stocking.cpp for implementation.

class CStockingApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKING_H__5CBE19AC_2BC7_4602_8A9B_122E5E238AA7__INCLUDED)
