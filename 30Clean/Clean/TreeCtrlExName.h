#pragma once
#include<set>
using namespace std;

// CTreeCtrlExName

class CTreeCtrlExName : public CTreeCtrl
{
	DECLARE_DYNAMIC(CTreeCtrlExName)

public:
	CTreeCtrlExName();
	virtual ~CTreeCtrlExName();

protected:
	DECLARE_MESSAGE_MAP()
public:
	set<HTREEITEM> stItem;//装点击项的句柄
public:
	void InsertOnePage(CString strPath,HTREEITEM hItem);
	CString GetExpandItemPath(HTREEITEM hItem);
public:
	afx_msg void OnTvnItemexpanding(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClick(NMHDR *pNMHDR, LRESULT *pResult);
};


