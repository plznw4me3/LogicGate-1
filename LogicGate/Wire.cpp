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
	//startPos 는 왼쪽버튼을 클릭할때 지정되고 
	//EndPos는 마우스를 움직일때 지정됩니다.
	
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
	//선을 감싸는 polygon을 만들고 그 polygon을 클릭하고 드레그 하면 움직일수 있게 합니다.
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