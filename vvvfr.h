// vvvfr.h : vvvfr Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CvvvfrApp:
// �йش����ʵ�֣������ vvvfr.cpp
//

class CvvvfrApp : public CWinApp
{
public:
	CvvvfrApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CvvvfrApp theApp;
