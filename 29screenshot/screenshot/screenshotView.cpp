
// screenshotView.cpp : CscreenshotView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "screenshot.h"
#endif

#include "screenshotDoc.h"
#include "screenshotView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CscreenshotView

IMPLEMENT_DYNCREATE(CscreenshotView, CView)

BEGIN_MESSAGE_MAP(CscreenshotView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON32784,&CscreenshotView::OnChangeDrawColor)
END_MESSAGE_MAP()

// CscreenshotView 构造/析构

void CscreenshotView::OnChangeDrawColor()
{
	//弹出一个调色板
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		//获取颜色
		color = dlg.GetColor();
	}
}
CscreenshotView::CscreenshotView()
{
	m_bIsDrawFlag = false;
	color = RGB(0,255,0);//默认的颜色

}

CscreenshotView::~CscreenshotView()
{
}

BOOL CscreenshotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CscreenshotView 绘制

void CscreenshotView::OnDraw(CDC* /*pDC*/)
{
	CscreenshotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	// -------------2.把图片放到窗口上---------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	cdc.SelectObject(pFrame->sk.top());

	dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
	// -------------2.把图片放到窗口上---------------

}


// CscreenshotView 打印

BOOL CscreenshotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CscreenshotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CscreenshotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CscreenshotView 诊断

#ifdef _DEBUG
void CscreenshotView::AssertValid() const
{
	CView::AssertValid();
}

void CscreenshotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CscreenshotDoc* CscreenshotView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CscreenshotDoc)));
	return (CscreenshotDoc*)m_pDocument;
}
#endif //_DEBUG


// CscreenshotView 消息处理程序


void CscreenshotView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE)
	{
		//按ESC退出
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CscreenshotView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//执行填充
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	if (pFrame->m_nDrawType == FULL)
	{
		CClientDC dc(this);
		CBrush brush(color);
		dc.SelectObject(brush);

		//获取点击的像素点的颜色
		COLORREF col = dc.GetPixel(point);
		//填充
		dc.ExtFloodFill(point.x,point.y,col,FLOODFILLSURFACE);

	}
	// ------------记录坐标，开始画图--------------
	ptDown = point;
	m_bIsDrawFlag = true;
	// ------------记录坐标，开始画图--------------

	CView::OnLButtonDown(nFlags, point);
}


void CscreenshotView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//--------------结束画图---------------
	m_bIsDrawFlag = false;

	//--------------结束画图---------------
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//----------把视图这个窗口上的图片，保存到栈里-------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	CBitmap* bitmap = new CBitmap;
	bitmap->CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
	cdc.SelectObject(bitmap);

	cdc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&dc,0,0,SRCCOPY);//把视图拷贝到兼容性DC里

	pFrame->sk.push(bitmap);//把图片存到栈里

	CView::OnLButtonUp(nFlags, point);
}


void CscreenshotView::OnMouseMove(UINT nFlags, CPoint point)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//--------------判断是否要画图-------------
	if (m_bIsDrawFlag == true && pFrame->m_nDrawType != FULL)
	{
		CClientDC dc(this);//截取屏幕窗口
		//---------判断画什么图形--------------
		if (pFrame->m_nDrawType == CURVE)//曲线
		{
			CPen pen(PS_SOLID,5,color);	//创建一个画笔
			dc.SelectObject(pen);		//把画笔选到DC中
			dc.MoveTo(ptDown);
			dc.LineTo(point);
			ptDown = point;
			return;
		}
		//--------------解决闪屏-------------
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
		memDC.SelectObject(bitmap);

		//-----------用栈顶的元素，擦除移动的痕迹---------
		CDC cdc;
		cdc.CreateCompatibleDC(&dc);
		cdc.SelectObject(pFrame->sk.top());
		memDC.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);

		//-----------其他的图形----------------
		switch (pFrame->m_nDrawType)
		{
		case LINE:
			{
				CPen pen(PS_SOLID,5,color);	//创建一个画笔
				memDC.SelectObject(pen);	//把画笔选到DC中
				memDC.MoveTo(ptDown);
				memDC.LineTo(point);
			}
			break;
		case RECTANGL:
			{
				CPen pen(PS_SOLID,5,color);	//创建一个画笔
				memDC.SelectObject(pen);	//把画笔选到DC中
				memDC.SelectStockObject(NULL_BRUSH);//选入一个空画刷
				memDC.Rectangle(ptDown.x,ptDown.y,point.x,point.y);
			}
			break;
		case ELLIPSE:
			{
				//实心圆
				CBrush bursh(color);//创建一个画刷
				memDC.SelectObject(bursh);
				memDC.SelectStockObject(NULL_PEN);//选入一个空画笔
				//空心圆
				//CPen pen(PS_SOLID,5,color);	//创建一个画笔
				//memDC.SelectObject(pen);	//把画笔选到DC中
				//memDC.SelectStockObject(NULL_BRUSH);//选入一个空画刷
				memDC.Ellipse(ptDown.x,ptDown.y,point.x,point.y);
			}
			break;
		case TRIANGLE:
			{
				CPen pen(PS_SOLID,5,color);	//创建一个画笔
				memDC.SelectObject(pen);	//把画笔选到DC中
				memDC.SelectStockObject(NULL_BRUSH);//选入一个空画刷
				POINT ptArr[3] = {
					{(ptDown.x+point.x)/2,ptDown.y},
					{point.x,point.y},
					{ptDown.x,point.y}
				};
				memDC.Polygon(ptArr,3);//画多边形
			}
			break;
		default:
			break;
		}
		dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&memDC,0,0,SRCCOPY);//从兼容性DC拷贝到窗口上
	}


	CView::OnMouseMove(nFlags, point);
}
