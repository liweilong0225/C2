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
	CShowDlg m_dlgShow;//��ʾ·��
	CSetDlg m_dlgSet;//��ʾ��׺
	bool m_bMaxMinWndFlag;
public:
	void InitTabCtrl();
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};


