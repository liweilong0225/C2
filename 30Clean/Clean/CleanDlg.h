
// CleanDlg.h : ͷ�ļ�
//

#pragma once
#include "mytabctrl.h"


// CCleanDlg �Ի���
class CCleanDlg : public CDialogEx
{
// ����
public:
	CCleanDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLEAN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	HBITMAP m_hBitmap7;
	HBITMAP m_hBitmap8;
	CStatic picture;//ͼƬ
	bool m_bIsChangeBmp;//�Ƿ�ı�λͼ
	bool m_bChangeWndSizeFlag;//�Ƿ�ı䴰�ڴ�С
public:
	afx_msg void OnStnClickedPicture();
	CMyTabCtrl m_tab;
};
