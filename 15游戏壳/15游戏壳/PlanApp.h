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
		::MessageBox(0,"���¿�ʼ","GameOver",MB_OK);
	}
};

