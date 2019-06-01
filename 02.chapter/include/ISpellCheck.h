
#ifndef __I_SPELLCHECK_H__
#define __I_SPELLCHECK_H__

#include "IMyUnknown.h" 

class ISpellCheck : public IMyUnknown 
{
public:
    virtual BOOL _stdcall CheckWord(String, String*) = 0; 
}; 

// {20A839D6-125D-43a4-BA89-09DB6769DDD9}
static const IID IID_ISpellCheck = 
{ 0x20a839d6, 0x125d, 0x43a4, { 0xba, 0x89, 0x9, 0xdb, 0x67, 0x69, 0xdd, 0xd9 } };

#endif // __I_SPELLCHECK_H__