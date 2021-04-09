// ListCtrlShowPath.cpp : 实现文件
//

#include "stdafx.h"
#include "Clean.h"
#include "ListCtrlShowPath.h"


// CListCtrlShowPath

IMPLEMENT_DYNAMIC(CListCtrlShowPath, CListCtrl)

CListCtrlShowPath::CListCtrlShowPath()
{
	//加载菜单
	menu.LoadMenu(IDR_MENU1);
}

CListCtrlShowPath::~CListCtrlShowPath()
{
}


BEGIN_MESSAGE_MAP(CListCtrlShowPath, CListCtrl)
	ON_NOTIFY_REFLECT(NM_RCLICK, &CListCtrlShowPath::OnNMRClick)
	ON_COMMAND(ID_32771, &CListCtrlShowPath::On32771)
	ON_COMMAND(ID_32772, &CListCtrlShowPath::On32772)
	ON_COMMAND(ID_32773, &CListCtrlShowPath::On32773)
	ON_COMMAND(ID_32774, &CListCtrlShowPath::On32774)
END_MESSAGE_MAP()



// CListCtrlShowPath 消息处理程序




void CListCtrlShowPath::OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	POINT point;
	::GetCursorPos(&point);
	//显示一个菜单
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,point.x,point.y,this);
	*pResult = 0;
}


void CListCtrlShowPath::On32771()
{
	//弹出一个游览文件夹的对话框
	CString strPath = theApp.GetBrowseForFloder();
	if (strPath != _T(""))
	{
		//给列表添加路径
		this->InsertItem(this->GetItemCount(),strPath);
	}
}


void CListCtrlShowPath::On32772()
{
	//遍历列表所有项
	for (int i = 0; i < this->GetItemCount(); i++)
	{
		//判断当前这一项是不是选中的
		if (this->GetCheck(i) == TRUE)
		{
			//删除这一项
			this->DeleteItem(i);
			--i;
		}
	}
}


void CListCtrlShowPath::On32773()
{
	//删除所有相
	this->DeleteAllItems();
}


void CListCtrlShowPath::On32774()
{
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
