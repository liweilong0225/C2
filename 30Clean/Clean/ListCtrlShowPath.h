#pragma once


// CListCtrlShowPath

class CListCtrlShowPath : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlShowPath)

public:
	CListCtrlShowPath();
	virtual ~CListCtrlShowPath();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CMenu menu;//ÓÒ¼ü²Ëµ¥
	afx_msg void OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
};


