// ShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clean.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// CShowDlg �Ի���

IMPLEMENT_DYNAMIC(CShowDlg, CDialogEx)

CShowDlg::CShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowDlg::IDD, pParent)
{

}

CShowDlg::~CShowDlg()
{
}

void CShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lcShowPath);
}


BEGIN_MESSAGE_MAP(CShowDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShowDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShowDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShowDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CShowDlg ��Ϣ�������


void CShowDlg::OnBnClickedButton1()
{
	//����һ�������ļ��еĶԻ���
	CString strPath = theApp.GetBrowseForFloder();
	if (strPath != _T(""))
	{
		//���б����·��
		m_lcShowPath.InsertItem(m_lcShowPath.GetItemCount(),strPath);
	}
}


void CShowDlg::OnBnClickedButton2()
{
	//�����б�������
	for (int i = 0; i < m_lcShowPath.GetItemCount(); i++)
	{
		//�жϵ�ǰ��һ���ǲ���ѡ�е�
		if (m_lcShowPath.GetCheck(i) == TRUE)
		{
			//ɾ����һ��
			m_lcShowPath.DeleteItem(i);
			--i;
		}
	}
}


void CShowDlg::OnBnClickedButton3()
{
	//ɾ��������
	m_lcShowPath.DeleteAllItems();
}


BOOL CShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//��m_lcShowPath���ø�ѡ��ť�ķ��
	m_lcShowPath.SetExtendedStyle(LVS_EX_CHECKBOXES);
	return TRUE;  // return TRUE unless you set the focus to a control

}
