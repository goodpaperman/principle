// SourceObj.cpp : implementation file
//

#include "stdafx.h"
#include "SourceComp.h"
#include "SourceObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSourceObj

IMPLEMENT_DYNCREATE(CSourceObj, CCmdTarget)

CSourceObj::CSourceObj()
{
	EnableAutomation();
	EnableConnections(); 

	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CSourceObj::~CSourceObj()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CSourceObj::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CSourceObj, CCmdTarget)
	//{{AFX_MSG_MAP(CSourceObj)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSourceObj, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CSourceObj)
	DISP_PROPERTY_EX(CSourceObj, "MyProperty", GetMyProperty, SetMyProperty, VT_I4)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ISourceObj to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {F1C14DD3-0351-4002-8425-87E2AE8203D6}
static const IID IID_ISourceObj =
{ 0xf1c14dd3, 0x351, 0x4002, { 0x84, 0x25, 0x87, 0xe2, 0xae, 0x82, 0x3, 0xd6 } };

BEGIN_INTERFACE_MAP(CSourceObj, CCmdTarget)
	INTERFACE_PART(CSourceObj, IID_ISourceObj, Dispatch)
    INTERFACE_PART(CSourceObj, IID_IConnectionPointContainer, ConnPtContainer) 
END_INTERFACE_MAP()

BEGIN_CONNECTION_MAP(CSourceObj, CCmdTarget) 
    CONNECTION_PART(CSourceObj, IID_IEventSet, EventSetConnPt) 
END_CONNECTION_MAP()

// {9E4874BE-FD1B-4FD1-A678-492050CD2FE8}
IMPLEMENT_OLECREATE(CSourceObj, "SourceComp.SourceObj", 0x9e4874be, 0xfd1b, 0x4fd1, 0xa6, 0x78, 0x49, 0x20, 0x50, 0xcd, 0x2f, 0xe8)

/////////////////////////////////////////////////////////////////////////////
// CSourceObj message handlers

REFIID CSourceObj::XEventSetConnPt::GetIID()
{
    return IID_IEventSet; 
}

long CSourceObj::GetMyProperty() 
{
	// TODO: Add your property handler here

	return m_property;
}

void CSourceObj::SetMyProperty(long nNewValue) 
{
	// TODO: Add your property handler here
    m_property = nNewValue; 
    FirePropChanged(m_property); 
}

void CSourceObj::FirePropChanged(long nInt)
{
    POSITION pos = m_xEventSetConnPt.GetStartPosition(); 
    IEventSet* pInter; 
    while(pos != NULL)
    {
        pInter = (IEventSet*)m_xEventSetConnPt.GetNextConnection(pos); 
        pInter->PropChanged(nInt); 
    }
}