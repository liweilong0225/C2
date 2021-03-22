#pragma once
#include<Windows.h>

#define DECLARE(ThisClass)\
	CGameApp* CreateObject()\
	{\
		return new ThisClass;\
	}
class CGameApp
{
protected:
	HINSTANCE m_nhIns;
	HWND m_hMainwnd;
public:
	CGameApp()
	{
		m_nhIns = 0;
		m_hMainwnd = 0;
	}
	~CGameApp()
	{
	}
public:
	void Set(HINSTANCE hIns,HWND hwnd)
	{
		m_nhIns = hIns;
		m_hMainwnd = hwnd; 
	}
public:
	virtual void OnCreateGame(){}				//��ҪHINSTANCE
	virtual void OnGameDraw(){}					//��ҪHWND
	virtual void OnGameRun(WPARAM nTimerID){}	//��ҪWPARAM�����ʱ�����
	virtual void OnKeyDown(WPARAM nKey){}		//��ҪWPARAM������尴��
	virtual void OnKeyUp(WPARAM nKey){}			//��ҪWPARAM������尴��
	virtual void OnLButtonDown(POINT point){}	//��Ҫһ������㣬�����Ļ�ȡ��ͨ��LPARAM
	virtual void OnLButtonUp(POINT point){}		//��Ҫһ������㣬�����Ļ�ȡ��ͨ��LPARAM
	virtual void OnMouseMore(POINT point){}		//��Ҫһ������㣬�����Ļ�ȡ��ͨ��LPARAM
};