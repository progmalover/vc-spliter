// ChildView.h : CChildView ��Ľӿ�
//


#pragma once

#include "afxcmn.h"
// CChildView ����
 
class CChildView : public  CView
{
// ����
	DECLARE_DYNAMIC(CChildView)
protected :
	
public:
	CChildView();
    
// ����
public:

// ����
public:

// ��д
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CChildView();
   //  CTabCtrl  m_tab;
	// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

