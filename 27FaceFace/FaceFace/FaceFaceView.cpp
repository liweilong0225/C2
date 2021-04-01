
// FaceFaceView.cpp : CFaceFaceView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFaceFaceView ����/����

CFaceFaceView::CFaceFaceView()
{
	// TODO: �ڴ˴���ӹ������

}

CFaceFaceView::~CFaceFaceView()
{
}

BOOL CFaceFaceView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	HCURSOR hCursor = theApp.LoadCursor(IDC_CURSOR1);
	HBRUSH hBrush = ::CreateSolidBrush(RGB(0,0,255));

	cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW|CS_HREDRAW,hCursor,hBrush);

	return CView::PreCreateWindow(cs);
}

// CFaceFaceView ����

void CFaceFaceView::OnDraw(CDC* /*pDC*/)
{
	CFaceFaceDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CFaceFaceView ��ӡ

BOOL CFaceFaceView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CFaceFaceView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CFaceFaceView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CFaceFaceView ���

#ifdef _DEBUG
void CFaceFaceView::AssertValid() const
{
	CView::AssertValid();
}

void CFaceFaceView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFaceFaceDoc* CFaceFaceView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFaceFaceDoc)));
	return (CFaceFaceDoc*)m_pDocument;
}
#endif //_DEBUG


// CFaceFaceView ��Ϣ�������
