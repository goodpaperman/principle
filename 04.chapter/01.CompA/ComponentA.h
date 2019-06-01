
#ifndef __COMPONET_A_H__
#define __COMPONET_A_H__

#include "..\\include\\ISomeInterface.h"
#include "..\\include\\INondelegatingUnknown.h" 

class CA : public ISomeInterface, public INondelegatingUnknown 
{
public:
    CA(IUnknown* pUnknownOuter); 
    ~CA(); 
public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** ppv); 
    virtual ULONG _stdcall AddRef(); 
    virtual ULONG _stdcall Release(); 

    virtual void _stdcall SomeFunction(); 

    virtual HRESULT _stdcall NondelegatingQueryInterface(const IID& iid, void** ppv); 
    virtual ULONG _stdcall NondelegatingAddRef(); 
    virtual ULONG _stdcall NondelegatingRelease(); 

private:
    int m_nRef; 
    IUnknown* m_pUnknownOuter; 
}; 


#endif // __COMPONET_A_H__