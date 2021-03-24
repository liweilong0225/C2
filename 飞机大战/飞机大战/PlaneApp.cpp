#include "PlaneApp.h"

DECLARE(CPlaneApp)
	CPlaneApp::CPlaneApp(void)
{
}


CPlaneApp::~CPlaneApp(void)
{
}
void CPlaneApp::OnCreateGame()				//需要HINSTANCE
{
	//1.背景初始化
	back.InitBack(m_nhIns);
	//2.玩家飞机初始化
	player.InitPlayer(m_nhIns);

	//3.启动所有定时器
	::SetTimer(m_hMainwnd,BACK_MOVE_TIMER_ID,100,0);		//控制背景移动
	::SetTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID,1,0);		//控制玩家移动
	::SetTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID,350,0);		//控制玩家飞机发射炮弹
	::SetTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID,10,0);		//控制所有炮弹移动
	::SetTimer(m_hMainwnd,CREATE_FOEPLANE_TIMER_ID,1000,0);	//创建敌人飞机
	::SetTimer(m_hMainwnd,FOEPLANE_MOVE_TIMER_ID,30,0);		//创建敌人移动
	::SetTimer(m_hMainwnd,CHANGE_SHOWID_TIMER_ID,150,0);	//改变显示ID
}
void CPlaneApp::OnGameDraw()					//需要HWND
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainwnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550);
	::SelectObject(hMemDC,hBitmap);

	back.ShowBack(hMemDC);					//显示背景
	player.ShowPlayer(hMemDC);				//显示玩家飞机
	gunBox.AllGunnerShow(hMemDC);			//显示所有炮弹
	foeplaneBox.AllFoePlaneShow(hMemDC);	//显所有敌人飞机
	blastBox.AllBlastFoePlaneShow(hMemDC);	//显示所有爆炸的敌人飞机

	::BitBlt(hdc,0,0,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::EndPaint(m_hMainwnd,&ps);
}
void CPlaneApp::OnGameRun(WPARAM nTimerID)	//需要WPARAM这个定时器编号
{
	if (nTimerID == CHANGE_SHOWID_TIMER_ID)	//改变显示ID
	{
		blastBox.ChangeShowID();
	}
	if (nTimerID == CREATE_FOEPLANE_TIMER_ID)//创建敌人飞机
	{
		foeplaneBox.CreateFoePlane(m_nhIns);
	}
	if (nTimerID == FOEPLANE_MOVE_TIMER_ID)	//敌人飞机移动
	{
		foeplaneBox.AllFoePlaneMove();
		if(this->IsGameOver() == true)
		{
			//关闭所有定时器
			::KillTimer(m_hMainwnd,BACK_MOVE_TIMER_ID);			//控制背景移动
			::KillTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID);		//控制玩家移动
			::KillTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID);		//控制玩家飞机发射炮弹
			::KillTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID);		//控制所有炮弹移动
			::KillTimer(m_hMainwnd,CREATE_FOEPLANE_TIMER_ID);	//创建敌人飞机
			::KillTimer(m_hMainwnd,FOEPLANE_MOVE_TIMER_ID);		//创建敌人移动
			::KillTimer(m_hMainwnd,CHANGE_SHOWID_TIMER_ID);		//改变显示ID
			MessageBox(0,"GameOver","提示",MB_OK);
		}
	}
	if (nTimerID == PLAYER_SEND_TIMER_ID)	//发射炮弹
	{
		player.SendGunner(m_nhIns,gunBox);
	}
	if (nTimerID == GUNNER_MOVE_TIMER_ID)	//炮弹移动
	{
		gunBox.AllGunnerMove();
		this->GunnerHitFoePlane();			//炮弹打敌人飞机
	}
	if (nTimerID == BACK_MOVE_TIMER_ID)		//背景移动
	{
		back.MoveBack();
	}
	if (nTimerID == PLAYER_MOVE_TIMER_ID)	//玩家飞机移动
	{
		if(GetAsyncKeyState(VK_LEFT))		//GetAsyncKeyState：获取键盘按下状态
			player.MovePlayer(VK_LEFT);
		if(GetAsyncKeyState(VK_RIGHT))
			player.MovePlayer(VK_RIGHT);
		if(GetAsyncKeyState(VK_UP))
			player.MovePlayer(VK_UP);
		if(GetAsyncKeyState(VK_DOWN))
			player.MovePlayer(VK_DOWN);
	}
	//重绘
	RECT rect = {0,0,380,550};
	::InvalidateRect(m_hMainwnd,&rect,FALSE);
}
void CPlaneApp::OnKeyDown(WPARAM nKey)		//需要WPARAM这个具体按键
{
	if(nKey == VK_SPACE)
	{
		blastBox.m_lstBlastFoePlane.splice(blastBox.m_lstBlastFoePlane.end(),foeplaneBox.m_lstFoePlane);
		RECT rect = {0,0,380,550};
		::InvalidateRect(m_hMainwnd,&rect,FALSE);
	}
}
void CPlaneApp::GunnerHitFoePlane()
{
	bool bflag = false;//标记炮弹是否打中敌人飞机

	//-----------遍历所有炮弹---------------------
	list<CGunner*>::iterator iteGun = gunBox.m_lstGunner.begin();
	while (iteGun != gunBox.m_lstGunner.end())
	{
		//----------遍历所有敌人飞机--------------
		list<CFoePlane*>::iterator iteFoe = foeplaneBox.m_lstFoePlane.begin();
		while (iteFoe != foeplaneBox.m_lstFoePlane.end())
		{
			//-------判断iteGun炮弹是否打中了iteFoe敌人飞机
			if ((*iteFoe)->IsGunnerHitFoePlane(*iteGun) == true)
			{
				bflag = true;
				//删除炮弹
				delete (*iteGun);
				iteGun = gunBox.m_lstGunner.erase(iteGun);
				//敌人飞机掉血
				(*iteFoe)->DownBlood();
				//判断是否爆炸
				if ((*iteFoe)->IsBoom() == true)
				{
					//把iteFoe敌人飞机放到另一个链表里显示爆炸的效果
					blastBox.m_lstBlastFoePlane.push_back(*iteFoe);
					//删除这个节点
					foeplaneBox.m_lstFoePlane.erase(iteFoe);
				}
				break;
			}
			++iteFoe;
		}
		//-------------遍历所有敌人飞机------------
		if(bflag == false)
			++iteGun;
		else
			bflag = false;
	}
}
bool CPlaneApp::IsGameOver()
{
	list<CFoePlane*>::iterator ite = foeplaneBox.m_lstFoePlane.begin();
	while (ite != foeplaneBox.m_lstFoePlane.end())
	{
		if((*ite)->IsHitPlayer(player) == true)
			return true;
		++ite;
	}
	return false;
}