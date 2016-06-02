
// LogicGateView.cpp : implementation of the CLogicGateView class
//

#include "stdafx.h"
#include "Gate.h"
#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "NOT.h"
#include "XOR.h"
#include "DPP.h"
#include "TPP.h"
#include "JKPP.h"
#include "Wire.h"
#include "Clock.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LogicGate.h"
#endif

#include "MainFrm.h"
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
	ON_COMMAND(STOP_WATCH, &CLogicGateView::OnStopWatch)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CLogicGateView construction/destruction

//CMainFrame *pFrame;
//CLogicGateDoc *doc;
CLogicGateView::CLogicGateView()
{
	// TODO: add construction code
	//���� ����� CArray �� ����ϴ�
	/*
	arrline.SetSize(10);
	arrlineCount = 0;
	wire = new Wire();
	lineMoveFlag = false;
	eraseRect.SetRect(0,400,100,500);
	xorRect.SetRect(0,0,100,100);
	*/
	makeLogic = false;
	sw_flag = false;
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
	// TODO: add draw code for native data here
	/*Test ���Դϴ�*/
	/*
	xor.DrawXOR(pDC, xor.locateX, xor.locateY);
	testRect.SetRect(100, 100, 300, 300);
	pDC->Rectangle(100, 100, 300, 300);
	pDC->Rectangle(0, 0, 100, 100);

	//////////////////////////////////////////////////////////Wiring///////////////////
	for (int i = 0; i <= arrlineCount; i++) {
		arrline.GetAt(i).DrawLine(pDC);
	}
	*/
	/* ���� ���۸� */
	CDC *dc = GetDC();

	CRect rect;
	GetClientRect(&rect);

	// �޸� DC ����
	CDC memDC;
	CBitmap *pOldBitmap, bitmap;

	// ȭ�� DC�� ȣȯ�Ǵ� �޸� DC ��ü�� ����
	memDC.CreateCompatibleDC(dc);

	// ���������� ȭ�� DC�� ȣȯ�Ǵ� Bitmap ����
	bitmap.CreateCompatibleBitmap(dc, rect.Width(), rect.Height());

	pOldBitmap = (CBitmap*)memDC.SelectObject(&bitmap);
	memDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);	// ������� �ʱ�ȭ

	// �޸� DC�� �׸���
	DrawImage(&memDC);

	// �޸� DC�� ȭ�� DC�� ��� ����
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

	memDC.SelectObject(pOldBitmap);
	memDC.DeleteDC();
	bitmap.DeleteObject();
}
// CLogicGateView diagnostics

/* �޸� DC�� �׸��� */
void CLogicGateView::DrawImage(CDC *dc) {
	CLogicGateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int cnt = pDoc->logic_size;
	int nand_cnt = 0;
	dc->TextOutW(cnt, cnt, _T("ABC %d"), cnt);
	/*while(cnt != 0) {
		CPoint point;
		point.x = pDoc->pos[pDoc->pos.GetSize() - cnt].x;
		point.y = pDoc->pos[pDoc->pos.GetSize() - cnt].y;

		dc->TextOutW(point.x, point.y, _T("QWE %d"), cnt);
		dc->TextOutW(cnt, cnt, _T("ZXC %d"), cnt);
		nand.createLogic(nand.logic, point);
		//nand.logic[nand_cnt].rotate = pDoc->r[pDoc->pos.GetSize() - 1 - cnt];
		cnt--;
	}*/

	if (makeLogic) {
		pDoc->id.Add(id);
		pDoc->pos.Add(logic_pos);
		pDoc->r.Add(rotate);
		pDoc->SetModifiedFlag();
		makeLogic = false;
	}

	if(sw_flag)
		clk.DrawCLK(dc);
	else
	{
		nand.drawLogic(nand.logic, dc);
	}

	
	//if (doc->OnNewDocument()) {
		//nand.logic.RemoveAll();
	//}
	//else {
	//}
}

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
	nand.createLogic(nand.logic, point);
	id = 1;
	pos = nand.logic[nand.logic.GetSize() - 1].pos;
	rotate = nand.logic[nand.logic.GetSize() - 1].rotate;

	makeLogic = true;


	CLogicGateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->pos.Add(point);
	pDoc->r.Add(nand.logic[0].rotate);
	pDoc->id.Add(id);

	/* STOP WATCH */
	if(sw_flag){
		if (clk.flag) {
			int yn = MessageBox(L"������ Ŭ���� �����Ͻðڽ��ϱ�?", NULL, MB_YESNO);
			if (yn == IDYES) {			//����Ŭ����
				clk.flag = false;
				KillTimer(0);
			}
			else {
				clk.flag = true;
			}
		}
		else {
			int yn = MessageBox(L"������ Ŭ���� ���۽�Ű�ðڽ��ϱ�?", NULL, MB_YESNO);
			if (yn == IDYES)
			{
				clk.flag = true;
				SetTimer(0, 10, NULL);	//1ms���� set
				Invalidate(true);
			}
			else {
				clk.flag = false;
			}
		}
	}
	/*
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
	*/
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
		Invalidate(false);	
	}

//////////////////////////////////////////���콺�� ������ ���� ����ϴ� �Ǵ� �����ϴϴ�//////////////////////////

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
	/*
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
	}*/
	CView::OnLButtonUp(nFlags, point);
}


void CLogicGateView::OnRButtonDown(UINT nFlags, CPoint point){
	// TODO: Add your message handler code here and/or call default
	
	if (!clk.flag)
		clk.Reset();
	
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

void CLogicGateView::OnStopWatch()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	sw_flag = true;
	
	clk.Reset();
}


int CLogicGateView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(0, 10, NULL);	// 10ms ����
	clk.flag = true;

	return 0;
}


void CLogicGateView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	clk.flag = false;
	KillTimer(0);
}


void CLogicGateView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	clk.flag = true;
	clk.IncCLK();
	clk.StopWatch(clk.clk_sec, clk.clk_ms);
	Invalidate(false);

	CView::OnTimer(nIDEvent);
}
