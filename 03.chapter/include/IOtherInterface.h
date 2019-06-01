
#ifndef __IOTHERINTERFACE_H__
#define __IOTHERINTERFACE_H__

interface IOtherInterface : public IUnknown
{
public:
    virtual void _stdcall OtherFunction() = 0; 
}; 

// {51843551-A17D-4c38-BEC1-289498037F8A}
static const GUID IID_IOtherInterface = 
{ 0x51843551, 0xa17d, 0x4c38, { 0xbe, 0xc1, 0x28, 0x94, 0x98, 0x3, 0x7f, 0x8a } };

#endif // __IOTHERINTERFACE_H__