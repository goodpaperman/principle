#if !defined(AFX_SOURCEOBJ_H__23D9F3F5_EE7F_4D3A_98EB_9E72E2E602D4__INCLUDED_)
#define AFX_SOURCEOBJ_H__23D9F3F5_EE7F_4D3A_98EB_9E72E2E602D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SourceObj.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSourceObj command target
class CSourceObj : public CCmdTarget
{
	DECLARE_DYNCREATE(CSourceObj)

	CSourceObj();           // protected constructor used by dynamic creation

// Attributes
public:
    long m_property; 
    void FirePropChanged(long nInt); 

// Operations
public:
    BEGIN_CONNECTION_PART(CSourceObj, SourceObjConnPt)
        virtual REFIID GetIID(); 
    END_CONNECTION_PART(SourceObjConnPt) 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSourceObj)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CSourceObj();

	// Generated message map functions
	//{{AFX_MSG(CSourceObj)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CSourceObj)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CSourceObj)
	afx_msg long GetMyProperty();
	afx_msg void SetMyProperty(long nNewValue);
	afx_msg void PropChanged(long nInt);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
    DECLARE_CONNECTION_MAP() 
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOURCEOBJ_H__23D9F3F5_EE7F_4D3A_98EB_9E72E2E602D4__INCLUDED_)
