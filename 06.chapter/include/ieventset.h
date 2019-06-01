
#ifndef __I_EVENT_SET__
#define __I_EVENT_SET__	
	

interface IEventSet : public IUnknown
{
public:
    STDMETHOD(PropChanged)(long nInt) PURE;
};


// {428CAFF7-8B7D-4d16-B85C-52046E4D06EE}
static const IID IID_IEventSet = 
{ 0x428caff7, 0x8b7d, 0x4d16, { 0xb8, 0x5c, 0x52, 0x4, 0x6e, 0x4d, 0x6, 0xee } };

#endif