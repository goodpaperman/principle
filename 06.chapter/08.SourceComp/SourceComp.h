// SourceComp.h : main header file for the SOURCECOMP application
//

#if !defined(AFX_SOURCECOMP_H__5F90C88F_AF54_40DB_8951_7831FE118219__INCLUDED_)
#define AFX_SOURCECOMP_H__5F90C88F_AF54_40DB_8951_7831FE118219__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSourceCompApp:
// See SourceComp.cpp for the implementation of this class
//

class CSourceCompApp : public CWinApp
{
public:
	CSourceCompApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSourceCompApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSourceCompApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOURCECOMP_H__5F90C88F_AF54_40DB_8951_7831FE118219__INCLUDED_)
