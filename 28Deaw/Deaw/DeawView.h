
// DeawView.h : CDeawView ��Ľӿ�
//

#pragma once


class CDeawView : public CView
{
protected: // �������л�����
	CDeawView();
	DECLARE_DYNCREATE(CDeawView)

// ����
public:
	CDeawDoc* GetDocument() const;

// ����
public:
	CPoint ptDown;
	bool m_blsDrawFlag;//�Ƿ�ͼ

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
	virtual ~CDeawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DeawView.cpp �еĵ��԰汾
inline CDeawDoc* CDeawView::GetDocument() const
   { return reinterpret_cast<CDeawDoc*>(m_pDocument); }
#endif

