
#ifndef __I_MY_UNKNOWN_H__
#define __I_MY_UNKNOWN_H__

typedef unsigned short* String; 

class IMyUnknown
{
public:
    virtual HRESULT _stdcall QueryInterface(const IID& iid, void** pv) = 0; 
    virtual ULONG _stdcall AddRef() = 0; 
    virtual ULONG _stdcall Release() = 0; 
}; 

#endif // __I_MY_UNKNOWN_H__