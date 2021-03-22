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
	virtual void OnCreateGame(){}				//需要HINSTANCE
	virtual void OnGameDraw(){}					//需要HWND
	virtual void OnGameRun(WPARAM nTimerID){}	//需要WPARAM这个定时器编号
	virtual void OnKeyDown(WPARAM nKey){}		//需要WPARAM这个具体按键
	virtual void OnKeyUp(WPARAM nKey){}			//需要WPARAM这个具体按键
	virtual void OnLButtonDown(POINT point){}	//需要一个坐标点，坐标点的获取是通过LPARAM
	virtual void OnLButtonUp(POINT point){}		//需要一个坐标点，坐标点的获取是通过LPARAM
	virtual void OnMouseMore(POINT point){}		//需要一个坐标点，坐标点的获取是通过LPARAM
};