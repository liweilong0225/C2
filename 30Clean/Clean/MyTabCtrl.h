#pragma once
#include"ShowDlg.h"
#include"SetDlg.h"
// CMyTabCtrl

class CMyTabCtrl : public CTabCtrl
{
	DECLARE_DYNAMIC(CMyTabCtrl)

public:
	CMyTabCtrl();
	virtual ~CMyTabCtrl();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CShowDlg m_dlgShow;//显示路径
	CSetDlg m_dlgSet;//显示后缀
	bool m_bMaxMinWndFlag;
public:
	void InitTabCtrl();
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};


