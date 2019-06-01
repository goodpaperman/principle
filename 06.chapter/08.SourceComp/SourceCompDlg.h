// SourceCompDlg.h : header file
//

#if !defined(AFX_SOURCECOMPDLG_H__133E1AA6_3FC2_4A23_96CB_45F51A4DF554__INCLUDED_)
#define AFX_SOURCECOMPDLG_H__133E1AA6_3FC2_4A23_96CB_45F51A4DF554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSourceCompDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CSourceCompDlg dialog

class CSourceCompDlg : public CDialog
{
	DECLARE_DYNAMIC(CSourceCompDlg);
	friend class CSourceCompDlgAutoProxy;

// Construction
public:
	CSourceCompDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CSourceCompDlg();

// Dialog Data
	//{{AFX_DATA(CSourceCompDlg)
	enum { IDD = IDD_SOURCECOMP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSourceCompDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CSourceCompDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CSourceCompDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOURCECOMPDLG_H__133E1AA6_3FC2_4A23_96CB_45F51A4DF554__INCLUDED_)
