// SetDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clean.h"
#include "SetDlg.h"
#include "afxdialogex.h"


// CSetDlg �Ի���

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetDlg::IDD, pParent)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, combox);
	DDX_Control(pDX, IDC_TREE1, m_tree);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)
	ON_CBN_CLOSEUP(IDC_COMBO1, &CSetDlg::OnCbnCloseupCombo1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSetDlg ��Ϣ�������


BOOL CSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	combox.AddString(_T("Ĭ��Ŀ¼"));
	combox.AddString(_T("��ѡ��Ŀ¼..."));
	combox.SelectString(-1,_T("Ĭ��Ŀ¼"));

	return TRUE;  // return TRUE unless you set the focus to a control

}


void CSetDlg::OnCbnCloseupCombo1()
{
	//��ȡѡ�����
	int index = combox.GetCurSel();
	if (index != CB_ERR)
	{
		//�ж���һ���ǲ�����ѡ��Ŀ¼��һ��
		if (index == combox.GetCount()-1)
		{
			//����һ�������ļ��еĶԻ���
			CString strPath = theApp.GetBrowseForFloder();
			if (strPath != _T(""))
			{
				combox.AddString(strPath);
				combox.SelectString(-1,strPath);
			}
			else
			{
				combox.SelectString(-1,_T("Ĭ��Ŀ¼"));
			}
		}
	}
}


void CSetDlg::OnBnClickedButton2()
{
	//ɾ��������
	m_tree.DeleteAllItems();

	//��ȡcombo������ı�
	CString strPath;
	combox.GetWindowText(strPath);
	if(strPath == _T("Ĭ��Ŀ¼"))
		strPath = _T("c:\\");
	//�����ؼ�����
	HTREEITEM hRootItem = m_tree.InsertItem(strPath);
	//����һ���������һ��
	m_tree.InsertOnePage(strPath,hRootItem);
}
