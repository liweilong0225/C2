
// FaceFace.h : FaceFace Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CFaceFaceApp:
// �йش����ʵ�֣������ FaceFace.cpp
//

class CFaceFaceApp : public CWinAppEx
{
public:
	CFaceFaceApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFaceFaceApp theApp;
