// Dictionary.h : Declaration of the CDictionary

#ifndef __DICTIONARY_H_
#define __DICTIONARY_H_

#include "resource.h"       // main symbols
#define MaxWordLength 32

struct DictWord
{
    char wordForLang1[MaxWordLength]; 
    char wordForLang2[MaxWordLength]; 
}; 


/////////////////////////////////////////////////////////////////////////////
// CDictionary
class ATL_NO_VTABLE CDictionary : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDictionary, &CLSID_CComDictionary>,
	public IDictionary, 
    public ISpellCheck
{
public:
	CDictionary()
	{
	}
// IDictionary
public:
	STDMETHOD(FreeLibrary)(void);
	STDMETHOD(RestoreLibrary)(LPOLESTR);
	STDMETHOD(LookupWord)(LPOLESTR, LPOLESTR*);
	STDMETHOD(DeleteWord)(LPOLESTR);
	STDMETHOD(InsertWord)(LPOLESTR, LPOLESTR);
	STDMETHOD(LoadLibrary)(LPOLESTR);
	STDMETHOD(Initialize)(void);

    STDMETHOD(CheckWord)(LPOLESTR, LPOLESTR*); 
    
DECLARE_REGISTRY_RESOURCEID(IDR_DICTIONARY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDictionary)
	COM_INTERFACE_ENTRY(IDictionary)
    COM_INTERFACE_ENTRY(ISpellCheck) 
END_COM_MAP()

private:
    struct DictWord* m_pData; 
    int m_nWordNumber, m_nStructNumber; 
};

#endif //__DICTIONARY_H_
