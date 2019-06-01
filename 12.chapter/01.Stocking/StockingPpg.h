#if !defined(AFX_STOCKINGPPG_H__DD8946C3_EFFF_4F19_A6D1_624A62AD8857__INCLUDED_)
#define AFX_STOCKINGPPG_H__DD8946C3_EFFF_4F19_A6D1_624A62AD8857__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// StockingPpg.h : Declaration of the CStockingPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CStockingPropPage : See StockingPpg.cpp.cpp for implementation.

class CStockingPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CStockingPropPage)
	DECLARE_OLECREATE_EX(CStockingPropPage)

// Constructor
public:
	CStockingPropPage();

// Dialog Data
	//{{AFX_DATA(CStockingPropPage)
	enum { IDD = IDD_PROPPAGE_STOCKING };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CStockingPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKINGPPG_H__DD8946C3_EFFF_4F19_A6D1_624A62AD8857__INCLUDED)
