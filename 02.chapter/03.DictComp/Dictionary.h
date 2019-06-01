
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "..\\includeex\\IDictionary.h"
#include "..\\includeex\\ISpellCheck.h"

#define MaxWordLength 128 

struct DictWord
{
    char wordForLang1[128]; 
    char wordForLang2[128]; 
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

    virtual BOOL _stdcall Initialize(); 
    virtual BOOL _stdcall LoadLibrary(String); 
    virtual BOOL _stdcall InsertWord(String, String);
    virtual void _stdcall DeleteWord(String); 
    virtual BOOL _stdcall LookupWord(String, String*); 
    virtual BOOL _stdcall RestoreLibrary(String); 
    virtual void _stdcall FreeLibrary(); 

    virtual BOOL _stdcall CheckWord(String, String*); 

private:
    struct DictWord* m_pData; 
    int m_nRef; 
    int m_nWordNumber, m_nStructNumber; 
}; 


#endif // __DICTIONARY_H__