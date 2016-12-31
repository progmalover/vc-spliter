#pragma once
#include "afxcmn.h"



// CmFormView ������ͼ

class CmFormView : public CFormView
{
	DECLARE_DYNCREATE(CmFormView)

protected:
	CmFormView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CmFormView();

public:
	enum { IDD = IDD_MFORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEditCut();
	CTabCtrl m_tab;
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg void OnDestroy();
//	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	virtual void OnInitialUpdate();
};


