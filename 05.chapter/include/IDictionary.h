
#ifndef __I_DICTIONARY_H__
#define __I_DICTIONARY_H__

#include <unknwn.h> 

typedef unsigned short* String; 
class IDictionary : public IUnknown 
{
public:
    virtual HRESULT _stdcall Initialize() = 0; 
    virtual HRESULT _stdcall LoadLibrary(String) = 0; 
    virtual HRESULT _stdcall InsertWord(String, String) = 0;
    virtual HRESULT _stdcall DeleteWord(String) = 0; 
    virtual HRESULT _stdcall LookupWord(String, String*) = 0; 
    virtual HRESULT _stdcall RestoreLibrary(String) = 0; 
    virtual HRESULT _stdcall FreeLibrary() = 0; 
}; 

// {001A7733-AD05-4009-BF22-798BA9D52036}
static const IID IID_IDictionary = 
{ 0x1a7733, 0xad05, 0x4009, { 0xbf, 0x22, 0x79, 0x8b, 0xa9, 0xd5, 0x20, 0x36 } };

// {ACA2CA2A-0968-4b89-89F0-54072C2551F7}
static const CLSID CLSID_Dictionary = 
{ 0xaca2ca2a, 0x968, 0x4b89, { 0x89, 0xf0, 0x54, 0x7, 0x2c, 0x25, 0x51, 0xf7 } };


#endif // __I_DICTIONARY_H__