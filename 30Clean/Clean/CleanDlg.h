
// CleanDlg.h : 头文件
//

#pragma once
#include "mytabctrl.h"


// CCleanDlg 对话框
class CCleanDlg : public CDialogEx
{
// 构造
public:
	CCleanDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLEAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	HBITMAP m_hBitmap7;
	HBITMAP m_hBitmap8;
	CStatic picture;//图片
	bool m_bIsChangeBmp;//是否改变位图
	bool m_bChangeWndSizeFlag;//是否改变窗口大小
public:
	afx_msg void OnStnClickedPicture();
	CMyTabCtrl m_tab;
};
