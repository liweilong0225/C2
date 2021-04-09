// ListCtrlShowPath.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clean.h"
#include "ListCtrlShowPath.h"


// CListCtrlShowPath

IMPLEMENT_DYNAMIC(CListCtrlShowPath, CListCtrl)

CListCtrlShowPath::CListCtrlShowPath()
{
	//���ز˵�
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



// CListCtrlShowPath ��Ϣ�������




void CListCtrlShowPath::OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	POINT point;
	::GetCursorPos(&point);
	//��ʾһ���˵�
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,point.x,point.y,this);
	*pResult = 0;
}


void CListCtrlShowPath::On32771()
{
	//����һ�������ļ��еĶԻ���
	CString strPath = theApp.GetBrowseForFloder();
	if (strPath != _T(""))
	{
		//���б����·��
		this->InsertItem(this->GetItemCount(),strPath);
	}
}


void CListCtrlShowPath::On32772()
{
	//�����б�������
	for (int i = 0; i < this->GetItemCount(); i++)
	{
		//�жϵ�ǰ��һ���ǲ���ѡ�е�
		if (this->GetCheck(i) == TRUE)
		{
			//ɾ����һ��
			this->DeleteItem(i);
			--i;
		}
	}
}


void CListCtrlShowPath::On32773()
{
	//ɾ��������
	this->DeleteAllItems();
}


void CListCtrlShowPath::On32774()
{
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}
