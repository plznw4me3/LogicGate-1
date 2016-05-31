
// LogicGateView.cpp : implementation of the CLogicGateView class
//

#include "stdafx.h"
#include "XOR.h"
#include "Wire.h"
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
	//���� ����� CArray �� ����ϴ�
	arrline.SetSize(10);
	arrlineCount = 0;
	wire = new Wire();
	lineMoveFlag = false;
	eraseRect.SetRect(0,400,100,500);
	xorRect.SetRect(0,0,100,100);

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
	/*Test ���Դϴ�*/
	xor.DrawXOR(pDC, xor.locateX, xor.locateY);
	testRect.SetRect(100, 100, 300, 300);
	pDC->Rectangle(100, 100, 300, 300);
	pDC->Rectangle(0, 0, 100, 100);

	//////////////////////////////////////////////////////////Wiring///////////////////
	for (int i = 0; i <= arrlineCount; i++) {
		arrline.GetAt(i).DrawLine(pDC);
	}

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
	// test���Դϴ� //	
	if (xor.GetRect().PtInRect(point) == true) {
		xor.MoveFlag = true;
		SetCapture();
	}

////////////////////////////////////////////////////////////////////////
//���콺�� Ŭ���ϸ� �װ��� ��ü�� �ִ��� �ƴϸ� ��������� Ȯ���մϴ�.
//��ü�� ������ �ش� flag�� true�� ���մϴ�.
		LBtnClickedCheck(point);
		m_StartPos = point;	
/////////////////////���콺 ���ʹ�ư Ŭ��/////////////XOR ��ü�� ����ϴ�/////////////
	
////////////////////////////////////////////////////���� ����ϴ�/////////////////////
	if (testRect.PtInRect(point)) {
		wire->StartPos = point;
		wire->makeLineFlag = true;
		arrline.InsertAt(arrlineCount, *wire);
	}
//////////////////////////////////////////////////���� �����մϴ�//////////////////
	else if (arrline.GetAt(changedLine).EndPointRect_LBtnClickFlag) {
		wire->StartPos = point;
		wire->makeLineFlag = true;
		arrline.InsertAt(arrlineCount, *wire);
	}
 /////////////////////////////////////////////////////tool box���� erase button�� Ŭ���մϴ�///////////////////////
	for (int i = 0; i < arrlineCount; i++) {
		}
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
	//���콺�� Ŭ���Ǹ� Ŭ���� ������ �̹� �׷��� �������� �ƴ��� Ȯ���Ѵ�	
	// TODO: Add your message handler code here and/or call defaulf
	CView::OnLButtonDown(nFlags, point);
}


void CLogicGateView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC cdc(this);
///////////<MOUSE MOVE>/////////��ü�� �����Դϴ�.//////////////////////// 
	if (xor.MoveFlag ) {
		m_EndPos = point;
		CPoint pos = m_EndPos - m_StartPos;
		m_StartPos = point;
		xor.SetPoint(xor.locateX + pos.x, xor.locateY + pos.y);
		ReleaseCapture();
		Invalidate();	
	}

//////////////////////////////////////////���콺�� ������ ���� ����ϴ� �Ǵ� �����ϴϴ�//////////////////////////
	else if (arrline.GetAt(arrlineCount).makeLineFlag) {
		arrline.GetAt(arrlineCount).EndPos = point;
		if (xor.clieckedCheck(point)) {
		
		
		}
	
		Invalidate();
	}
//////////////////////////////////////////���̾ �����Դϴ� ./////////////////////////////////////
	else if (lineMoveFlag) {
		m_EndPos = point;
		pos = m_EndPos - m_StartPos;
		m_StartPos = point;
		CPoint preStartPos = arrline.GetAt(changedLine).StartPos;
		CPoint preEndPos = arrline.GetAt(changedLine).EndPos;
		arrline.GetAt(changedLine).StartPos = preStartPos + pos;
		arrline.GetAt(changedLine).EndPos = preEndPos + pos;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}



void CLogicGateView::OnLButtonUp(UINT nFlags, CPoint point)
{	// TODO: Add your message handler code here and/or call default
	CClientDC cdc(this);
	xor.MoveFlag = false;
	Wire testwire;
	if (arrline.GetAt(arrlineCount).makeLineFlag) {
		arrline.GetAt(arrlineCount).makeLineFlag = false;
		CString str;
		str.Format(_T("%d"), arrlineCount);
		AfxMessageBox(str);
		arrlineCount++;
	}
	else if (lineMoveFlag) {
		lineMoveFlag = false;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CLogicGateView::OnRButtonDown(UINT nFlags, CPoint point){
	// TODO: Add your message handler code here and/or call default
	
	
	CView::OnRButtonDown(nFlags, point);
}



void CLogicGateView::LBtnClickedCheck(CPoint point){
//////////////line�� Ŭ������� Ȯ���մϴ� �׸��� ���� ���� �簢���� Ŭ��������� Ȯ���մϴ�//////////////////////
	for (int i = 0; i <= arrlineCount; i++) {
		getWire = arrline.GetAt(i);
		if (getWire.rect[0].PtInRect(point) || getWire.rect[1].PtInRect(point))
		{
			getWire.LBtnClickedFlag = true;
			lineMoveFlag = true;
			changedLine = i;
		}
		else if (getWire.EndPointRect.PtInRect(point)) {
					
			getWire.EndPointRect_LBtnClickFlag = true;
			AfxMessageBox(_T("click"));
		}




	}
///////////////////////////////////////////////////////////////////////////////
}