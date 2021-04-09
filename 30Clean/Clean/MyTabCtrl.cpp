// MyTabCtrl.cpp : 实现文件
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



// CMyTabCtrl 消息处理程序
void CMyTabCtrl::InitTabCtrl()
{
	//============初始化标签==============
	for (int i = 0; i < 4; i++)
	{
		CString str;
		//通过ID加载字符串
		str.LoadString(IDS_AAAAAA+i);
		//插入标签项
		this->InsertItem(i,str);
	}
	//设置高度
	CSize size(0,30);
	this->SetItemSize(size); 
	//===========标签上其他内容的初始化===========
	m_dlgShow.Create(IDD_DIALOG1,this);
	m_dlgShow.ShowWindow(SW_SHOW);

	m_dlgSet.Create(IDD_DIALOG2,this);
	m_dlgSet.ShowWindow(SW_HIDE);

	//=============m_dlgShow m_dlgSet--对话框向下移动30======
	RECT rect;
	this->GetClientRect(&rect);
	rect.top += 30;
	rect.bottom += 30;

	m_dlgShow.MoveWindow(&rect);
	m_dlgSet.MoveWindow(&rect);

}



void CMyTabCtrl::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	//获取点击的标签项
	int index = this->GetCurSel();
	if (index != -1)
	{
		//判断是哪一项
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
				//放大缩小窗口
				if (m_bMaxMinWndFlag == false)//放大
				{
					RECT rect;
					AfxGetMainWnd()->GetWindowRect(&rect);
					rect.bottom += 245;
					AfxGetMainWnd()->MoveWindow(&rect);
				}
				else//缩小
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
