// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "pointcomp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IPointObj properties

long IPointObj::GetX()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void IPointObj::SetX(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

long IPointObj::GetY()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void IPointObj::SetY(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IPointObj operations

void IPointObj::MoveTo(long newX, long newY)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 newX, newY);
}
