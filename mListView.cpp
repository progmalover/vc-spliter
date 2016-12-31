// mListView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vvvfr.h"
#include "mListView.h"
#include ".\mlistview.h"


// CmListView

IMPLEMENT_DYNCREATE(CmListView, CListView)

CmListView::CmListView()
{
}

CmListView::~CmListView()
{
}

BEGIN_MESSAGE_MAP(CmListView, CListView)
//	ON_WM_CREATE()
ON_WM_CREATE()
END_MESSAGE_MAP()


// CmListView ���

#ifdef _DEBUG
void CmListView::AssertValid() const
{
	CListView::AssertValid();
}

void CmListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG


// CmListView ��Ϣ�������

BOOL CmListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
    cs.style  |= LVS_REPORT ;
	cs.dwExStyle |=LVS_EX_FULLROWSELECT ;
	return CListView::PreCreateWindow(cs);
}


int CmListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
    LV_COLUMN item;
	CRect  rect;

	CListCtrl  &ltctr  = GetListCtrl();
	GetWindowRect(&rect);
	
	item.mask = LVCF_TEXT|LVCF_WIDTH|LVCF_FMT|LVCF_SUBITEM;
	item.pszText = "this is an demo";
    item.fmt = LVCFMT_CENTER ;
	item.cx  = 120 ;

	for(int i = 0;i < 3;i++)
	{
		item.iSubItem = i;
		ltctr.InsertColumn(0,&item);
	}
	return 0;
}
