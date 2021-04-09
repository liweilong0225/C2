// MyTabCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Clean.h"
#include "MyTabCtrl.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
{
	m_bMaxMinWndFlag = false;
}

CMyTabCtrl::~CMyTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CMyTabCtrl::OnNMClick)
END_MESSAGE_MAP()



// CMyTabCtrl ��Ϣ�������
void CMyTabCtrl::InitTabCtrl()
{
	//============��ʼ����ǩ==============
	for (int i = 0; i < 4; i++)
	{
		CString str;
		//ͨ��ID�����ַ���
		str.LoadString(IDS_AAAAAA+i);
		//�����ǩ��
		this->InsertItem(i,str);
	}
	//���ø߶�
	CSize size(0,30);
	this->SetItemSize(size); 
	//===========��ǩ���������ݵĳ�ʼ��===========
	m_dlgShow.Create(IDD_DIALOG1,this);
	m_dlgShow.ShowWindow(SW_SHOW);

	m_dlgSet.Create(IDD_DIALOG2,this);
	m_dlgSet.ShowWindow(SW_HIDE);

	//=============m_dlgShow m_dlgSet--�Ի��������ƶ�30======
	RECT rect;
	this->GetClientRect(&rect);
	rect.top += 30;
	rect.bottom += 30;

	m_dlgShow.MoveWindow(&rect);
	m_dlgSet.MoveWindow(&rect);

}



void CMyTabCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	//��ȡ����ı�ǩ��
	int index = this->GetCurSel();
	if (index != -1)
	{
		//�ж�����һ��
		switch (index)
		{
		case 0:
			{
				m_dlgShow.ShowWindow(SW_SHOW);
				m_dlgSet.ShowWindow(SW_HIDE);
			}
			break;
		case 1:
			{
				//�Ŵ���С����
				if (m_bMaxMinWndFlag == false)//�Ŵ�
				{
					RECT rect;
					AfxGetMainWnd()->GetWindowRect(&rect);
					rect.bottom += 245;
					AfxGetMainWnd()->MoveWindow(&rect);
				}
				else//��С
				{
					RECT rect;
					AfxGetMainWnd()->GetWindowRect(&rect);
					rect.bottom -= 245;
					AfxGetMainWnd()->MoveWindow(&rect);
				}
				m_bMaxMinWndFlag = !m_bMaxMinWndFlag;
			}
			break;
		case 2:
			{
				m_dlgShow.ShowWindow(SW_HIDE);
				m_dlgSet.ShowWindow(SW_SHOW);
			}
			break;
		case 3:
			{}
			break;
		default:
			break;
		}
	}
	*pResult = 0;
}
