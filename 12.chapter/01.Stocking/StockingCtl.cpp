// StockingCtl.cpp : Implementation of the CStockingCtrl ActiveX Control class.

#include "stdafx.h"
#include "Stocking.h"
#include "StockingCtl.h"
#include "StockingPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CStockingCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CStockingCtrl, COleControl)
	//{{AFX_MSG_MAP(CStockingCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CStockingCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CStockingCtrl)
	DISP_DEFVALUE(CStockingCtrl, "ReadyState")
	DISP_STOCKFUNC_REFRESH()
	DISP_STOCKFUNC_DOCLICK()
	DISP_STOCKPROP_APPEARANCE()
	DISP_STOCKPROP_BACKCOLOR()
	DISP_STOCKPROP_BORDERSTYLE()
	DISP_STOCKPROP_CAPTION()
	DISP_STOCKPROP_ENABLED()
	DISP_STOCKPROP_FONT()
	DISP_STOCKPROP_FORECOLOR()
	DISP_STOCKPROP_HWND()
	DISP_STOCKPROP_READYSTATE()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CStockingCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CStockingCtrl, COleControl)
	//{{AFX_EVENT_MAP(CStockingCtrl)
	EVENT_STOCK_CLICK()
	EVENT_STOCK_DBLCLICK()
	EVENT_STOCK_ERROREVENT()
	EVENT_STOCK_KEYDOWN()
	EVENT_STOCK_KEYPRESS()
	EVENT_STOCK_KEYUP()
	EVENT_STOCK_MOUSEDOWN()
	EVENT_STOCK_MOUSEMOVE()
	EVENT_STOCK_MOUSEUP()
	EVENT_STOCK_READYSTATECHANGE()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CStockingCtrl, 1)
	PROPPAGEID(CStockingPropPage::guid)
END_PROPPAGEIDS(CStockingCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CStockingCtrl, "STOCKING.StockingCtrl.1",
	0xf4a62cab, 0x1950, 0x41a9, 0xb0, 0xad, 0x9e, 0x87, 0x83, 0xd1, 0x89, 0x36)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CStockingCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DStocking =
		{ 0xeb335b9e, 0xef8, 0x4d65, { 0x99, 0x73, 0x98, 0xca, 0x42, 0xff, 0xb9, 0x85 } };
const IID BASED_CODE IID_DStockingEvents =
		{ 0x4e16806f, 0xeef6, 0x4e69, { 0xa9, 0x62, 0xaf, 0xc, 0x69, 0x92, 0x81, 0xbe } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwStockingOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CStockingCtrl, IDS_STOCKING, _dwStockingOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::CStockingCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CStockingCtrl

BOOL CStockingCtrl::CStockingCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_STOCKING,
			IDB_STOCKING,
			afxRegApartmentThreading,
			_dwStockingOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("Stocking.lic");

static const WCHAR BASED_CODE _szLicString[] =
	L"Copyright (c) 2011 ·¬ÇÑ»¨Ô°";


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::CStockingCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

BOOL CStockingCtrl::CStockingCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::CStockingCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CStockingCtrl::CStockingCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::CStockingCtrl - Constructor

CStockingCtrl::CStockingCtrl()
{
	InitializeIIDs(&IID_DStocking, &IID_DStockingEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::~CStockingCtrl - Destructor

CStockingCtrl::~CStockingCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::OnDraw - Drawing function

void CStockingCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::DoPropExchange - Persistence support

void CStockingCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::OnResetState - Reset control to default state

void CStockingCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl::AboutBox - Display an "About" box to the user

void CStockingCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_STOCKING);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl message handlers
