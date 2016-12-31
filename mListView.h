#pragma once


// CmListView 视图

class CmListView : public CListView
{
	DECLARE_DYNCREATE(CmListView)

protected:
	CmListView();           // 动态创建所使用的受保护的构造函数
	virtual ~CmListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


