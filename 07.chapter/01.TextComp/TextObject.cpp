// TextObject.cpp : implementation file
//

#include "stdafx.h"
#include "TextComp.h"
#include "TextObject.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTextObject

IMPLEMENT_DYNCREATE(CTextObject, CCmdTarget)

CTextObject::CTextObject()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
    m_pText = NULL; 
}

CTextObject::~CTextObject()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
    if(m_pText)
        delete[] m_pText; 

	AfxOleUnlockApp();
}


void CTextObject::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CTextObject, CCmdTarget)
	//{{AFX_MSG_MAP(CTextObject)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CTextObject, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CTextObject)
	DISP_PROPERTY_EX(CTextObject, "Text", GetText, SetText, VT_VARIANT)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ITextObject to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {AD945D34-2E40-4EEF-9172-496CA957F956}
static const IID IID_ITextObject =
{ 0xad945d34, 0x2e40, 0x4eef, { 0x91, 0x72, 0x49, 0x6c, 0xa9, 0x57, 0xf9, 0x56 } };

BEGIN_INTERFACE_MAP(CTextObject, CCmdTarget)
	INTERFACE_PART(CTextObject, IID_ITextObject, Dispatch)
    INTERFACE_PART(CTextObject, IID_IPersistStream, PersistStream) 
END_INTERFACE_MAP()

// {DB472D34-0EA9-4B17-8103-5458D7D72C50}
IMPLEMENT_OLECREATE(CTextObject, "Text.Object", 0xdb472d34, 0xea9, 0x4b17, 0x81, 0x3, 0x54, 0x58, 0xd7, 0xd7, 0x2c, 0x50)

/////////////////////////////////////////////////////////////////////////////
// CTextObject message handlers

VARIANT CTextObject::GetText() 
{
    //VARIANT vaResult;
    //VariantInit(&vaResult);
    //// TODO: Add your property handler here

    //return vaResult;
    return COleVariant(m_pText).Detach(); 
}

void CTextObject::SetText(const VARIANT FAR& newValue) 
{
	// TODO: Add your property handler here
    CString strTemp; 
    ASSERT(newValue.vt == VT_BSTR); 
    if(m_pText != NULL)
        delete[] m_pText; 

    strTemp = newValue.bstrVal; 
    m_pText = new char[strTemp.GetLength() + 1]; 
    strcpy(m_pText, strTemp); 
}


STDMETHODIMP_(ULONG) CTextObject::XPersistStream::AddRef()
{
    METHOD_PROLOGUE_(CTextObject, PersistStream) 
    return (ULONG)pThis->ExternalAddRef(); 
}

STDMETHODIMP_(ULONG) CTextObject::XPersistStream::Release()
{
    METHOD_PROLOGUE_(CTextObject, PersistStream)
    return (ULONG)pThis->ExternalRelease(); 
}

STDMETHODIMP CTextObject::XPersistStream::QueryInterface(REFIID iid, void** ppvObj)
{
    METHOD_PROLOGUE_(CTextObject, PersistStream)
    return pThis->ExternalQueryInterface(&iid, ppvObj); 
}

STDMETHODIMP CTextObject::XPersistStream::GetClassID(LPCLSID lpClassID)
{
    METHOD_PROLOGUE_(CTextObject, PersistStream) 
    *lpClassID = CTextObject::guid;
    return NOERROR; 
}

STDMETHODIMP CTextObject::XPersistStream::IsDirty()
{
    METHOD_PROLOGUE_(CTextObject, PersistStream) 
    return NOERROR; 
}

STDMETHODIMP CTextObject::XPersistStream::Load(LPSTREAM pStm)
{
    METHOD_PROLOGUE_(CTextObject, PersistStream) 
    if(pThis->m_pText != NULL)
        delete[] pThis->m_pText; 

    STATSTG statstg = { 0 } ; 
    VERIFY(pStm->Stat(&statstg, STATFLAG_NONAME) == NOERROR); 
    int nSize = statstg.cbSize.LowPart; 
    if(nSize > 0)
    {
        ULONG nLength = 0; 
        pThis->m_pText = new char[nSize]; 
        pStm->Read(pThis->m_pText, nSize, &nLength); 
    }

    return NOERROR; 
}

STDMETHODIMP CTextObject::XPersistStream::Save(LPSTREAM pStm, BOOL fClearDirty)
{
    METHOD_PROLOGUE_(CTextObject, PersistStream) 
    if(pThis->m_pText)
    {
        int nSize = strlen(pThis->m_pText) + 1; 
        pStm->Write(pThis->m_pText, nSize, NULL); 
    }

    return NOERROR; 
}

STDMETHODIMP CTextObject::XPersistStream::GetSizeMax(ULARGE_INTEGER* pcbSize)
{
    METHOD_PROLOGUE_(CTextObject, PersistStream)
    if(pThis->m_pText)
    {
        pcbSize->LowPart = strlen(pThis->m_pText) + 1; 
        pcbSize->HighPart = 0; 
    }

    return NOERROR; 
}