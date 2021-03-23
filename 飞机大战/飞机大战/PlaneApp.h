#pragma once
#include "CGameApp.h"
#include"Back.h"
#include"Player.h"
#include"GunnerBox.h"
class CPlaneApp :
	public CGameApp
{
public:
	CBack back;				//背景
	CPlayer player;			//玩家飞机
	CGunnerBox gunBox;		//所有炮弹
public:
	CPlaneApp(void);
	~CPlaneApp(void);
public:
	virtual void OnCreateGame();			//需要HINSTANCE
	virtual void OnGameDraw();				//需要HWND
	virtual void OnGameRun(WPARAM nTimerID);//需要WPARAM这个定时器编号
	virtual void OnKeyDown(WPARAM nKey);	//需要WPARAM这个具体按键
};

