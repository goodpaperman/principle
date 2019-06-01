// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "SourceComp.h"
#include "DlgProxy.h"
#include "SourceCompDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSourceCompDlgAutoProxy

IMPLEMENT_DYNCREATE(CSourceCompDlgAutoProxy, CCmdTarget)

CSourceCompDlgAutoProxy::CSourceCompDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CSourceCompDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CSourceCompDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CSourceCompDlgAutoProxy::~CSourceCompDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CSourceCompDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CSourceCompDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CSourceCompDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSourceCompDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CSourceCompDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISourceComp to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {2D7A295F-864D-4776-B1D8-B5F968CD233B}
static const IID IID_ISourceComp =
{ 0x2d7a295f, 0x864d, 0x4776, { 0xb1, 0xd8, 0xb5, 0xf9, 0x68, 0xcd, 0x23, 0x3b } };

BEGIN_INTERFACE_MAP(CSourceCompDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CSourceCompDlgAutoProxy, IID_ISourceComp, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {F116A612-0890-4AC2-9A33-EB43A9ADD8F7}
IMPLEMENT_OLECREATE2(CSourceCompDlgAutoProxy, "SourceComp.Application", 0xf116a612, 0x890, 0x4ac2, 0x9a, 0x33, 0xeb, 0x43, 0xa9, 0xad, 0xd8, 0xf7)

/////////////////////////////////////////////////////////////////////////////
// CSourceCompDlgAutoProxy message handlers
