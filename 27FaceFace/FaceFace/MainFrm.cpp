
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "FaceFace.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//删掉菜单
	//this->SetMenu(0);
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	
	//修改位置和大小
	cs.cx = 300;
	cs.cy = 300;
	
	int CX =::GetSystemMetrics(SM_CXSCREEN);//获取系统的尺寸信息,获取屏幕大小
	int CY =::GetSystemMetrics(SM_CYSCREEN);
	
	cs.x = (CX-cs.cx)/2;
	cs.y = (CY-cs.cy)/2;

	//WS_OVERLAPPEDWINDOW
	//去掉最大化最小化按钮
	cs.style = cs.style^WS_MINIMIZEBOX;
	cs.style = cs.style^WS_MAXIMIZEBOX;

	//去掉调整窗口大小
	cs.style = cs.style^WS_THICKFRAME;

	//去掉标题,去掉FWS_ADDTOTITLE样式才可以修改标题
	cs.style = cs.style^FWS_ADDTOTITLE;
	cs.lpszName = _T("窗口");

	//去掉边框
	/*cs.style = WS_POPUP;*/

	//修改光标 图标 背景
	//HICON hIcon = ::LoadIcon(theApp.m_hInstance,MAKEINTRESOURCE(IDI_ICON1));
	HICON hIcon = theApp.LoadIcon(IDI_ICON1);//MFC加载光标
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,0,0,hIcon);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

