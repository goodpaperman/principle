// DocFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DocFile.h"
#include "DocFileDlg.h"
#include "TextComp.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CLSID g_clsid = CLSID_NULL; 
size_t g_nLevel = 0; 

/////////////////////////////////////////////////////////////////////////////
// CDocFileDlg dialog

CDocFileDlg::CDocFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDocFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDocFileDlg)
	m_strInput = _T("");
	m_strOutput = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDocFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDocFileDlg)
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
	DDX_Text(pDX, IDC_EDIT_OUTPUT, m_strOutput);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDocFileDlg, CDialog)
	//{{AFX_MSG_MAP(CDocFileDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INPUT, OnBtnInput)
	ON_BN_CLICKED(IDC_BTN_OUTPUT, OnBtnOutput)
	ON_BN_CLICKED(IDC_BTN_READ, OnBtnRead)
	ON_BN_CLICKED(IDC_BTN_WRITE, OnBtnWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDocFileDlg message handlers

BOOL CDocFileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	if(FAILED(CLSIDFromProgID(L"Text.Object", &g_clsid)))
    {
        g_clsid = CLSID_NULL; 
        TRACE("cannot get class id from \"Text.Object\"\n"); 
    }

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDocFileDlg::OnPaint() 
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
HCURSOR CDocFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDocFileDlg::OnBtnInput() 
{
	// TODO: Add your control notification handler code here
    CFileDialog dlg(TRUE); 
    if(dlg.DoModal() == IDOK)
    {
        m_strInput = dlg.GetPathName(); 
        int n = m_strInput.ReverseFind('\\'); 
        if(n > 0)
            m_strInput = m_strInput.Left(n+1); 
        UpdateData(FALSE); 
    }
}

void CDocFileDlg::OnBtnOutput() 
{
	// TODO: Add your control notification handler code here
    CFileDialog dlg(FALSE); 
    if(dlg.DoModal() == IDOK)
    {
        m_strOutput = dlg.GetPathName(); 
        UpdateData(FALSE); 
    }
}

void CDocFileDlg::OnBtnRead() 
{
	// TODO: Add your control notification handler code here
	if(g_clsid == CLSID_NULL)
        return; 
	
    UpdateData(TRUE); 
    USES_CONVERSION; 
    g_nLevel = 0; 
    LPSTORAGE pStgRoot = NULL; 
    if(FAILED(::StgOpenStorage(T2OLE(m_strOutput), 
        NULL, STGM_READ | STGM_SHARE_EXCLUSIVE, 
        NULL, 0, &pStgRoot)))
    {
        AfxMessageBox("Storage file not available or not readable"); 
    }
    else
    {
        ReadStorage(pStgRoot); 
        pStgRoot->Release(); 
    }

    AfxMessageBox("Read Completed."); 
}

void CDocFileDlg::ReadStorage(LPSTORAGE pStg)
{
    g_nLevel ++; 
    LPENUMSTATSTG pEnum = NULL; 
    if(FAILED(pStg->EnumElements(0, NULL, 0, &pEnum)))
    {
        return; 
    }

    STATSTG statstg = { 0 }; 
    while(pEnum->Next(1, &statstg, NULL) == NOERROR)
    {
        if(statstg.type == STGTY_STORAGE)
        {
            LPSTORAGE pSubStg = NULL; 
            if(SUCCEEDED(pStg->OpenStorage(statstg.pwcsName, 
                NULL, STGM_READ | STGM_SHARE_EXCLUSIVE, 
                NULL, 0, &pSubStg)))
            {
                ReadStorage(pSubStg); 
                pSubStg->Release(); 
            }
        }
        else if(statstg.type == STGTY_STREAM)
        {
            LPSTREAM pStream = NULL; 
            if(SUCCEEDED(pStg->OpenStream(statstg.pwcsName, 
                NULL, STGM_READ | STGM_SHARE_EXCLUSIVE, 
                0, &pStream)))
            {
                ITextObject text; 
                if(text.CreateDispatch(g_clsid))
                {
                    LPPERSISTSTREAM pPersistStream = NULL; 
                    if(SUCCEEDED(text.m_lpDispatch->QueryInterface(IID_IPersistStream, 
                        (void**)&pPersistStream)))
                    {
                        pPersistStream->Load(pStream); 
                        pPersistStream->Release(); 
                        COleVariant va = text.GetText(); 
                        CString str = va.bstrVal; 
                        TRACE("%s\n", str); 
                    }
                }

                pStream->Release(); 
            }
        }

        CoTaskMemFree(statstg.pwcsName); 
    }

    pEnum->Release(); 
    g_nLevel --; 
}

void CDocFileDlg::OnBtnWrite() 
{
	// TODO: Add your control notification handler code here
	if(g_clsid == CLSID_NULL)
        return; 
	
    UpdateData(TRUE); 
    USES_CONVERSION; 
    g_nLevel = 0; 
    LPSTORAGE pStgRoot = NULL; 
    if(FAILED(::StgCreateDocfile(T2OLE(m_strOutput), 
        STGM_READWRITE | STGM_SHARE_EXCLUSIVE | STGM_CREATE, 
        0, &pStgRoot)))
    {
        AfxMessageBox("Create DocFile Failed!"); 
        return; 
    }

    if(m_strInput.GetLength() > 0 && m_strInput[m_strInput.GetLength()-1] != '\\')
        m_strInput += "\\"; 

    ReadDirectory(m_strInput, pStgRoot); 
    pStgRoot->Release(); 
    AfxMessageBox("Write Component File Completed."); 
}

void CDocFileDlg::ReadDirectory(const char* szPath, LPSTORAGE pStg)
{
    USES_CONVERSION; 
    char szNewPath[MAX_PATH] = { 0 }; 
    strcpy(szNewPath, szPath); 
    strcat(szNewPath, "*.*"); 

    g_nLevel ++; 
    WIN32_FIND_DATA fd = { 0 }; 
    HANDLE h = FindFirstFile(szNewPath, &fd); 
    if(h == INVALID_HANDLE_VALUE)
        return; 

    do
    {
        if(strcmp(fd.cFileName, ".") == 0 ||
            strcmp(fd.cFileName, "..") == 0)
            continue; 

        if(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            strcpy(szNewPath, szPath); 
            strcat(szNewPath, fd.cFileName); 
            strcat(szNewPath, "\\"); 

            LPSTORAGE pSubStg = NULL; 
            char szStorageName[32] = { 0 }; 
            strcpy(szStorageName, fd.cFileName); 
            szStorageName[31] = 0; 
            TRACE("%d -- sStorage = %s\n", (g_nLevel - 1) * 4, szStorageName); 
            VERIFY( SUCCEEDED(pStg->CreateStorage(T2OLE(szStorageName), 
                STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 
                0, 0, &pSubStg))); 
            ASSERT(pSubStg != NULL); 
            ReadDirectory(szNewPath, pSubStg); 
            pSubStg->Release(); 
        }
        else 
        {
            char* pch = strrchr(fd.cFileName, '.'); 
            if(pch != NULL && 
               ( stricmp(pch, ".txt") == 0 ||
                 stricmp(pch, ".c") == 0 || 
                 stricmp(pch, ".cpp") == 0 || 
                 stricmp(pch, ".h") == 0))
            {
                char szStreamName[32] = { 0 }; 
                strcpy(szStreamName, fd.cFileName); 
                szStreamName[31] = 0; 
                TRACE("%d -- sStream = %s\n", (g_nLevel - 1) * 4, szStreamName); 

                char szData[512] = { 0 }; 
                strcpy(szNewPath, szPath); 
                strcat(szNewPath, szStreamName); 
                CStdioFile file(szNewPath, CFile::modeRead); 
                if(file.ReadString(szData, 511))
                {
                    TRACE("%s\n", szData); 
                    LPSTREAM pStream = NULL; 
                    VERIFY(SUCCEEDED(pStg->CreateStream(T2OLE(szStreamName), 
                        STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 
                        0, 0, &pStream))); 
                    ASSERT(pStream != NULL); 

                    ITextObject text; 
                    LPPERSISTSTREAM pPersistStream = NULL; 
                    VERIFY(text.CreateDispatch(g_clsid)); 
                    text.SetText(COleVariant(szData)); 
                    if(text.m_lpDispatch)
                    {
                        text.m_lpDispatch->QueryInterface(IID_IPersistStream, 
                            (void**)&pPersistStream); 
                        if(pPersistStream != NULL)
                        {
                            pPersistStream->Save(pStream, TRUE); 
                            pPersistStream->Release(); 
                        }
                    }

                    pStream->Release(); 
                }
            }
        }
    }while(::FindNextFile(h, &fd)); 

    g_nLevel --; 
}