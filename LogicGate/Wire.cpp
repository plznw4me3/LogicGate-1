#include "stdafx.h"
#include "Wire.h"


Wire::Wire()
{
	LBtnClickedFlag = false;
	EndPointRect_LBtnClickFlag = false;
}


Wire::~Wire()
{
}


bool Wire::makeLine(CDC *dc , CPoint point) {	
	dc->MoveTo(StartPos);
	dc->LineTo(EndPos.x, StartPos.y);
	dc->MoveTo(EndPos.x, StartPos.y);
	dc->LineTo(EndPos.x, EndPos.y);
	StartPos = point;
	return true;
};

void Wire::DrawLine(CDC *pDC) {
	//startPos �� ���ʹ�ư�� Ŭ���Ҷ� �����ǰ� 
	//EndPos�� ���콺�� �����϶� �����˴ϴ�.
	
	CPen pen(PS_SOLID, THICK, RGB(0, 0, 0));

	rect[0].SetRect(StartPos.x, StartPos.y, EndPos.x, StartPos.y + THICK);
	rect[1].SetRect(EndPos.x-THICK, StartPos.y+THICK, EndPos.x, EndPos.y + THICK);
	EndPointRect.SetRect(EndPos.x + THICK*5, EndPos.y + THICK, EndPos.x - THICK * 5, EndPos.y - THICK * 5);

	pDC->Rectangle(rect[0]);
	pDC->Rectangle(rect[1]);
	pen.CreatePen(PS_SOLID, THICK, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	pDC->Rectangle(EndPointRect);
	
	pen.CreatePen(PS_SOLID, THICK, RGB(0, 0, 0));
	pDC->SelectObject(pen);
	pDC->SelectObject(&pen);
	pDC->MoveTo(StartPos);
	pDC->LineTo(EndPos.x, StartPos.y);
	pDC->MoveTo(EndPos.x, StartPos.y);
	pDC->LineTo(EndPos.x, EndPos.y);
		
	/////////////////////////////////////////////////////////////////////////
	//���� ���δ� polygon�� ����� �� polygon�� Ŭ���ϰ� �巹�� �ϸ� �����ϼ� �ְ� �մϴ�.
	polyPoint[0].SetPoint(StartPos.x, StartPos.y);
	polyPoint[1].SetPoint(EndPos.x, StartPos.y);
	polyPoint[2].SetPoint(EndPos.x, EndPos.y);
	polyPoint[3].SetPoint(EndPos.x - THICK, EndPos.y);
	polyPoint[4].SetPoint(EndPos.x - THICK, StartPos.y + THICK);
	polyPoint[5].SetPoint(StartPos.x, StartPos.y + THICK);
	///////////////////////////////////////////////////////////////////////

}

/*
Wire& Wire::operator = (const Wire & w)
{
	
	return *this;
}

*/