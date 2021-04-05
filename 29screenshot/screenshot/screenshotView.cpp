
// screenshotView.cpp : CscreenshotView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON32784,&CscreenshotView::OnChangeDrawColor)
END_MESSAGE_MAP()

// CscreenshotView ����/����

void CscreenshotView::OnChangeDrawColor()
{
	//����һ����ɫ��
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		//��ȡ��ɫ
		color = dlg.GetColor();
	}
}
CscreenshotView::CscreenshotView()
{
	m_bIsDrawFlag = false;
	color = RGB(0,255,0);//Ĭ�ϵ���ɫ

}

CscreenshotView::~CscreenshotView()
{
}

BOOL CscreenshotView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CscreenshotView ����

void CscreenshotView::OnDraw(CDC* /*pDC*/)
{
	CscreenshotDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	// -------------2.��ͼƬ�ŵ�������---------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	cdc.SelectObject(pFrame->sk.top());

	dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
	// -------------2.��ͼƬ�ŵ�������---------------

}


// CscreenshotView ��ӡ

BOOL CscreenshotView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CscreenshotView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CscreenshotView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CscreenshotView ���

#ifdef _DEBUG
void CscreenshotView::AssertValid() const
{
	CView::AssertValid();
}

void CscreenshotView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CscreenshotDoc* CscreenshotView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CscreenshotDoc)));
	return (CscreenshotDoc*)m_pDocument;
}
#endif //_DEBUG


// CscreenshotView ��Ϣ�������


void CscreenshotView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE)
	{
		//��ESC�˳�
		AfxGetMainWnd()->PostMessage(WM_CLOSE);
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CscreenshotView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//ִ�����
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	if (pFrame->m_nDrawType == FULL)
	{
		CClientDC dc(this);
		CBrush brush(color);
		dc.SelectObject(brush);

		//��ȡ��������ص����ɫ
		COLORREF col = dc.GetPixel(point);
		//���
		dc.ExtFloodFill(point.x,point.y,col,FLOODFILLSURFACE);

	}
	// ------------��¼���꣬��ʼ��ͼ--------------
	ptDown = point;
	m_bIsDrawFlag = true;
	// ------------��¼���꣬��ʼ��ͼ--------------

	CView::OnLButtonDown(nFlags, point);
}


void CscreenshotView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//--------------������ͼ---------------
	m_bIsDrawFlag = false;

	//--------------������ͼ---------------
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//----------����ͼ��������ϵ�ͼƬ�����浽ջ��-------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	CBitmap* bitmap = new CBitmap;
	bitmap->CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
	cdc.SelectObject(bitmap);

	cdc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&dc,0,0,SRCCOPY);//����ͼ������������DC��

	pFrame->sk.push(bitmap);//��ͼƬ�浽ջ��

	CView::OnLButtonUp(nFlags, point);
}


void CscreenshotView::OnMouseMove(UINT nFlags, CPoint point)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	//--------------�ж��Ƿ�Ҫ��ͼ-------------
	if (m_bIsDrawFlag == true && pFrame->m_nDrawType != FULL)
	{
		CClientDC dc(this);//��ȡ��Ļ����
		//---------�жϻ�ʲôͼ��--------------
		if (pFrame->m_nDrawType == CURVE)//����
		{
			CPen pen(PS_SOLID,5,color);	//����һ������
			dc.SelectObject(pen);		//�ѻ���ѡ��DC��
			dc.MoveTo(ptDown);
			dc.LineTo(point);
			ptDown = point;
			return;
		}
		//--------------�������-------------
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
		memDC.SelectObject(bitmap);

		//-----------��ջ����Ԫ�أ������ƶ��ĺۼ�---------
		CDC cdc;
		cdc.CreateCompatibleDC(&dc);
		cdc.SelectObject(pFrame->sk.top());
		memDC.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);

		//-----------������ͼ��----------------
		switch (pFrame->m_nDrawType)
		{
		case LINE:
			{
				CPen pen(PS_SOLID,5,color);	//����һ������
				memDC.SelectObject(pen);	//�ѻ���ѡ��DC��
				memDC.MoveTo(ptDown);
				memDC.LineTo(point);
			}
			break;
		case RECTANGL:
			{
				CPen pen(PS_SOLID,5,color);	//����һ������
				memDC.SelectObject(pen);	//�ѻ���ѡ��DC��
				memDC.SelectStockObject(NULL_BRUSH);//ѡ��һ���ջ�ˢ
				memDC.Rectangle(ptDown.x,ptDown.y,point.x,point.y);
			}
			break;
		case ELLIPSE:
			{
				//ʵ��Բ
				CBrush bursh(color);//����һ����ˢ
				memDC.SelectObject(bursh);
				memDC.SelectStockObject(NULL_PEN);//ѡ��һ���ջ���
				//����Բ
				//CPen pen(PS_SOLID,5,color);	//����һ������
				//memDC.SelectObject(pen);	//�ѻ���ѡ��DC��
				//memDC.SelectStockObject(NULL_BRUSH);//ѡ��һ���ջ�ˢ
				memDC.Ellipse(ptDown.x,ptDown.y,point.x,point.y);
			}
			break;
		case TRIANGLE:
			{
				CPen pen(PS_SOLID,5,color);	//����һ������
				memDC.SelectObject(pen);	//�ѻ���ѡ��DC��
				memDC.SelectStockObject(NULL_BRUSH);//ѡ��һ���ջ�ˢ
				POINT ptArr[3] = {
					{(ptDown.x+point.x)/2,ptDown.y},
					{point.x,point.y},
					{ptDown.x,point.y}
				};
				memDC.Polygon(ptArr,3);//�������
			}
			break;
		default:
			break;
		}
		dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&memDC,0,0,SRCCOPY);//�Ӽ�����DC������������
	}


	CView::OnMouseMove(nFlags, point);
}
