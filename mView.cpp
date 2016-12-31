// mView.cpp : 实现文件
//

#include "stdafx.h"
#include "vvvfr.h"
#include "mView.h"
#include ".\mview.h"
#include "afximpl.h"
#include "mClientWnd.h"


// CmView

IMPLEMENT_DYNCREATE(CmView, CView)

CmView::CmView()
{
}

CmView::~CmView()
{
}

BEGIN_MESSAGE_MAP(CmView, CView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CmView 绘图

void CmView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	CRect  rect;
	GetClientRect(&rect);
	pDC->FillRect(&rect,CBrush::FromHandle(afxData.hbrBtnFace));
}


// CmView 诊断

#ifdef _DEBUG
void CmView::AssertValid() const
{
	CView::AssertValid();
}

void CmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CmView 消息处理程序
HWND  hwnd = NULL ;
void CmView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
    CRect rect;
	GetClientRect(&rect);
	if(m_tab.GetSafeHwnd())
	{
		m_tab.MoveWindow(&rect,1);
	}else
		return;
	
	if(hwnd)
	{
		CWnd *pwnd  = m_tab.GetParent();
		pwnd->GetClientRect(&rect);

		rect.top += 25;
		rect.bottom -= 10;
		::MoveWindow(hwnd,rect.left,rect.top,rect.right,rect.bottom,1);
	}
}
CmClientWnd  tview;
int CmView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(!m_tab.Create(WS_CHILD|WS_VISIBLE,CRect(0,0,0,0),this,1234))
	{
       ASSERT(FALSE);
	   return -1;
	}

	m_tab.InsertItem(0,"demo0");
	m_tab.InsertItem(1,"demo1");
	m_tab.InsertItem(2,"demo2");
	m_tab.InsertItem(3,"demo3");
	
	CRect  rect;
	CWnd *pwnd  = m_tab.GetParent();
	pwnd->GetClientRect(&rect);

	rect.top += 25;
	rect.bottom -= 10;

	  hwnd  = ::CreateWindow("STATIC","demo for wanglei",
		  WS_CLIPCHILDREN | WS_VSCROLL |WS_HSCROLL|SS_GRAYRECT|WS_CHILD,
			rect.left,rect.top ,rect.right,rect.bottom,m_tab.GetSafeHwnd(),NULL,NULL,NULL);

	::SetWindowText(hwnd,"this is an demo write for wanglei to learn vc well.");
	m_tab.ShowWindow(SW_SHOW);
	tview.SubclassWindow(hwnd);
	::ShowWindow(hwnd,SW_SHOW);

	return 0;
}

BOOL CmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	return CView::PreCreateWindow(cs);
}

//BOOL CmView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	BOOL  ret  =  CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//	 
//	return ret;
//}

void CmView::OnDestroy()
{
	
	
	CView::OnDestroy();
	tview.UnsubclassWindow();
	
}
