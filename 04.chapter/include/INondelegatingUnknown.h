
#ifndef __I_NONDELEGATING_UNKNOWN_H__
#define __I_NONDELEGATING_UNKNOWN_H__

interface INondelegatingUnknown
{
public:    
    virtual HRESULT _stdcall NondelegatingQueryInterface(const IID& iid, void** pv) = 0; 
    virtual ULONG _stdcall NondelegatingAddRef() = 0; 
    virtual ULONG _stdcall NondelegatingRelease() = 0; 
}; 

#endif // __I_NONDELEGATING_UNKNOWN_H__