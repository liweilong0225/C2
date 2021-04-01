
// DeawView.cpp : CDeawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Deaw.h"
#endif

#include "DeawDoc.h"
#include "DeawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDeawView

IMPLEMENT_DYNCREATE(CDeawView, CView)

	BEGIN_MESSAGE_MAP(CDeawView, CView)
		// ��׼��ӡ����
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_WM_MOUSEMOVE()
	END_MESSAGE_MAP()

	// CDeawView ����/����

	CDeawView::CDeawView()
	{
		// TODO: �ڴ˴���ӹ������
		//Ĭ�ϲ���ͼ
		m_blsDrawFlag = false;
	}

	CDeawView::~CDeawView()
	{
	}

	BOOL CDeawView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: �ڴ˴�ͨ���޸�
		//  CREATESTRUCT cs ���޸Ĵ��������ʽ

		return CView::PreCreateWindow(cs);
	}

	// CDeawView ����

	void CDeawView::OnDraw(CDC* /*pDC*/)
	{
		CDeawDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
		//-----------------������------------
		/*HDC hdc = ::GetDC(this->m_hWnd);
		::Rectangle(hdc,0,0,100,100);
		::ReleaseDC(this->m_hWnd,hdc)*/;

		//--------------------MFC��ͼ--------------
		/*CDC* pDC = this->GetDC();
		pDC->Rectangle(0,0,100,100);
		this->ReleaseDC(pDC);*/

		//------------------��ͼ----------
		//1.
		/*HDC hdc = ::GetDC(this->m_hWnd);
		HDC hMemDC = ::CreateCompatibleDC(hdc);
		HBITMAP hBitmap = ::LoadBitmap(theApp.m_hInstance,MAKEINTRESOURCE(IDB_BITMAP1));
		::SelectObject(hMemDC,hBitmap);
		::BitBlt(hdc,0,0,48,48,hMemDC,0,0,SRCCOPY);

		::DeleteObject(hBitmap);
		::DeleteDC(hMemDC);
		::ReleaseDC(this->m_hWnd,hdc);*/

		//2.
		CClientDC dc(this);
		CDC cdc;//CDC����������
		cdc.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		cdc.SelectObject(&bitmap);
		dc.BitBlt(0,0,48,48,&cdc,0,0,SRCCOPY);

	}


	// CDeawView ��ӡ

	BOOL CDeawView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// Ĭ��׼��
		return DoPreparePrinting(pInfo);
	}

	void CDeawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
	}

	void CDeawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӵ�ӡ����е��������
	}


	// CDeawView ���

#ifdef _DEBUG
	void CDeawView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CDeawView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CDeawDoc* CDeawView::GetDocument() const // �ǵ��԰汾��������
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDeawDoc)));
		return (CDeawDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CDeawView ��Ϣ�������


	void CDeawView::OnLButtonDown(UINT nFlags, CPoint point)
	{
		//��¼����,��ʼ��
		ptDown = point;
		//m_blsDrawFlag = true;
		CView::OnLButtonDown(nFlags, point);
	}


	void CDeawView::OnLButtonUp(UINT nFlags, CPoint point)
	{
		//̧����������
		//1.
		//m_blsDrawFlag = false;
		/*CDC* pDC = this->GetDC();
		pDC->MoveTo(ptDown);
		pDC->LineTo(point);
		this->ReleaseDC(pDC);*/
		//2.
		CClientDC dc(this);
		//CClientDC dc(AfxGetMainWnd());//��ȡFrame�Ŀͻ���DC
		//CWindowDC dc(AfxGetMainWnd());//��ȡFrame�Ĵ���DC
		//CWindowDC dc(GetDesktopWindow());//GetDesktopWindow��ȡ�����������
		dc.MoveTo(ptDown);
		dc.LineTo(point);

		CView::OnLButtonUp(nFlags, point);
	}


	void CDeawView::OnMouseMove(UINT nFlags, CPoint point)
	{
		//if (m_blsDrawFlag == true)
		//{
		//	//��ͼ
		//	CDC* pDC = GetDC();
		//	pDC->MoveTo(ptDown);
		//	pDC->LineTo(point);

		//	//���°��µĵ�
		//	ptDown = point;
		//	this->ReleaseDC(pDC);
		//}
		CView::OnMouseMove(nFlags, point);
	}
