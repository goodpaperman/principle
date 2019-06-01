#if !defined(AFX_POINTOBJ_H__B648BBDD_CC29_4662_814B_24F77E54C757__INCLUDED_)
#define AFX_POINTOBJ_H__B648BBDD_CC29_4662_814B_24F77E54C757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PointObj.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CPointObj command target

class CPointObj : public CCmdTarget
{
	DECLARE_DYNCREATE(CPointObj)

	CPointObj();           // protected constructor used by dynamic creation

// Attributes
public:
    long m_x; 
    long m_y; 

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointObj)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPointObj();

	// Generated message map functions
	//{{AFX_MSG(CPointObj)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPointObj)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CPointObj)
	afx_msg long GetX();
	afx_msg void SetX(long nNewValue);
	afx_msg long GetY();
	afx_msg void SetY(long nNewValue);
	afx_msg void MoveTo(long newX, long newY);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTOBJ_H__B648BBDD_CC29_4662_814B_24F77E54C757__INCLUDED_)
