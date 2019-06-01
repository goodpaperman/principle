// PointComp.h : main header file for the POINTCOMP DLL
//

#if !defined(AFX_POINTCOMP_H__AEBF269B_2A2F_4C73_80B8_6D2E9EA752A2__INCLUDED_)
#define AFX_POINTCOMP_H__AEBF269B_2A2F_4C73_80B8_6D2E9EA752A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointCompApp
// See PointComp.cpp for the implementation of this class
//

class CPointCompApp : public CWinApp
{
public:
	CPointCompApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCompApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPointCompApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTCOMP_H__AEBF269B_2A2F_4C73_80B8_6D2E9EA752A2__INCLUDED_)
