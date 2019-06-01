
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "..\\includeex\\IDictionary.h"
#include "..\\includeex\\ISpellCheck.h"

#define MaxWordLength 32

struct DictWord
{
    char wordForLang1[MaxWordLength]; 
    char wordForLang2[MaxWordLength]; 
}; 

class CDictionary : public IDictionary, public ISpellCheck 
{
public:
    CDictionary(); 
    ~CDictionary(); 
public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** pv); 
    virtual ULONG _stdcall AddRef(); 
    virtual ULONG _stdcall Release(); 

    virtual HRESULT _stdcall Initialize(); 
    virtual HRESULT _stdcall LoadLibrary(String); 
    virtual HRESULT _stdcall InsertWord(String, String);
    virtual HRESULT _stdcall DeleteWord(String); 
    virtual HRESULT _stdcall LookupWord(String, String); 
    virtual HRESULT _stdcall RestoreLibrary(String); 
    virtual HRESULT _stdcall FreeLibrary(); 

    virtual HRESULT _stdcall CheckWord(String, String); 

private:
    struct DictWord* m_pData; 
    int m_nRef; 
    int m_nWordNumber, m_nStructNumber; 
}; 


#endif // __DICTIONARY_H__