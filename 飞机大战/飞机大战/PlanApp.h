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
		::MessageBox(0,"���¿�ʼ","GameOver!",MB_OK);
	}
};

