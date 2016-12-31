#pragma once


// CmTreeView ��ͼ

class CmTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CmTreeView)

protected:
	CmTreeView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CmTreeView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
//	afx_msg int  OnCreate(LPCREATESTRUCT lpcs);
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


