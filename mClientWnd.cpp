// mClientWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vvvfr.h"
#include "mClientWnd.h"
#include ".\mclientwnd.h"


// CmClientWnd

IMPLEMENT_DYNAMIC(CmClientWnd, CWnd)
CmClientWnd::CmClientWnd()
{
}

CmClientWnd::~CmClientWnd()
{
}


BEGIN_MESSAGE_MAP(CmClientWnd, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CmClientWnd ��Ϣ�������


void CmClientWnd::OnPaint()
{
	// // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	CWnd::OnPaint();

	CDC *pdc  = GetDC();
	CRect rect;
	GetClientRect(&rect);

	pdc->TextOut(0,10,"д�����㲻�У����о����Ҳ��У������ӣ�Ϊ��������ʱ���ˣ�����\
		һ��Ҫѧ��VCΪ���������ף���");

	ReleaseDC(pdc);

}
