#pragma once
#include "afxwin.h"
#include "treectrlexname.h"


// CSetDlg �Ի���

class CSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox combox;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnCloseupCombo1();
	afx_msg void OnBnClickedButton2();
	CTreeCtrlExName m_tree;
};
