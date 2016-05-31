
// LogicGateView.h : interface of the CLogicGateView class
//

#pragma once
#include <afxtempl.h>
#include "Gate.h"
#include "XOR.h"
#include "Wire.h"
class CLogicGateView : public CView
{
protected: // create from serialization only
	CLogicGateView();
	DECLARE_DYNCREATE(CLogicGateView)

// Attributes
public:
	CLogicGateDoc* GetDocument() const;
	
// Operations
public:
	//test 용입니다//
	XOR xor;
	XOR *newXor;
	CRect eraseRect;
	CRect makelineRect;
	CRect xorRect;
	////////////////
	

	bool gateMoveFlag;
	/*
	마우스를 클릭하면 지금 어떤 객체가 움직이는지 확인합니다
	마우스를 클릭히 하나의 객체만 움직이기 때문에 
	*/

	CPoint pos;
	CPoint	m_StartPos, m_EndPos;
	bool m_StartToMove;
	
	CRect testRect;
	bool eraseButtonClickedFlag;
	CPoint mousePoint;

//선을 저장하기 위한 member
	Wire *wire;
	CArray <Wire, Wire&> arrline;

	Wire getWire;
	int arrlineCount;
	int arrGateCount=0;
	bool lineMoveFlag;
	int changedLine = 0;
	

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void CLogicGateView::LBtnClickedCheck(CPoint point); //이 함수는 지정된 위치에 객체가 있는지 확인합니다 . 그리고 
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


