
// screenshotView.h : CscreenshotView 类的接口
//

#pragma once


class CscreenshotView : public CView
{
protected: // 仅从序列化创建
	CscreenshotView();
	DECLARE_DYNCREATE(CscreenshotView)

// 特性
public:
	CscreenshotDoc* GetDocument() const;

// 操作
public:
	bool m_bIsDrawFlag;	//是否要画图
	CPoint ptDown;		//记录按下的坐标
	COLORREF color;		//颜色
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CscreenshotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChangeDrawColor();
};

#ifndef _DEBUG  // screenshotView.cpp 中的调试版本
inline CscreenshotDoc* CscreenshotView::GetDocument() const
   { return reinterpret_cast<CscreenshotDoc*>(m_pDocument); }
#endif

