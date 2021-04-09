// ShowDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Clean.h"
#include "ShowDlg.h"
#include "afxdialogex.h"


// CShowDlg 对话框

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


// CShowDlg 消息处理程序


void CShowDlg::OnBnClickedButton1()
{
	//弹出一个游览文件夹的对话框
	CString strPath = theApp.GetBrowseForFloder();
	if (strPath != _T(""))
	{
		//给列表添加路径
		m_lcShowPath.InsertItem(m_lcShowPath.GetItemCount(),strPath);
	}
}


void CShowDlg::OnBnClickedButton2()
{
	//遍历列表所有项
	for (int i = 0; i < m_lcShowPath.GetItemCount(); i++)
	{
		//判断当前这一项是不是选中的
		if (m_lcShowPath.GetCheck(i) == TRUE)
		{
			//删除这一项
			m_lcShowPath.DeleteItem(i);
			--i;
		}
	}
}


void CShowDlg::OnBnClickedButton3()
{
	//删除所有相
	m_lcShowPath.DeleteAllItems();
}


BOOL CShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//给m_lcShowPath设置复选按钮的风格
	m_lcShowPath.SetExtendedStyle(LVS_EX_CHECKBOXES);
	return TRUE;  // return TRUE unless you set the focus to a control

}
