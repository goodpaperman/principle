// TestCtrl.h : main header file for the TESTCTRL application
//

#if !defined(AFX_TESTCTRL_H__E011D066_DBDC_4CBF_92D9_2819A756E592__INCLUDED_)
#define AFX_TESTCTRL_H__E011D066_DBDC_4CBF_92D9_2819A756E592__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestCtrlApp:
// See TestCtrl.cpp for the implementation of this class
//

class CTestCtrlApp : public CWinApp
{
public:
	CTestCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCTRL_H__E011D066_DBDC_4CBF_92D9_2819A756E592__INCLUDED_)
