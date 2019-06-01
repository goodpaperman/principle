// StockingPpg.cpp : Implementation of the CStockingPropPage property page class.

#include "stdafx.h"
#include "Stocking.h"
#include "StockingPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CStockingPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CStockingPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CStockingPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CStockingPropPage, "STOCKING.StockingPropPage.1",
	0x279bab97, 0x8022, 0x4e31, 0x97, 0x6d, 0xfc, 0x9d, 0x1f, 0x71, 0x5c, 0xbf)


/////////////////////////////////////////////////////////////////////////////
// CStockingPropPage::CStockingPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CStockingPropPage

BOOL CStockingPropPage::CStockingPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_STOCKING_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CStockingPropPage::CStockingPropPage - Constructor

CStockingPropPage::CStockingPropPage() :
	COlePropertyPage(IDD, IDS_STOCKING_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CStockingPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CStockingPropPage::DoDataExchange - Moves data between page and properties

void CStockingPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CStockingPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CStockingPropPage message handlers
