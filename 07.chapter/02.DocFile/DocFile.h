// DocFile.h : main header file for the DOCFILE application
//

#if !defined(AFX_DOCFILE_H__80538223_697C_4FD1_93B8_EEDE7F5C2CD9__INCLUDED_)
#define AFX_DOCFILE_H__80538223_697C_4FD1_93B8_EEDE7F5C2CD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDocFileApp:
// See DocFile.cpp for the implementation of this class
//

class CDocFileApp : public CWinApp
{
public:
	CDocFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDocFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCFILE_H__80538223_697C_4FD1_93B8_EEDE7F5C2CD9__INCLUDED_)
