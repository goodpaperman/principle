
#ifndef __COMPONET_B_H__
#define __COMPONET_B_H__

#include "..\\include\\ISomeInterface.h" 
#include "..\\include\\IOtherInterface.h"

class CB : public IOtherInterface, public ISomeInterface
{
public:
    CB(); 
    ~CB(); 
public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** pv); 
    virtual ULONG _stdcall AddRef(); 
    virtual ULONG _stdcall Release(); 

    virtual void _stdcall SomeFunction(); 
    virtual void _stdcall OtherFunction(); 
    HRESULT Init(); 

private:
    int m_nRef; 
    ISomeInterface* m_pSomeInterface; 
}; 

#endif // __COMPONET_B_H__