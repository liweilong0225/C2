#pragma once
#include "afxwin.h"
#include "treectrlexname.h"


// CSetDlg 对话框

class CSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox combox;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnCloseupCombo1();
	afx_msg void OnBnClickedButton2();
	CTreeCtrlExName m_tree;
};
