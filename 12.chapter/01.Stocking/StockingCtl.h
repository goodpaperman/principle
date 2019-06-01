#if !defined(AFX_STOCKINGCTL_H__FB394901_0592_4093_A77B_3C8248BE7AE1__INCLUDED_)
#define AFX_STOCKINGCTL_H__FB394901_0592_4093_A77B_3C8248BE7AE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// StockingCtl.h : Declaration of the CStockingCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CStockingCtrl : See StockingCtl.cpp for implementation.

class CStockingCtrl : public COleControl
{
	DECLARE_DYNCREATE(CStockingCtrl)

// Constructor
public:
	CStockingCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStockingCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CStockingCtrl();

	BEGIN_OLEFACTORY(CStockingCtrl)        // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CStockingCtrl)

	DECLARE_OLETYPELIB(CStockingCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CStockingCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CStockingCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CStockingCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CStockingCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CStockingCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CStockingCtrl)
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKINGCTL_H__FB394901_0592_4093_A77B_3C8248BE7AE1__INCLUDED)
