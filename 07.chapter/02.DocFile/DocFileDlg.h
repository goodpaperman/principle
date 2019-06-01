// DocFileDlg.h : header file
//

#if !defined(AFX_DOCFILEDLG_H__33C29C2E_0C3A_4A00_A8B6_83B1D2E47B74__INCLUDED_)
#define AFX_DOCFILEDLG_H__33C29C2E_0C3A_4A00_A8B6_83B1D2E47B74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDocFileDlg dialog

class CDocFileDlg : public CDialog
{
// Construction
public:
	CDocFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDocFileDlg)
	enum { IDD = IDD_DOCFILE_DIALOG };
	CString	m_strInput;
	CString	m_strOutput;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDocFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

    void ReadStorage(LPSTORAGE pStg); 
    void ReadDirectory(const char* szPath, LPSTORAGE pStg); 

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDocFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnInput();
	afx_msg void OnBtnOutput();
	afx_msg void OnBtnRead();
	afx_msg void OnBtnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCFILEDLG_H__33C29C2E_0C3A_4A00_A8B6_83B1D2E47B74__INCLUDED_)
