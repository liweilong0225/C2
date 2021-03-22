#pragma once
#include "gameapp.h"
class CPlanApp :
	public CGameapp
{
public:
	CPlanApp(void);
	~CPlanApp(void);
public:
	virtual void OnLButtonDown(POINT point)
	{
		::MessageBox(0,"重新开始","GameOver",MB_OK);
	}
};

