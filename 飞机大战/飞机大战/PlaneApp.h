#pragma once
#include "CGameApp.h"
#include"Back.h"
#include"Player.h"
#include"GunnerBox.h"
#include"FoePlaneBox.h"
#include"BlastFoePlaneBox.h"
class CPlaneApp :
	public CGameApp
{
public:
	CBack back;				//背景
	CPlayer player;			//玩家飞机

	CGunnerBox gunBox;			//所有炮弹
	CFoePlaneBox foeplaneBox;	//装所有的敌人飞机
	CBlastFoePlaneBox blastBox;	//装所有爆炸的敌人飞机
	
public:
	CPlaneApp(void);
	~CPlaneApp(void);
public:
	virtual void OnCreateGame();			//需要HINSTANCE
	virtual void OnGameDraw();				//需要HWND
	virtual void OnGameRun(WPARAM nTimerID);//需要WPARAM这个定时器编号
	virtual void OnKeyDown(WPARAM nKey);	//需要WPARAM这个具体按键
public:
	void GunnerHitFoePlane();	//炮弹打敌人飞机
	bool IsGameOver();			//游戏是否结束
};

