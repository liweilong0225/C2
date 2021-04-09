
// CleanDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Clean.h"
#include "CleanDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCleanDlg 对话框



CCleanDlg::CCleanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCleanDlg::IDD, pParent)
{
	m_bChangeWndSizeFlag = false;
	m_bIsChangeBmp = false;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCleanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_PICTURE,picture);
	DDX_Control(pDX, IDC_TAB2, m_tab);
}

BEGIN_MESSAGE_MAP(CCleanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_PICTURE, &CCleanDlg::OnStnClickedPicture)
END_MESSAGE_MAP()


// CCleanDlg 消息处理程序

BOOL CCleanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//--------------加载位图-------------
	m_hBitmap7 = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	m_hBitmap8 = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP2));

	//-------------插入标签项------------
	m_tab.InitTabCtrl();



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCleanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCleanDlg::OnPaint()
{
	//------------显示窗口的上半部分-------------
	if (m_bChangeWndSizeFlag == false)
	{
		RECT rect;
		this->GetWindowRect(&rect);
		rect.bottom -= 245;
		this->MoveWindow(&rect);
		m_bChangeWndSizeFlag = true;
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCleanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCleanDlg::OnStnClickedPicture()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_bIsChangeBmp == false)
		picture.SetBitmap(m_hBitmap8);
	else
		picture.SetBitmap(m_hBitmap7);
	m_bIsChangeBmp = !m_bIsChangeBmp;
}