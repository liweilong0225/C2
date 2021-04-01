
// DeawView.cpp : CDeawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
		// 标准打印命令
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_LBUTTONDOWN()
		ON_WM_LBUTTONUP()
		ON_WM_MOUSEMOVE()
	END_MESSAGE_MAP()

	// CDeawView 构造/析构

	CDeawView::CDeawView()
	{
		// TODO: 在此处添加构造代码
		//默认不画图
		m_blsDrawFlag = false;
	}

	CDeawView::~CDeawView()
	{
	}

	BOOL CDeawView::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: 在此处通过修改
		//  CREATESTRUCT cs 来修改窗口类或样式

		return CView::PreCreateWindow(cs);
	}

	// CDeawView 绘制

	void CDeawView::OnDraw(CDC* /*pDC*/)
	{
		CDeawDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: 在此处为本机数据添加绘制代码
		//-----------------画矩形------------
		/*HDC hdc = ::GetDC(this->m_hWnd);
		::Rectangle(hdc,0,0,100,100);
		::ReleaseDC(this->m_hWnd,hdc)*/;

		//--------------------MFC绘图--------------
		/*CDC* pDC = this->GetDC();
		pDC->Rectangle(0,0,100,100);
		this->ReleaseDC(pDC);*/

		//------------------贴图----------
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
		CDC cdc;//CDC创建兼容性
		cdc.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		cdc.SelectObject(&bitmap);
		dc.BitBlt(0,0,48,48,&cdc,0,0,SRCCOPY);

	}


	// CDeawView 打印

	BOOL CDeawView::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// 默认准备
		return DoPreparePrinting(pInfo);
	}

	void CDeawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 添加额外的打印前进行的初始化过程
	}

	void CDeawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 添加打印后进行的清理过程
	}


	// CDeawView 诊断

#ifdef _DEBUG
	void CDeawView::AssertValid() const
	{
		CView::AssertValid();
	}

	void CDeawView::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	CDeawDoc* CDeawView::GetDocument() const // 非调试版本是内联的
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDeawDoc)));
		return (CDeawDoc*)m_pDocument;
	}
#endif //_DEBUG


	// CDeawView 消息处理程序


	void CDeawView::OnLButtonDown(UINT nFlags, CPoint point)
	{
		//记录坐标,开始画
		ptDown = point;
		//m_blsDrawFlag = true;
		CView::OnLButtonDown(nFlags, point);
	}


	void CDeawView::OnLButtonUp(UINT nFlags, CPoint point)
	{
		//抬起后结束画线
		//1.
		//m_blsDrawFlag = false;
		/*CDC* pDC = this->GetDC();
		pDC->MoveTo(ptDown);
		pDC->LineTo(point);
		this->ReleaseDC(pDC);*/
		//2.
		CClientDC dc(this);
		//CClientDC dc(AfxGetMainWnd());//获取Frame的客户区DC
		//CWindowDC dc(AfxGetMainWnd());//获取Frame的窗口DC
		//CWindowDC dc(GetDesktopWindow());//GetDesktopWindow获取桌面这个窗口
		dc.MoveTo(ptDown);
		dc.LineTo(point);

		CView::OnLButtonUp(nFlags, point);
	}


	void CDeawView::OnMouseMove(UINT nFlags, CPoint point)
	{
		//if (m_blsDrawFlag == true)
		//{
		//	//画图
		//	CDC* pDC = GetDC();
		//	pDC->MoveTo(ptDown);
		//	pDC->LineTo(point);

		//	//更新按下的点
		//	ptDown = point;
		//	this->ReleaseDC(pDC);
		//}
		CView::OnMouseMove(nFlags, point);
	}
