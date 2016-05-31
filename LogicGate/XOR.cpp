#include "stdafx.h"	
#include "XOR.h"



// #include "stdafx.h�� ���� ���ٿ� �־� �ּž� ������ ���� �ʽ��ϴ�.
XOR::XOR() {
	width = 60;
	height = 60;
}

void XOR::SetPoint(int x, int y) {
	//  curve that code made down part of curve in XOR
	// there are 3 curve at XOR gate so 
	//BeziePT mean most right and upper side of curve 

	//
	locateX = x;
	locateY = y;

	//
	//��XOR�� �׷����� Rect �� ����ϴ�. 
	rect.SetRect(x, y, x + width, y + height);

	BezierPt[0].SetPoint(x + 10+20, y);
	BezierPt[1].SetPoint(x + 10+20 + 7, y + 3);
	BezierPt[2].SetPoint(x + 10+20 + 25, y);
	BezierPt[3].SetPoint(x + 10+50, y + 30);

	//��BeziePT2 mean most right and bottom side of curve 
	BezierPt2[0].SetPoint(x + 20+10, y + 60);
	BezierPt2[1].SetPoint(x +10+20 + 7, y + 60 - 3);
	BezierPt2[2].SetPoint(x + 10+20 + 25, y + 60);
	BezierPt2[3].SetPoint(x + 10+50, y + 30);

	//��BeziePT3 mean most left side curve at XOR Gate  
	BezierPt3[0].SetPoint(x+10, y);
	BezierPt3[1].SetPoint(x +10+ 20, y + 30);
	BezierPt3[2].SetPoint(x +10+20, y + 30);
	BezierPt3[3].SetPoint(x+10, y + 60);

	//��BeziePT4 mean most left side curve at XOR Gate
	BezierPt4[0].SetPoint(x, y);
	BezierPt4[1].SetPoint(x + 20, y + 30);
	BezierPt4[2].SetPoint(x + 20, y + 30);
	BezierPt4[3].SetPoint(x, y + 60);

	pt[0].SetPoint(x+10, y);
	pt[1].SetPoint(x +10+ 20, y);

	pt2[0].SetPoint(x+10, y + 60);
	pt2[1].SetPoint(x +10+ 20, y + 60);
	input2Rect.SetRect(x + 10, (int)y + height*(0.75), x - 20, (int)y + height*(0.75) + THICK);
	inputRect.SetRect(x + 10, (int)y + height*(0.25), x - 20, (int)y + height*(0.25) + THICK);
	outputRect.SetRect(x + width, y + height*(0.5), x+width + 30, y + height*(0.5) + THICK);
	//x~x+60 , y~y+60
	
}
CPoint* XOR::GetBezierPt() {
	return 0;
}
void XOR::DrawXOR(CDC *pDC, int x, int  y) {

	SetPoint(x, y);
	
	pDC->PolyBezier(BezierPt, 4);
	pDC->PolyBezier(BezierPt2, 4);
	pDC->PolyBezier(BezierPt3, 4);
	pDC->PolyBezier(BezierPt4, 4);
	pDC->Polyline(pt, 2);
	pDC->Polyline(pt2, 2);
	pDC->Rectangle(inputRect);
	pDC->Rectangle(input2Rect);
	pDC->Rectangle(outputRect);
}


bool XOR::clieckedCheck(CPoint point) {
	if (this->inputRect.PtInRect(point)) {
		return true;
	}
	else if (this->input2Rect.PtInRect(point)) {
		return true;
	}
	else if (this->outputRect.PtInRect(point)) {
		return true;
	}
		return false;
}