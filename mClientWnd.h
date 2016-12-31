#pragma once


// CmClientWnd

class CmClientWnd : public CWnd
{
	DECLARE_DYNAMIC(CmClientWnd)

public:
	CmClientWnd();
	virtual ~CmClientWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


