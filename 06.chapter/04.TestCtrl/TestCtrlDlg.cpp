// TestCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestCtrl.h"
#include "TestCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// {F1C14DD3-0351-4002-8425-87E2AE8203D6}
static const IID IID_ISourceObj =
{ 0xf1c14dd3, 0x351, 0x4002, { 0x84, 0x25, 0x87, 0xe2, 0xae, 0x82, 0x3, 0xd6 } };

/////////////////////////////////////////////////////////////////////////////
// CTestCtrlDlg dialog

CTestCtrlDlg::CTestCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestCtrlDlg)
	m_property = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    
    m_dwCookie = 0; 
    m_pDispatch = NULL; 
    
	GUID sourceobjCLSID; 
    HRESULT hRes = CLSIDFromProgID(L"SourceComp.SourceObj", &sourceobjCLSID); 
    if(FAILED(hRes))
        return; 

    hRes = CoCreateInstance(sourceobjCLSID, NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&m_pDispatch); 
    if(FAILED(hRes))
        return; 
}

CTestCtrlDlg::~CTestCtrlDlg()
{
    if(m_pDispatch)
    {
        if(m_dwCookie)
            OnBtnDisconn(); 

        m_pDispatch->Release(); 
    }
}

void CTestCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestCtrlDlg)
	DDX_Text(pDX, IDC_EDIT_PROP, m_property);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CTestCtrlDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BTN_CONN, OnBtnConn)
	ON_BN_CLICKED(ID_BTN_DISCONN, OnBtnDisconn)
	ON_BN_CLICKED(ID_BTN_SETPROP, OnBtnSetprop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCtrlDlg message handlers

BOOL CTestCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestCtrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestCtrlDlg::OnBtnConn() 
{
	// TODO: Add your control notification handler code here
    if(m_dwCookie)
        return; 

    LPCONNECTIONPOINTCONTAINER pContainer = NULL; 
    if(m_pDispatch && 
        SUCCEEDED(m_pDispatch->QueryInterface(IID_IConnectionPointContainer, (LPVOID*)&pContainer)))
    {
        LPCONNECTIONPOINT pPt = NULL; 
        DWORD dwCookie = 0; 
        if(SUCCEEDED(pContainer->FindConnectionPoint(IID_ISourceObj, &pPt)))
        {
            pPt->Advise(&m_xEventSink, &dwCookie); 
            m_dwCookie = dwCookie; 
            pPt->Release(); 

            SetDlgItemText(IDC_STATIC_STATE, "Connected"); 
        }

        pContainer->Release(); 
        m_dwCookie = dwCookie; 
    }
}

void CTestCtrlDlg::OnBtnDisconn() 
{
	// TODO: Add your control notification handler code here
	if(m_dwCookie == 0)
        return; 

    LPCONNECTIONPOINTCONTAINER pContainer = NULL; 
    if(m_pDispatch && 
        SUCCEEDED(m_pDispatch->QueryInterface(IID_IConnectionPointContainer, (LPVOID*)&pContainer)))
    {
        LPCONNECTIONPOINT pPt = NULL; 
        if(SUCCEEDED(pContainer->FindConnectionPoint(IID_ISourceObj, &pPt)))
        {
            pPt->Unadvise(m_dwCookie); 
            m_dwCookie = 0; 
            pPt->Release(); 

            SetDlgItemText(IDC_STATIC_STATE, "Disconnected"); 
        }

        pContainer->Release(); 
    }
}

void CTestCtrlDlg::OnBtnSetprop() 
{
	// TODO: Add your control notification handler code here
	if(!UpdateData(TRUE))
        return; 

    COleDispatchDriver driver; 
    driver.AttachDispatch(m_pDispatch, FALSE); 
    TRY
        driver.SetProperty(0x01, VT_I4, m_property); 
    END_TRY 
    driver.DetachDispatch(); 
}


STDMETHODIMP_(ULONG) CTestCtrlDlg::XEventSink::AddRef()
{
    return 1; 
}

STDMETHODIMP_(ULONG) CTestCtrlDlg::XEventSink::Release()
{
    return 0; 
}

STDMETHODIMP CTestCtrlDlg::XEventSink::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
    METHOD_PROLOGUE_EX_(CTestCtrlDlg, EventSink)
    if(IsEqualIID(iid, IID_IUnknown) || 
        IsEqualIID(iid, IID_IDispatch) || 
        IsEqualIID(iid, IID_ISourceObj))
    {
        *ppvObj = this; 
        AddRef(); 
        return S_OK; 
    }
    else 
        return E_NOINTERFACE; 
}

STDMETHODIMP CTestCtrlDlg::XEventSink::GetTypeInfoCount(unsigned int*)
{
    return E_NOTIMPL; 
}

STDMETHODIMP CTestCtrlDlg::XEventSink::GetTypeInfo(unsigned int, LCID, ITypeInfo**)
{
    return E_NOTIMPL; 
}

STDMETHODIMP CTestCtrlDlg::XEventSink::GetIDsOfNames(REFIID, LPOLESTR*, unsigned int, LCID, DISPID*)
{
    return E_NOTIMPL; 
}

STDMETHODIMP CTestCtrlDlg::XEventSink::Invoke(DISPID dispid, REFIID, LCID, unsigned short wFlag, 
                                              DISPPARAMS* pDispParams, VARIANT* pvarResult, 
                                              EXCEPINFO* pExcepInfo, unsigned int* puArgError)
{
    if(dispid == 0)
    {
        CString str; 
        str.Format("The Property has been changed to %d!", pDispParams->rgvarg->lVal); 
        AfxMessageBox(str); 
    }
    else
    {
        AfxMessageBox("I don't known the event!"); 
    }

    return S_OK; 
}
