// mTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "vvvfr.h"
#include "mTreeView.h"
#include ".\mtreeview.h"

// CmTreeView

IMPLEMENT_DYNCREATE(CmTreeView, CTreeView)

CmTreeView::CmTreeView()
{
}

CmTreeView::~CmTreeView()
{
}

BEGIN_MESSAGE_MAP(CmTreeView, CTreeView)
//ON_WM_CREATE()
//ON_WM_CREATE()
//ON_WM_CREATE()
ON_WM_CREATE()
END_MESSAGE_MAP()


// CmTreeView 诊断

#ifdef _DEBUG
void CmTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CmTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG


// CmTreeView 消息处理程序
//int  CmTreeView:: OnCreate(LPCREATESTRUCT lpcs)
//{
//		MessageBox("sdfsdfdfee","dddddrr",MB_OK);
//		return 1;
//}
BOOL CmTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	cs.style  =WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER
  | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES
  | TVS_DISABLEDRAGDROP|TVS_CHECKBOXES|TVS_FULLROWSELECT ;
	return CTreeView::PreCreateWindow(cs);
}


BOOL CmTreeView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	int ret = CTreeView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
	
	if(ret)
	{
		CTreeCtrl  &tr  = GetTreeCtrl();
		HTREEITEM  itm = tr.InsertItem("this is an demo!");
		tr.InsertItem("hello world",itm);
        tr.InsertItem("hello ",itm);
		tr.InsertItem("blue ",itm);
		tr.InsertItem("red ",itm);
		tr.InsertItem("yellow ",itm);
	}

	
	return ret;
}

int CmTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
   // MessageBox("CmTreeView::OnCreate","dddddrr",MB_OK);
	return 0;
}
