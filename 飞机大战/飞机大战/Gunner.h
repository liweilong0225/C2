#pragma once
#include"Sys.h"
class CGunner
{
public:
	HBITMAP m_hBmpGunner;
	int x;
	int y;
public:
	CGunner(void);
	~CGunner(void);
public:
	void InitGunner(HINSTANCE hIns, int x1, int y1);
	void MoveGunner();
	void ShowGunner(HDC hdc);
};

