#include "stdafx.h"
#include "mSplitterWnd.h"
#include ".\msplitterwnd.h"
#include "afximpl.h"
//extern AFX_DATA AUX_DATA afxData;

IMPLEMENT_DYNAMIC(CmSplitterWnd,CSplitterWnd)

BEGIN_MESSAGE_MAP(CmSplitterWnd, CSplitterWnd)
 
END_MESSAGE_MAP()
CmSplitterWnd::CmSplitterWnd() 
{

}

CmSplitterWnd:: ~CmSplitterWnd()
{

}
void CmSplitterWnd::OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect)
{
	// TODO: 在此添加专用代码和/或调用基类
   
	CSplitterWnd::OnDrawSplitter(pDC, nType, rect);
	//CDC  *dc = GetWindowDC();
	//dc->FillRect(rect,CBrush::FromHandle(afxData));
	//ReleaseDC(dc);
}
