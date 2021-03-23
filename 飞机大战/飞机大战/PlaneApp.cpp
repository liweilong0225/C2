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
	::SetTimer(m_hMainwnd,BACK_MOVE_TIMER_ID,100,0);//控制背景移动
	::SetTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID,1,0);//控制玩家移动
	::SetTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID,350,0);//控制玩家飞机发射炮弹
	::SetTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID,10,0);//控制所有炮弹移动

}
void CPlaneApp::OnGameDraw()					//需要HWND
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainwnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550);
	::SelectObject(hMemDC,hBitmap);

	back.ShowBack(hMemDC);			//显示背景
	player.ShowPlayer(hMemDC);		//显示玩家飞机
	gunBox.AllGunnerShow(hMemDC);	//显示所有炮弹

	::BitBlt(hdc,0,0,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::EndPaint(m_hMainwnd,&ps);
}
void CPlaneApp::OnGameRun(WPARAM nTimerID)	//需要WPARAM这个定时器编号
{
	if (nTimerID == PLAYER_SEND_TIMER_ID)	//发射炮弹
	{
		player.SendGunner(m_nhIns,gunBox);
	}
	if (nTimerID == GUNNER_MOVE_TIMER_ID)	//炮弹移动
	{
		gunBox.AllGunnerMove();
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
	//player.MovePlayer(nKey);
	//RECT rect = {0,0,380,550};
	//::InvalidateRect(m_hMainwnd,&rect,FALSE);
}