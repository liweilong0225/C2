// TreeCtrlExName.cpp : ʵ���ļ�
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



// CTreeCtrlExName ��Ϣ�������

void CTreeCtrlExName::InsertOnePage(CString strPath,HTREEITEM hItem)
{
	if(strPath == _T("")||hItem == 0)
		return;

	//��strPath ·���²����ļ�
	CFileFind file;
	BOOL bflag = file.FindFile(strPath+_T("\\*.*"));//Ѱ���������͵������ļ�
	//��ͣ�Ĳ���
	while(bflag)
	{
		//����һ��
		bflag = file.FindNextFile();
		//�ж��ǲ���. �� ..�ļ�
		if(file.IsDots() == TRUE)
			continue;
		//��ȡ�ļ���
		CString strFileName = file.GetFileName();
		//���뵽hItem������
		this->InsertItem(strFileName,hItem);
	}
}

CString CTreeCtrlExName::GetExpandItemPath(HTREEITEM hItem)
{
	CString strPath;
	//��ͣ�ı���������
	while (hItem)
	{
		//��ȡ����ı�
		CString strText = this->GetItemText(hItem);
		//ƴ��
		strPath = strText + '\\' + strPath;
		//���Ҹ���
		hItem = this->GetParentItem(hItem);
	}
	return strPath;
}

void CTreeCtrlExName::OnTvnItemexpanding(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//��ȡչ����ľ��
	HTREEITEM hExpandItem = pNMTreeView->itemNew.hItem;
	//1.��ȡչ����һ���ϵͳ·��
	CString strPath = this->GetExpandItemPath(hExpandItem);
	//2.����չ����һ�����������ÿ���������һ��
	if(strPath != _T(""))
	{
		HTREEITEM hChildItem = this->GetChildItem(hExpandItem);
		while (hChildItem)
		{
			//��ȡ���������
			CString strName = this->GetItemText(hChildItem);
			//����һ��
			if(this->GetChildItem(hChildItem) == 0)
				this->InsertOnePage(strPath + "\\" + strName,hChildItem);
			hChildItem = this->GetNextSiblingItem(hChildItem);
		}
	}
	*pResult = 0;
}


void CTreeCtrlExName::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	//��ȡ�������һ��ľ��
	CPoint point;
	GetCursorPos(&point);
	this->ScreenToClient(&point);
	HTREEITEM hItem = this->HitTest(point);
	//���浽������
	if(hItem!= 0)
		stItem.insert(hItem);

	*pResult = 0;
}
