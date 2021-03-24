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
	CBack back;				//����
	CPlayer player;			//��ҷɻ�

	CGunnerBox gunBox;			//�����ڵ�
	CFoePlaneBox foeplaneBox;	//װ���еĵ��˷ɻ�
	CBlastFoePlaneBox blastBox;	//װ���б�ը�ĵ��˷ɻ�
	
public:
	CPlaneApp(void);
	~CPlaneApp(void);
public:
	virtual void OnCreateGame();			//��ҪHINSTANCE
	virtual void OnGameDraw();				//��ҪHWND
	virtual void OnGameRun(WPARAM nTimerID);//��ҪWPARAM�����ʱ�����
	virtual void OnKeyDown(WPARAM nKey);	//��ҪWPARAM������尴��
public:
	void GunnerHitFoePlane();	//�ڵ�����˷ɻ�
	bool IsGameOver();			//��Ϸ�Ƿ����
};

