// SetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Clean.h"
#include "SetDlg.h"
#include "afxdialogex.h"


// CSetDlg 对话框

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


// CSetDlg 消息处理程序


BOOL CSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	combox.AddString(_T("默认目录"));
	combox.AddString(_T("请选择目录..."));
	combox.SelectString(-1,_T("默认目录"));

	return TRUE;  // return TRUE unless you set the focus to a control

}


void CSetDlg::OnCbnCloseupCombo1()
{
	//获取选择的项
	int index = combox.GetCurSel();
	if (index != CB_ERR)
	{
		//判断这一项是不是请选择目录这一项
		if (index == combox.GetCount()-1)
		{
			//弹出一个游览文件夹的对话框
			CString strPath = theApp.GetBrowseForFloder();
			if (strPath != _T(""))
			{
				combox.AddString(strPath);
				combox.SelectString(-1,strPath);
			}
			else
			{
				combox.SelectString(-1,_T("默认目录"));
			}
		}
	}
}


void CSetDlg::OnBnClickedButton2()
{
	//删除所有相
	m_tree.DeleteAllItems();

	//获取combo上面的文本
	CString strPath;
	combox.GetWindowText(strPath);
	if(strPath == _T("默认目录"))
		strPath = _T("c:\\");
	//给树控件插入
	HTREEITEM hRootItem = m_tree.InsertItem(strPath);
	//在这一项下面插入一层
	m_tree.InsertOnePage(strPath,hRootItem);
}
