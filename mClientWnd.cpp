// mClientWnd.cpp : 实现文件
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



// CmClientWnd 消息处理程序


void CmClientWnd::OnPaint()
{
	// // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CWnd::OnPaint();

	CDC *pdc  = GetDC();
	CRect rect;
	GetClientRect(&rect);

	pdc->TextOut(0,10,"写程序你不行，读研究生我不行，大雷子，为国捐躯的时候到了！！！\
		一定要学好VC为国家做贡献！！");

	ReleaseDC(pdc);

}
