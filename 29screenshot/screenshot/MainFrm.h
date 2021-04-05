
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include<stack>
using namespace std;

class CMainFrame : public CFrameWnd
{
	
protected: // �������л����� 
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:
	//��Ļ�Ĵ�С
	int m_nScreenCX;
	int m_nScreenCY;
	//ջ��������ͼƬ
	stack<CBitmap*> sk;
	//��ʲôͼ��
	int m_nDrawType;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnToolBarQuit();
	afx_msg void OnToolBarChangeDrawTyle(UINT uID);
	afx_msg void OnAccelerator32780();
	afx_msg void OnFull();
	afx_msg void OnSave();
};


