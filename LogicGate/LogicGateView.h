
// LogicGateView.h : interface of the CLogicGateView class
//

#pragma once
#include <afxtempl.h>
#include "Gate.h"
#include "XOR.h"
class CLogicGateView : public CView
{
protected: // create from serialization only
	CLogicGateView();
	DECLARE_DYNCREATE(CLogicGateView)

// Attributes
public:
	CLogicGateDoc* GetDocument() const;
	int CLogicGateView::checkRect(CPoint point);
// Operations
public:
	//test 용입니다//
	XOR xor;
	//test 용입니다//

	CPoint pos;
	CPoint	m_StartPos, m_EndPos;
	bool m_StartToMove;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CLogicGateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in LogicGateView.cpp
inline CLogicGateDoc* CLogicGateView::GetDocument() const
   { return reinterpret_cast<CLogicGateDoc*>(m_pDocument); }
#endif


