
// LogicGateView.cpp : implementation of the CLogicGateView class
//

#include "stdafx.h"
#include "XOR.h"

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LogicGate.h"
#endif

#include "LogicGateDoc.h"
#include "LogicGateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CLogicGateView


IMPLEMENT_DYNCREATE(CLogicGateView, CView)
BEGIN_MESSAGE_MAP(CLogicGateView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CLogicGateView construction/destruction

CLogicGateView::CLogicGateView()
{
	// TODO: add construction code


}

CLogicGateView::~CLogicGateView()
{
}

BOOL CLogicGateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// CLogicGateView drawing

void CLogicGateView::OnDraw(CDC* pDC)
{
	CLogicGateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	/*Test 용입니다*/
	xor.DrawXOR(pDC, xor.locateX, xor.locateY);
	
}
// CLogicGateView diagnostics

#ifdef _DEBUG
void CLogicGateView::AssertValid() const
{
	CView::AssertValid();
}

void CLogicGateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLogicGateDoc* CLogicGateView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLogicGateDoc)));
	return (CLogicGateDoc*)m_pDocument;
}
#endif //_DEBUG


// CLogicGateView message handlers




void CLogicGateView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC cdc(this);
	
	// test용입니다 //
	
	
	if (xor.GetRect().PtInRect(point) == true) {
		xor.MoveFlag = true;
		SetCapture();

	}
	
	// test용입니다 //

	//마우스가 클릭되면 클릭된 영역이 이미 그려진 영역인지 아닌지 확인한다	
	// TODO: Add your message handler code here and/or call default
	


	/*
	for(int i = 0; i < Gate::arr.GetSize(); i++) {
		if (Gate::arr.GetAt(i).GetRect().PtInRect(point) == true) {
			SetCapture();
			Gate::arr.GetAt(i).MoveFlag == true;
			m_StartPos = point;
			Gate::movedGate = i;
		}
	
	}
	*/
	

	CView::OnLButtonDown(nFlags, point);
}


void CLogicGateView::OnMouseMove(UINT nFlags, CPoint point)
{

	// TODO: Add your message handler code here and/or call default
	CClientDC cdc(this);
	

	//test용입니다// 
	if (xor.MoveFlag == true) {
		m_EndPos = point;
		CPoint pos = m_EndPos - m_StartPos;
		m_StartPos = point;
		xor.SetPoint(xor.locateX + pos.x, xor.locateY + pos.y);
		ReleaseCapture();
		Invalidate();
	
	}
		

	/*
	if (Gate::arr.GetAt(Gate::movedGate).MoveFlag == true) {
	m_StartPos = point;
	CPoint pos = m_EndPos - m_StartPos;
	m_StartPos = point;
	
	}
	*/




	
	CView::OnMouseMove(nFlags, point);
}



void CLogicGateView::OnLButtonUp(UINT nFlags, CPoint point)
{	// TODO: Add your message handler code here and/or call default

	CClientDC cdc(this);
	xor.MoveFlag = false;
	CView::OnLButtonUp(nFlags, point);
}


void CLogicGateView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
		
	CView::OnRButtonDown(nFlags, point);
}




