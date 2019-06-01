
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <unknwn.h>  

class CDictionaryFactory : public IClassFactory
{
public:
    CDictionaryFactory(); 
    ~CDictionaryFactory(); 

    HRESULT _stdcall QueryInterface(const IID& iid, void** ppv); 
    ULONG _stdcall AddRef(); 
    ULONG _stdcall Release(); 

    HRESULT _stdcall CreateInstance(IUnknown* pOuter, const IID& iid, void** ppv); 
    HRESULT _stdcall LockServer(BOOL bLock); 

public:
    static BOOL CanUnloadNow(); 
    static BOOL RegisterFactory(); 
    static BOOL UnregisterFactory(); 
    static DWORD dwRegister; 
    static CDictionaryFactory* theFactory; 

protected:
    ULONG m_nRef; 
}; 

#endif // __FACTORY_H__