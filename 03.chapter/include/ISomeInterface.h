
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

// {7EFC9282-E056-41fe-81C0-7AD089167C89}
static const GUID CLSID_ComponentB = 
{ 0x7efc9282, 0xe056, 0x41fe, { 0x81, 0xc0, 0x7a, 0xd0, 0x89, 0x16, 0x7c, 0x89 } };

#endif // __ISOMEINTERFACE_H__