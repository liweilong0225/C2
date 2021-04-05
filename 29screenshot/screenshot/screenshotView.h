
// screenshotView.h : CscreenshotView ��Ľӿ�
//

#pragma once


class CscreenshotView : public CView
{
protected: // �������л�����
	CscreenshotView();
	DECLARE_DYNCREATE(CscreenshotView)

// ����
public:
	CscreenshotDoc* GetDocument() const;

// ����
public:
	bool m_bIsDrawFlag;	//�Ƿ�Ҫ��ͼ
	CPoint ptDown;		//��¼���µ�����
	COLORREF color;		//��ɫ
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CscreenshotView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChangeDrawColor();
};

#ifndef _DEBUG  // screenshotView.cpp �еĵ��԰汾
inline CscreenshotDoc* CscreenshotView::GetDocument() const
   { return reinterpret_cast<CscreenshotDoc*>(m_pDocument); }
#endif

