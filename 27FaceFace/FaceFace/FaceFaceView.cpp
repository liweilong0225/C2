
// FaceFaceView.cpp : CFaceFaceView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FaceFace.h"
#endif

#include "FaceFaceDoc.h"
#include "FaceFaceView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFaceFaceView

IMPLEMENT_DYNCREATE(CFaceFaceView, CView)

BEGIN_MESSAGE_MAP(CFaceFaceView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFaceFaceView 构造/析构

CFaceFaceView::CFaceFaceView()
{
	// TODO: 在此处添加构造代码

}

CFaceFaceView::~CFaceFaceView()
{
}

BOOL CFaceFaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	HCURSOR hCursor = theApp.LoadCursor(IDC_CURSOR1);
	HBRUSH hBrush = ::CreateSolidBrush(RGB(0,0,255));

	cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW|CS_HREDRAW,hCursor,hBrush);

	return CView::PreCreateWindow(cs);
}

// CFaceFaceView 绘制

void CFaceFaceView::OnDraw(CDC* /*pDC*/)
{
	CFaceFaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFaceFaceView 打印

BOOL CFaceFaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFaceFaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFaceFaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFaceFaceView 诊断

#ifdef _DEBUG
void CFaceFaceView::AssertValid() const
{
	CView::AssertValid();
}

void CFaceFaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceFaceDoc* CFaceFaceView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceFaceDoc)));
	return (CFaceFaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CFaceFaceView 消息处理程序
