// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	// ����һ����ͼ��ռ�ÿ�ܵĹ�����,ԭʼ���Ի�CVIEW�ĵط�
	/*if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("δ�ܴ�����ͼ����\n");
		return -1;
	}*/
   


	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	// TODO: �������Ҫ��������ͣ������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	//// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	//// ��ʽ

	//cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	//cs.lpszClass = AfxRegisterWndClass(0);
	//cs.hMenu = NULL;
	//cs.style = WS_BORDER|WS_SYSMENU|WS_MINIMIZEBOX ;
	return TRUE;
}


// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	//// ����ͼ��һ�γ��Ը�����
	//if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//	return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
	CmSplitterWnd  mp;
	CmSplitterWnd  mp1;
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
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
