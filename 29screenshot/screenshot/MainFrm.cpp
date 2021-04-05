
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

void CMainFrame::OnSave()
{
	//*.*�����������͵������ļ���
	static TCHAR BASED_CODE szFilter[] = 
	_T("jpg(*.jpg)|*.jpg|")
   _T("bmp(*.bmp)|*.bmp|")
   _T("png(*.png)|*.png|");


	CFileDialog dlg(FALSE,_T("jpg"),_T("δ����"),OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if (dlg.DoModal() == IDOK)
	{
		//��ȡ·��
		CString strPath = dlg.GetPathName();
		//����
		CImage image;
		image.Attach((HBITMAP)(sk.top()->m_hObject));//����һ��ͼƬ
		if(image.Save(strPath) == S_OK)	//����
			MessageBox(_T("����ɹ�"));
		else
			MessageBox(_T("����ʧ��"));
		image.Detach();//����ͼƬ
	}
}
void CMainFrame::OnFull()
{
	//���
	m_nDrawType = FULL;
}
void CMainFrame::OnToolBarChangeDrawTyle(UINT uID)
{
	//�ı仭������
	m_nDrawType = uID-ID_BUTTON32774;
}
CMainFrame::CMainFrame()
{
	m_nDrawType = CURVE;
	//-------------��ȡ��Ļ�Ĵ�С-------------
	m_nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	m_nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);
	//-------------��ȡ��Ļ�Ĵ�С-------------

	// -----------1.��ȡ�����ͼƬ------------
	//��ȡ����DC
	CWindowDC dcDesktop(GetDesktopWindow());

	CDC cdc;
	cdc.CreateCompatibleDC(&dcDesktop);
	CBitmap* bitmap = new CBitmap;
	bitmap->CreateCompatibleBitmap(&dcDesktop,m_nScreenCX,m_nScreenCY);
	cdc.SelectObject(bitmap);

	cdc.BitBlt(0,0,m_nScreenCX,m_nScreenCY,&dcDesktop,0,0,SRCCOPY);
	// -----------1.��ȡ�����ͼƬ------------

	//------------���浽ջ��-----------------
	sk.push(bitmap);
	//------------���浽ջ��-----------------

}

CMainFrame::~CMainFrame()
{
	//ɾ��ջ�����е�ͼƬ
	while (sk.empty() == false)
	{
		//ɾ��ջ����Ķ���
		delete sk.top();
		//ɾ���ڵ�
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	} 

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//------------����һ���ղ˵�--------------
	this->SetMenu(0);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	 
	//ȥ���߿�
	cs.style = WS_POPUP;
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

void CMainFrame::OnToolBarQuit()
{
	//�������ڷ�����һ���رյ���Ϣ
	this->PostMessage(WM_CLOSE);
}

void CMainFrame::OnAccelerator32780()
{
	if (sk.size()>1)
	{
		//ɾ��ջ��
		delete sk.top();//ɾ������
		sk.pop();//ɾ���ڵ�
		//֪ͨ��ͼ�ػ�
		GetActiveView()->SendMessage(WM_PAINT);//GetActiveView��ȡ��ͼ����
	}
}
