
// CleanDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clean.h"
#include "CleanDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCleanDlg �Ի���



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


// CCleanDlg ��Ϣ�������

BOOL CCleanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	//--------------����λͼ-------------
	m_hBitmap7 = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
	m_hBitmap8 = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP2));

	//-------------�����ǩ��------------
	m_tab.InitTabCtrl();



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCleanDlg::OnPaint()
{
	//------------��ʾ���ڵ��ϰ벿��-------------
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
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCleanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCleanDlg::OnStnClickedPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_bIsChangeBmp == false)
		picture.SetBitmap(m_hBitmap8);
	else
		picture.SetBitmap(m_hBitmap7);
	m_bIsChangeBmp = !m_bIsChangeBmp;
}