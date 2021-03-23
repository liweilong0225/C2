#include "Gunner.h"


CGunner::CGunner(void)
{
	m_hBmpGunner = 0;
	x = 0;
	y = 0;
}


CGunner::~CGunner(void)
{
	::DeleteObject(m_hBmpGunner);
}
void CGunner::InitGunner(HINSTANCE hIns, int x1, int y1)
{
	m_hBmpGunner = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_GUNNER));
	x = x1;
	y = y1;
}
void CGunner::MoveGunner()
{
	y-=10;
}
void CGunner::ShowGunner(HDC hdc)
{
	HDC hMemDC = ::CreateCompatibleDC(hdc);
	::SelectObject(hMemDC,m_hBmpGunner);
	BitBlt(hdc,x,y,6,69,hMemDC,0,0,SRCCOPY);
	::DeleteDC(hMemDC);
}