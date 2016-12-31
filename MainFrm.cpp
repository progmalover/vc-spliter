// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "vvvfr.h"

#include "MainFrm.h"
#include ".\mainfrm.h"
#include "mFormView.h"
#include "mTreeView.h"
#include "mListView.h"
#include "mView.h"
#include "ChildView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// 创建一个视图以占用框架的工作区,原始初试化CVIEW的地方
	/*if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}*/
   


	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	// TODO: 如果不需要工具栏可停靠，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	//// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	//// 样式

	//cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	//cs.lpszClass = AfxRegisterWndClass(0);
	//cs.hMenu = NULL;
	//cs.style = WS_BORDER|WS_SYSMENU|WS_MINIMIZEBOX ;
	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	//// 让视图第一次尝试该命令
	//if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//	return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
	CmSplitterWnd  mp;
	CmSplitterWnd  mp1;
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	CCreateContext  ct;
	CRect   rc;

	GetClientRect(&rc);
	memset(&ct,0,sizeof(ct));

    pContext = &ct;

	m_splitter.CreateStatic(this,2,1);
	ct.m_pNewViewClass  = RUNTIME_CLASS(CmView);

	m_splitter.CreateView(0,0,pContext->m_pNewViewClass,CSize(rc.Width(),60),NULL);
	m_splitter.CreateView(1,0, mp.GetRuntimeClass(),CSize(rc.Width(),rc.Height()-60),NULL);
    
	mp.CreateStatic(&m_splitter,1,2,  WS_CHILD|WS_VISIBLE|WS_BORDER, AFX_IDW_PANE_FIRST + 16);
	mp.CreateView(0,0,RUNTIME_CLASS(CmTreeView),CSize(rc.Width()/2,rc.Height()/2),NULL);
	mp.CreateView(0,1,mp1.GetRuntimeClass(),CSize(rc.Width()/2,rc.Height()/2),NULL);
	
	mp1.CreateStatic(&mp,2,1,  WS_CHILD|WS_VISIBLE|WS_BORDER, AFX_IDW_PANE_FIRST + 1);
	mp1.CreateView(0,0,RUNTIME_CLASS(CmFormView),CSize(rc.Width()/4,rc.Height()/4),NULL);
	mp1.CreateView(1,0,RUNTIME_CLASS(CmFormView),CSize(rc.Width()/4,rc.Height()/4),NULL);

	SetActiveView((CView*)m_splitter.GetPane(0,0));
	return TRUE;
}
