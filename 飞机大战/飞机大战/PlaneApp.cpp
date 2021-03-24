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
	::SetTimer(m_hMainwnd,BACK_MOVE_TIMER_ID,100,0);		//���Ʊ����ƶ�
	::SetTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID,1,0);		//��������ƶ�
	::SetTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID,350,0);		//������ҷɻ������ڵ�
	::SetTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID,10,0);		//���������ڵ��ƶ�
	::SetTimer(m_hMainwnd,CREATE_FOEPLANE_TIMER_ID,1000,0);	//�������˷ɻ�
	::SetTimer(m_hMainwnd,FOEPLANE_MOVE_TIMER_ID,30,0);		//���������ƶ�
	::SetTimer(m_hMainwnd,CHANGE_SHOWID_TIMER_ID,150,0);	//�ı���ʾID
}
void CPlaneApp::OnGameDraw()					//��ҪHWND
{
	PAINTSTRUCT ps = {0};
	HDC hdc = ::BeginPaint(m_hMainwnd,&ps);

	HDC hMemDC = ::CreateCompatibleDC(hdc);
	HBITMAP hBitmap = ::CreateCompatibleBitmap(hdc,380,550);
	::SelectObject(hMemDC,hBitmap);

	back.ShowBack(hMemDC);					//��ʾ����
	player.ShowPlayer(hMemDC);				//��ʾ��ҷɻ�
	gunBox.AllGunnerShow(hMemDC);			//��ʾ�����ڵ�
	foeplaneBox.AllFoePlaneShow(hMemDC);	//�����е��˷ɻ�
	blastBox.AllBlastFoePlaneShow(hMemDC);	//��ʾ���б�ը�ĵ��˷ɻ�

	::BitBlt(hdc,0,0,380,550,hMemDC,0,0,SRCCOPY);

	::DeleteObject(hBitmap);
	::DeleteDC(hMemDC);
	::EndPaint(m_hMainwnd,&ps);
}
void CPlaneApp::OnGameRun(WPARAM nTimerID)	//��ҪWPARAM�����ʱ�����
{
	if (nTimerID == CHANGE_SHOWID_TIMER_ID)	//�ı���ʾID
	{
		blastBox.ChangeShowID();
	}
	if (nTimerID == CREATE_FOEPLANE_TIMER_ID)//�������˷ɻ�
	{
		foeplaneBox.CreateFoePlane(m_nhIns);
	}
	if (nTimerID == FOEPLANE_MOVE_TIMER_ID)	//���˷ɻ��ƶ�
	{
		foeplaneBox.AllFoePlaneMove();
		if(this->IsGameOver() == true)
		{
			//�ر����ж�ʱ��
			::KillTimer(m_hMainwnd,BACK_MOVE_TIMER_ID);			//���Ʊ����ƶ�
			::KillTimer(m_hMainwnd,PLAYER_MOVE_TIMER_ID);		//��������ƶ�
			::KillTimer(m_hMainwnd,PLAYER_SEND_TIMER_ID);		//������ҷɻ������ڵ�
			::KillTimer(m_hMainwnd,GUNNER_MOVE_TIMER_ID);		//���������ڵ��ƶ�
			::KillTimer(m_hMainwnd,CREATE_FOEPLANE_TIMER_ID);	//�������˷ɻ�
			::KillTimer(m_hMainwnd,FOEPLANE_MOVE_TIMER_ID);		//���������ƶ�
			::KillTimer(m_hMainwnd,CHANGE_SHOWID_TIMER_ID);		//�ı���ʾID
			MessageBox(0,"GameOver","��ʾ",MB_OK);
		}
	}
	if (nTimerID == PLAYER_SEND_TIMER_ID)	//�����ڵ�
	{
		player.SendGunner(m_nhIns,gunBox);
	}
	if (nTimerID == GUNNER_MOVE_TIMER_ID)	//�ڵ��ƶ�
	{
		gunBox.AllGunnerMove();
		this->GunnerHitFoePlane();			//�ڵ�����˷ɻ�
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
	if(nKey == VK_SPACE)
	{
		blastBox.m_lstBlastFoePlane.splice(blastBox.m_lstBlastFoePlane.end(),foeplaneBox.m_lstFoePlane);
		RECT rect = {0,0,380,550};
		::InvalidateRect(m_hMainwnd,&rect,FALSE);
	}
}
void CPlaneApp::GunnerHitFoePlane()
{
	bool bflag = false;//����ڵ��Ƿ���е��˷ɻ�

	//-----------���������ڵ�---------------------
	list<CGunner*>::iterator iteGun = gunBox.m_lstGunner.begin();
	while (iteGun != gunBox.m_lstGunner.end())
	{
		//----------�������е��˷ɻ�--------------
		list<CFoePlane*>::iterator iteFoe = foeplaneBox.m_lstFoePlane.begin();
		while (iteFoe != foeplaneBox.m_lstFoePlane.end())
		{
			//-------�ж�iteGun�ڵ��Ƿ������iteFoe���˷ɻ�
			if ((*iteFoe)->IsGunnerHitFoePlane(*iteGun) == true)
			{
				bflag = true;
				//ɾ���ڵ�
				delete (*iteGun);
				iteGun = gunBox.m_lstGunner.erase(iteGun);
				//���˷ɻ���Ѫ
				(*iteFoe)->DownBlood();
				//�ж��Ƿ�ը
				if ((*iteFoe)->IsBoom() == true)
				{
					//��iteFoe���˷ɻ��ŵ���һ����������ʾ��ը��Ч��
					blastBox.m_lstBlastFoePlane.push_back(*iteFoe);
					//ɾ������ڵ�
					foeplaneBox.m_lstFoePlane.erase(iteFoe);
				}
				break;
			}
			++iteFoe;
		}
		//-------------�������е��˷ɻ�------------
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