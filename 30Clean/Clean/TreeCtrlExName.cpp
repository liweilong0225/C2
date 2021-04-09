// TreeCtrlExName.cpp : 实现文件
//

#include "stdafx.h"
#include "Clean.h"
#include "TreeCtrlExName.h"


// CTreeCtrlExName

IMPLEMENT_DYNAMIC(CTreeCtrlExName, CTreeCtrl)

CTreeCtrlExName::CTreeCtrlExName()
{

}

CTreeCtrlExName::~CTreeCtrlExName()
{
}


BEGIN_MESSAGE_MAP(CTreeCtrlExName, CTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, &CTreeCtrlExName::OnTvnItemexpanding)
	ON_NOTIFY_REFLECT(NM_CLICK, &CTreeCtrlExName::OnNMClick)
END_MESSAGE_MAP()



// CTreeCtrlExName 消息处理程序

void CTreeCtrlExName::InsertOnePage(CString strPath,HTREEITEM hItem)
{
	if(strPath == _T("")||hItem == 0)
		return;

	//在strPath 路径下查找文件
	CFileFind file;
	BOOL bflag = file.FindFile(strPath+_T("\\*.*"));//寻找所有类型的所有文件
	//不停的查找
	while(bflag)
	{
		//找下一个
		bflag = file.FindNextFile();
		//判断是不是. 和 ..文件
		if(file.IsDots() == TRUE)
			continue;
		//获取文件名
		CString strFileName = file.GetFileName();
		//插入到hItem的下面
		this->InsertItem(strFileName,hItem);
	}
}

CString CTreeCtrlExName::GetExpandItemPath(HTREEITEM hItem)
{
	CString strPath;
	//不停的遍历父亲向
	while (hItem)
	{
		//获取项的文本
		CString strText = this->GetItemText(hItem);
		//拼接
		strPath = strText + '\\' + strPath;
		//查找父亲
		hItem = this->GetParentItem(hItem);
	}
	return strPath;
}

void CTreeCtrlExName::OnTvnItemexpanding(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//获取展开项的句柄
	HTREEITEM hExpandItem = pNMTreeView->itemNew.hItem;
	//1.获取展开这一项的系统路径
	CString strPath = this->GetExpandItemPath(hExpandItem);
	//2.遍历展开这一项所有子项，给每个子项插入一层
	if(strPath != _T(""))
	{
		HTREEITEM hChildItem = this->GetChildItem(hExpandItem);
		while (hChildItem)
		{
			//获取子项的名字
			CString strName = this->GetItemText(hChildItem);
			//插入一层
			if(this->GetChildItem(hChildItem) == 0)
				this->InsertOnePage(strPath + "\\" + strName,hChildItem);
			hChildItem = this->GetNextSiblingItem(hChildItem);
		}
	}
	*pResult = 0;
}


void CTreeCtrlExName::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	//获取点击的这一项的句柄
	CPoint point;
	GetCursorPos(&point);
	this->ScreenToClient(&point);
	HTREEITEM hItem = this->HitTest(point);
	//保存到容器中
	if(hItem!= 0)
		stItem.insert(hItem);

	*pResult = 0;
}
