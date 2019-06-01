

#ifndef __I_CLASSFACTORY_H__
#define __I_CLASSFACTORY_H__

#include "IMyUnknown.h" 

class IMyClassFactory : public IMyUnknown 
{
public:
    virtual HRESULT _stdcall CreateInstance(IUnknown* pUnknownOuter, 
        const IID& iid, void** ppv) = 0; 
    virtual HRESULT _stdcall LockServer(BOOL bLock) = 0; 
}; 

#endif // __I_CLASSFACTORY_H__