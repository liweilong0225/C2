#pragma once
#include "CGameApp.h"
class CPlanApp :
	public CGameApp
{
public:
	CPlanApp(void);
	~CPlanApp(void);
public:
	virtual void OnLButtonDown(POINT point)
	{
		::MessageBox(0,"重新开始","GameOver!",MB_OK);
	}
};

