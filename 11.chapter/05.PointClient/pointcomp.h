// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IPointObj wrapper class

class IPointObj : public COleDispatchDriver
{
public:
	IPointObj() {}		// Calls COleDispatchDriver default constructor
	IPointObj(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IPointObj(const IPointObj& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:
	long GetX();
	void SetX(long);
	long GetY();
	void SetY(long);

// Operations
public:
	void MoveTo(long newX, long newY);
};
