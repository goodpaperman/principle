// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__08B0F378_D96E_4F0D_B6B4_C7904C34997C__INCLUDED_)
#define AFX_DLGPROXY_H__08B0F378_D96E_4F0D_B6B4_C7904C34997C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSourceCompDlg;

/////////////////////////////////////////////////////////////////////////////
// CSourceCompDlgAutoProxy command target

class CSourceCompDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CSourceCompDlgAutoProxy)

	CSourceCompDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CSourceCompDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSourceCompDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSourceCompDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CSourceCompDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSourceCompDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CSourceCompDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__08B0F378_D96E_4F0D_B6B4_C7904C34997C__INCLUDED_)
