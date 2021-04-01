
// FaceFaceView.h : CFaceFaceView ��Ľӿ�
//

#pragma once


class CFaceFaceView : public CView
{
protected: // �������л�����
	CFaceFaceView();
	DECLARE_DYNCREATE(CFaceFaceView)

// ����
public:
	CFaceFaceDoc* GetDocument() const;

// ����
public:

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
	virtual ~CFaceFaceView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FaceFaceView.cpp �еĵ��԰汾
inline CFaceFaceDoc* CFaceFaceView::GetDocument() const
   { return reinterpret_cast<CFaceFaceDoc*>(m_pDocument); }
#endif

