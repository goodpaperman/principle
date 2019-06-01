// PointClient.h : main header file for the POINTCLIENT application
//

#if !defined(AFX_POINTCLIENT_H__11F6B077_D7A6_4B69_AD4C_9BF6B6C74136__INCLUDED_)
#define AFX_POINTCLIENT_H__11F6B077_D7A6_4B69_AD4C_9BF6B6C74136__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointClientApp:
// See PointClient.cpp for the implementation of this class
//

class CPointClientApp : public CWinApp
{
public:
	CPointClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPointClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTCLIENT_H__11F6B077_D7A6_4B69_AD4C_9BF6B6C74136__INCLUDED_)
