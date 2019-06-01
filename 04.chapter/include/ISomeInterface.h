
#ifndef __ISOMEINTERFACE_H__
#define __ISOMEINTERFACE_H__

#include <unknwn.h> 

interface ISomeInterface : public IUnknown
{
public: 
    virtual void _stdcall SomeFunction() = 0; 
}; 

// {5CB64498-E403-44c3-8432-26A59C37102C}
static const GUID IID_ISomeInterface = 
{ 0x5cb64498, 0xe403, 0x44c3, { 0x84, 0x32, 0x26, 0xa5, 0x9c, 0x37, 0x10, 0x2c } };

// {1C7E0B5C-E51C-479c-AA70-0F4B000A5141}
static const GUID CLSID_ComponentA = 
{ 0x1c7e0b5c, 0xe51c, 0x479c, { 0xaa, 0x70, 0xf, 0x4b, 0x0, 0xa, 0x51, 0x41 } };

#endif // __ISOMEINTERFACE_H__