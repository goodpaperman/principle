// TestCtrlDlg.h : header file
//

#if !defined(AFX_TESTCTRLDLG_H__D4FEA68A_5D49_48F2_98AD_66F02A25F044__INCLUDED_)
#define AFX_TESTCTRLDLG_H__D4FEA68A_5D49_48F2_98AD_66F02A25F044__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestCtrlDlg dialog

class CTestCtrlDlg : public CDialog
{
// Construction
public:
	CTestCtrlDlg(CWnd* pParent = NULL);	// standard constructor
    ~CTestCtrlDlg(); 

// Dialog Data
	//{{AFX_DATA(CTestCtrlDlg)
	enum { IDD = IDD_TESTCTRL_DIALOG };
	long	m_property;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
    DWORD m_dwCookie; 
    LPDISPATCH m_pDispatch; 

    BEGIN_INTERFACE_PART(EventSink, IDispatch)
        INIT_INTERFACE_PART(CTestCtrlDlg, EventSink) 
        STDMETHOD(GetTypeInfoCount)(unsigned int*); 
        STDMETHOD(GetTypeInfo)(unsigned int, LCID, ITypeInfo**); 
        STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, unsigned int, LCID, DISPID*); 
        STDMETHOD(Invoke)(DISPID, REFIID, LCID, unsigned short, DISPPARAMS*, 
            VARIANT*, EXCEPINFO*, unsigned int*); 
    END_INTERFACE_PART(EventSink) 

	// Generated message map functions
	//{{AFX_MSG(CTestCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnConn();
	afx_msg void OnBtnDisconn();
	afx_msg void OnBtnSetprop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCTRLDLG_H__D4FEA68A_5D49_48F2_98AD_66F02A25F044__INCLUDED_)
