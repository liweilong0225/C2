
// Clean.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Clean.h"
#include "CleanDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCleanApp

BEGIN_MESSAGE_MAP(CCleanApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCleanApp ����

CCleanApp::CCleanApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴����ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCleanApp ����

CCleanApp theApp;


// CCleanApp ��ʼ��

BOOL CCleanApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CCleanDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô�����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô�����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

CString CCleanApp::GetBrowseForFloder()
{
	WCHAR wszFolderName[MAX_PATH] = {0};//����ѡ����ļ��е���
	WCHAR wszFolderPath[MAX_PATH] = {0};//����ѡ����ļ��е�·��

	BROWSEINFO bi;
	bi.hwndOwner = m_pMainWnd->m_hWnd;//������ӵ������Ի���
	bi.pidlRoot = NULL;					//NULL���������濪ʼ����
	bi.pszDisplayName = wszFolderName;//����ѡ�������
	bi.lpszTitle = _T("��ѡ��");	//����
	bi.ulFlags = 0;					//�Ƿ����������Ŀؼ�
	bi.lpfn = 0;					//��������
	bi.lParam = 0;
	bi.iImage = 0;

	PIDLIST_ABSOLUTE pa = ::SHBrowseForFolder(&bi);//��ʾ�����ļ��еĶԻ���
	if (pa != 0)
	{
		//��ȡѡ���ļ��е�·��
		if(::SHGetPathFromIDList(pa,wszFolderPath) == TRUE)
		{
			return wszFolderPath;
		}
	}


	return _T("");
}
