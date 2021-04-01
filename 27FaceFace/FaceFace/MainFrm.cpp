
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	//ɾ���˵�
	//this->SetMenu(0);
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	//�޸�λ�úʹ�С
	cs.cx = 300;
	cs.cy = 300;
	
	int CX =::GetSystemMetrics(SM_CXSCREEN);//��ȡϵͳ�ĳߴ���Ϣ,��ȡ��Ļ��С
	int CY =::GetSystemMetrics(SM_CYSCREEN);
	
	cs.x = (CX-cs.cx)/2;
	cs.y = (CY-cs.cy)/2;

	//WS_OVERLAPPEDWINDOW
	//ȥ�������С����ť
	cs.style = cs.style^WS_MINIMIZEBOX;
	cs.style = cs.style^WS_MAXIMIZEBOX;

	//ȥ���������ڴ�С
	cs.style = cs.style^WS_THICKFRAME;

	//ȥ������,ȥ��FWS_ADDTOTITLE��ʽ�ſ����޸ı���
	cs.style = cs.style^FWS_ADDTOTITLE;
	cs.lpszName = _T("����");

	//ȥ���߿�
	/*cs.style = WS_POPUP;*/

	//�޸Ĺ�� ͼ�� ����
	//HICON hIcon = ::LoadIcon(theApp.m_hInstance,MAKEINTRESOURCE(IDI_ICON1));
	HICON hIcon = theApp.LoadIcon(IDI_ICON1);//MFC���ع��
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW,0,0,hIcon);
	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

