#include "PlaneApp.h"

DECLARE(CPlaneApp)
CPlaneApp::CPlaneApp(void)
{
}


CPlaneApp::~CPlaneApp(void)
{
}
void CPlaneApp::OnCreateGame()				//��ҪHINSTANCE
{
	//1.������ʼ��
	back.InitBack(m_nhIns);
	//2.��ҷɻ���ʼ��
	player.InitPlayer(m_nhIns);

	//3.�������ж�ʱ��
	::SetTimer(m_hMainwnd,BACK_MOVE_TIMER_ID,100,0);//���Ʊ����ƶ�
	::SetTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID,1,0);//��������ƶ�
	::SetTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID,350,0);//������ҷɻ������ڵ�
	::SetTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID,10,0);//���������ڵ��ƶ�

}
void CPlaneApp::OnGameDraw()					//��ҪHWND
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainwnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550);
	::SelectObject(hMemDC,hBitmap);

	back.ShowBack(hMemDC);			//��ʾ����
	player.ShowPlayer(hMemDC);		//��ʾ��ҷɻ�
	gunBox.AllGunnerShow(hMemDC);	//��ʾ�����ڵ�

	::BitBlt(hdc,0,0,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::EndPaint(m_hMainwnd,&ps);
}
void CPlaneApp::OnGameRun(WPARAM nTimerID)	//��ҪWPARAM�����ʱ�����
{
	if (nTimerID == PLAYER_SEND_TIMER_ID)	//�����ڵ�
	{
		player.SendGunner(m_nhIns,gunBox);
	}
	if (nTimerID == GUNNER_MOVE_TIMER_ID)	//�ڵ��ƶ�
	{
		gunBox.AllGunnerMove();
	}
	if (nTimerID == BACK_MOVE_TIMER_ID)		//�����ƶ�
	{
		back.MoveBack();
	}
	if (nTimerID == PLAYER_MOVE_TIMER_ID)	//��ҷɻ��ƶ�
	{
		if(GetAsyncKeyState(VK_LEFT))		//GetAsyncKeyState����ȡ���̰���״̬
			player.MovePlayer(VK_LEFT);
		if(GetAsyncKeyState(VK_RIGHT))
			player.MovePlayer(VK_RIGHT);
		if(GetAsyncKeyState(VK_UP))
			player.MovePlayer(VK_UP);
		if(GetAsyncKeyState(VK_DOWN))
			player.MovePlayer(VK_DOWN);
	}
	//�ػ�
	RECT rect = {0,0,380,550};
	::InvalidateRect(m_hMainwnd,&rect,FALSE);
}
void CPlaneApp::OnKeyDown(WPARAM nKey)		//��ҪWPARAM������尴��
{
	//player.MovePlayer(nKey);
	//RECT rect = {0,0,380,550};
	//::InvalidateRect(m_hMainwnd,&rect,FALSE);
}