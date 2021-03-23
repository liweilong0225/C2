#pragma once
#include "CGameApp.h"
#include"Back.h"
#include"Player.h"
#include"GunnerBox.h"
class CPlaneApp :
	public CGameApp
{
public:
	CBack back;				//����
	CPlayer player;			//��ҷɻ�
	CGunnerBox gunBox;		//�����ڵ�
public:
	CPlaneApp(void);
	~CPlaneApp(void);
public:
	virtual void OnCreateGame();			//��ҪHINSTANCE
	virtual void OnGameDraw();				//��ҪHWND
	virtual void OnGameRun(WPARAM nTimerID);//��ҪWPARAM�����ʱ�����
	virtual void OnKeyDown(WPARAM nKey);	//��ҪWPARAM������尴��
};

