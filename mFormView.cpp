// mFormView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vvvfr.h"
#include "mFormView.h"
#include ".\mformview.h"


// CmFormView

IMPLEMENT_DYNCREATE(CmFormView, CFormView)

CmFormView::CmFormView()
	: CFormView(CmFormView::IDD)
{
}

CmFormView::~CmFormView()
{
}

void CmFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);


}

BEGIN_MESSAGE_MAP(CmFormView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
//	ON_WM_SIZE()
ON_WM_CREATE()
ON_WM_SIZE()
ON_WM_DESTROY()
END_MESSAGE_MAP()


// CmFormView ���

#ifdef _DEBUG
void CmFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CmFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CmFormView ��Ϣ��������

void CmFormView::OnBnClickedButton1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	//
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































MessageBox("asdfasdf","asdf",MB_OK);
	//CDialog Dialog(IDD_MFORMVIEW);
	//Dialog.DoModal();
}

void CmFormView::OnEditCut()
{
	// TODO: �ڴ�����������������
	MessageBox("cut off","asdf",MB_OK);
}

//void CmFormView::OnSize(UINT nType, int cx, int cy)
//{
//	CFormView::OnSize(nType, cx, cy);
//	
//	// TODO: �ڴ˴�������Ϣ�����������
//}

int CmFormView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	
    ModifyStyle(WS_VSCROLL|WS_HSCROLL  ,0);
	return 0;
}

void CmFormView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
    CRect  rect;
	GetClientRect(&rect);

	if(m_tab.GetSafeHwnd())
		m_tab.MoveWindow(&rect,1);
	// TODO: �ڴ˴�������Ϣ�����������

}

BOOL CmFormView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ�����ר�ô����/����û���
	//cs.style &= ~WS_VSCROLL ;
	return CFormView::PreCreateWindow(cs);
}

void CmFormView::OnDestroy()
{
	CFormView::OnDestroy();
	 
	// TODO: �ڴ˴�������Ϣ�����������
}

 

void CmFormView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
      CRect  rect;
	GetClientRect(&rect);

	if(m_tab.GetSafeHwnd())
		m_tab.MoveWindow(&rect,1);
	 
}