// ChildView.h : CChildView 类的接口
//


#pragma once

#include "afxcmn.h"
// CChildView 窗口
 
class CChildView : public  CView
{
// 构造
	DECLARE_DYNAMIC(CChildView)
protected :
	
public:
	CChildView();
    
// 属性
public:

// 操作
public:

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();
   //  CTabCtrl  m_tab;
	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

