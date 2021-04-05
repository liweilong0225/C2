
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "screenshot.h"

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
	ON_COMMAND(ID_BUTTON32771,&CMainFrame::OnToolBarQuit)
	ON_COMMAND_RANGE(ID_BUTTON32774,ID_BUTTON32778,CMainFrame::OnToolBarChangeDrawTyle)
	ON_COMMAND(ID_ACCELERATOR32780, &CMainFrame::OnAccelerator32780)
	ON_COMMAND(ID_BUTTON32787,&CMainFrame::OnFull)
	ON_COMMAND(ID_BUTTON32792,&CMainFrame::OnSave)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

void CMainFrame::OnSave()
{
	//*.*代表所有类型的所有文件；
	static TCHAR BASED_CODE szFilter[] = 
	_T("jpg(*.jpg)|*.jpg|")
   _T("bmp(*.bmp)|*.bmp|")
   _T("png(*.png)|*.png|");


	CFileDialog dlg(FALSE,_T("jpg"),_T("未命名"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if (dlg.DoModal() == IDOK)
	{
		//获取路径
		CString strPath = dlg.GetPathName();
		//保存
		CImage image;
		image.Attach((HBITMAP)(sk.top()->m_hObject));//关联一个图片
		if(image.Save(strPath) == S_OK)	//保存
			MessageBox(_T("保存成功"));
		else
			MessageBox(_T("保存失败"));
		image.Detach();//分离图片
	}
}
void CMainFrame::OnFull()
{
	//填充
	m_nDrawType = FULL;
}
void CMainFrame::OnToolBarChangeDrawTyle(UINT uID)
{
	//改变画的类型
	m_nDrawType = uID-ID_BUTTON32774;
}
CMainFrame::CMainFrame()
{
	m_nDrawType = CURVE;
	//-------------获取屏幕的大小-------------
	m_nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	m_nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);
	//-------------获取屏幕的大小-------------

	// -----------1.获取桌面的图片------------
	//获取桌面DC
	CWindowDC dcDesktop(GetDesktopWindow());

	CDC cdc;
	cdc.CreateCompatibleDC(&dcDesktop);
	CBitmap* bitmap = new CBitmap;
	bitmap->CreateCompatibleBitmap(&dcDesktop,m_nScreenCX,m_nScreenCY);
	cdc.SelectObject(bitmap);

	cdc.BitBlt(0,0,m_nScreenCX,m_nScreenCY,&dcDesktop,0,0,SRCCOPY);
	// -----------1.获取桌面的图片------------

	//------------保存到栈里-----------------
	sk.push(bitmap);
	//------------保存到栈里-----------------

}

CMainFrame::~CMainFrame()
{
	//删除栈中所有的图片
	while (sk.empty() == false)
	{
		//删除栈顶里的东西
		delete sk.top();
		//删除节点
		sk.pop();
	}
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	} 

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//------------设置一个空菜单--------------
	this->SetMenu(0);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	 
	//去掉边框
	cs.style = WS_POPUP;
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

void CMainFrame::OnToolBarQuit()
{
	//给主窗口发送以一个关闭的消息
	this->PostMessage(WM_CLOSE);
}

void CMainFrame::OnAccelerator32780()
{
	if (sk.size()>1)
	{
		//删除栈顶
		delete sk.top();//删除内容
		sk.pop();//删除节点
		//通知视图重绘
		GetActiveView()->SendMessage(WM_PAINT);//GetActiveView获取视图对象
	}
}
