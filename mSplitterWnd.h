#include "afxext.h"

#pragma once
class CmSplitterWnd  : public CSplitterWnd
{
protected:
   DECLARE_DYNAMIC(CmSplitterWnd)
public :
	CmSplitterWnd();
	~CmSplitterWnd();
 DECLARE_MESSAGE_MAP()
 virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
};