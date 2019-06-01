#if !defined(AFX_DICTIONARYOBJ_H__98369008_0AD1_4295_95B2_7AE7A8A1709B__INCLUDED_)
#define AFX_DICTIONARYOBJ_H__98369008_0AD1_4295_95B2_7AE7A8A1709B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DictionaryObj.h : header file
//

#include "..\\include\\IDictionary.h" 
#include "..\\include\\ISpellCheck.h" 

#define MaxWordLength 32

struct DictWord
{
    char wordForLang1[MaxWordLength]; 
    char wordForLang2[MaxWordLength]; 
}; 

/////////////////////////////////////////////////////////////////////////////
// CDictionaryObj command target

class CDictionaryObj : public CCmdTarget
{
	DECLARE_DYNCREATE(CDictionaryObj)

	CDictionaryObj();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
    BEGIN_INTERFACE_PART(Dictionary, IDictionary)
        INIT_INTERFACE_PART(CDictionary, Dictionary) 
        STDMETHOD(Initialize)(); 
        STDMETHOD(LoadLibrary)(LPOLESTR); 
        STDMETHOD(InsertWord)(LPOLESTR, LPOLESTR); 
        STDMETHOD(DeleteWord)(LPOLESTR); 
        STDMETHOD(LookupWord)(LPOLESTR, LPOLESTR*); 
        STDMETHOD(RestoreLibrary)(LPOLESTR); 
        STDMETHOD(FreeLibrary)(); 
    END_INTERFACE_PART(Dictionary)
        
    BEGIN_INTERFACE_PART(SpellCheck, ISpellCheck)
        INIT_INTERFACE_PART(CDictionary, SpellCheck) 
        STDMETHOD(CheckWord)(LPOLESTR, LPOLESTR*); 
    END_INTERFACE_PART(SpellCheck)

private:
    struct DictWord* m_pData; 
    int m_nWordNumber, m_nStructNumber; 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDictionaryObj)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDictionaryObj();

	// Generated message map functions
	//{{AFX_MSG(CDictionaryObj)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
    DECLARE_INTERFACE_MAP()
    DECLARE_OLECREATE(CDictionaryObj) 
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DICTIONARYOBJ_H__98369008_0AD1_4295_95B2_7AE7A8A1709B__INCLUDED_)
