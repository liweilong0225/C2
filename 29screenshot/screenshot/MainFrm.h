
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include<stack>
using namespace std;

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建 
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:
	//屏幕的大小
	int m_nScreenCX;
	int m_nScreenCY;
	//栈，用来存图片
	stack<CBitmap*> sk;
	//画什么图形
	int m_nDrawType;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
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


