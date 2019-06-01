
#ifndef __COMPONET_A_H__
#define __COMPONET_A_H__

#include "..\\include\\ISomeInterface.h"

class CA : public ISomeInterface
{
public:
    CA(); 
    ~CA(); 
public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** pv); 
    virtual ULONG _stdcall AddRef(); 
    virtual ULONG _stdcall Release(); 

    virtual void _stdcall SomeFunction(); 

private:
    int m_nRef; 
}; 


#endif // __COMPONET_A_H__