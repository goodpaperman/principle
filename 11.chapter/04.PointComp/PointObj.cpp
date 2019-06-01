// PointObj.cpp : implementation file
//

#include "stdafx.h"
#include "PointComp.h"
#include "PointObj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPointObj

IMPLEMENT_DYNCREATE(CPointObj, CCmdTarget)

CPointObj::CPointObj()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CPointObj::~CPointObj()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CPointObj::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CPointObj, CCmdTarget)
	//{{AFX_MSG_MAP(CPointObj)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPointObj, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CPointObj)
	DISP_PROPERTY_EX(CPointObj, "x", GetX, SetX, VT_I4)
	DISP_PROPERTY_EX(CPointObj, "y", GetY, SetY, VT_I4)
	DISP_FUNCTION(CPointObj, "MoveTo", MoveTo, VT_EMPTY, VTS_I4 VTS_I4)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IPointObj to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {E319392E-413A-4B04-A946-5EAFBFFECD97}
static const IID IID_IPointObj =
{ 0xe319392e, 0x413a, 0x4b04, { 0xa9, 0x46, 0x5e, 0xaf, 0xbf, 0xfe, 0xcd, 0x97 } };

BEGIN_INTERFACE_MAP(CPointObj, CCmdTarget)
	INTERFACE_PART(CPointObj, IID_IPointObj, Dispatch)
END_INTERFACE_MAP()

// {3C591B21-1F13-101B-B826-00DD01103DE2}
IMPLEMENT_OLECREATE(CPointObj, "PointComp.PointObj", 0x3c591b21, 0x1f13, 0x101b, 0xb8, 0x26, 0x0, 0xdd, 0x1, 0x10, 0x3d, 0xe2)

/////////////////////////////////////////////////////////////////////////////
// CPointObj message handlers

long CPointObj::GetX() 
{
	// TODO: Add your property handler here
    return m_x; 
}

void CPointObj::SetX(long nNewValue) 
{
	// TODO: Add your property handler here
    m_x = nNewValue; 
}

long CPointObj::GetY() 
{
	// TODO: Add your property handler here
    return m_y; 
}

void CPointObj::SetY(long nNewValue) 
{
	// TODO: Add your property handler here
    m_y = nNewValue; 
}

void CPointObj::MoveTo(long newX, long newY) 
{
	// TODO: Add your dispatch handler code here
    m_x = newX; 
    m_y = newY; 
}
