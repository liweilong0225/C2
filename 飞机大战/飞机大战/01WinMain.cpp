#include <windows.h>
#include"CGameApp.h"

LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE hIns = 0;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdLine,int nShowCmd)
{
	//-----------------------------------------------------
	HWND hwnd = 0;
	MSG msg;       //  װ��Ϣ�Ľṹ��
	WNDCLASSEX wndclass;
	//-----------------------------------------------------
	
	hIns = hInstance;

	//----------------------�������ڹ���-----------------------------------
	//  1. ���
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wndclass.hCursor = LoadCursor(0,MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WindowProc;
	wndclass.lpszClassName = "�ɻ���ս";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_HREDRAW|CS_VREDRAW;
	// 2.  ע��
	if(RegisterClassEx(&wndclass) == FALSE)
	{
		MessageBox(0,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}
	//  3.  ����
	hwnd = CreateWindow("�ɻ���ս","�ɻ���ս",WS_OVERLAPPEDWINDOW,0,0,380+16,550+38,0,0,hInstance,0);
	if(hwnd == 0)
	{
		MessageBox(0,"����ʧ��","��ʾ",MB_OK);
		return 0;	
	}
	//  4.  ��ʾ����
	ShowWindow(hwnd,SW_SHOW);
	//---------------------------�������ڹ���------------------------------------------------



	//----------------------------��Ϣѭ��-------------------------------------------
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//----------------------------��Ϣѭ��-------------------------------------------

	return 0;
}


//=================================������Ϣ========================================================
CGameApp* pApp = 0;
CGameApp* CreateObject();//����������
LRESULT CALLBACK WindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		pApp = CreateObject();//����һ������Ϸ���������
		if(pApp != 0)
		{
			pApp->Set(hIns,hwnd);//���þ��
			pApp->OnCreateGame();//��ʼ����Ϸ��������Դ
		}
		break;
	case WM_PAINT:
		if(pApp != 0)
		{
			pApp->OnGameDraw();
		}
		break;
	case WM_TIMER:
		if(pApp != 0)
		{
			pApp->OnGameRun(wParam);
		}
		break;
	case WM_KEYDOWN:
		if(pApp != 0)
		{
			pApp->OnKeyDown(wParam);
		}
		break;
	case WM_KEYUP:
		if(pApp != 0)
		{
			pApp->OnKeyUp(wParam);
		}
		break;
	case WM_LBUTTONDOWN:
		if(pApp != 0)
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pApp->OnLButtonDown(point);
		}
		break;
	case WM_LBUTTONUP:
		if(pApp != 0)
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pApp->OnLButtonUp(point);
		}
		break;
	case WM_MOUSEMOVE:
		if(pApp != 0)
		{
			POINT point;
			point.x = LOWORD(lParam);
			point.y = HIWORD(lParam);
			pApp->OnMouseMore(point);
		}
		break;
	case WM_CLOSE:
		delete pApp;
		pApp = 0;
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc( hwnd, uMsg, wParam, lParam);
}