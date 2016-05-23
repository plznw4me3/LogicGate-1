#include "stdafx.h"	
#include "XOR.h"


// #include "stdafx.h을 가장 윗줄에 넣어 주셔야 오류가 나지 않습니다.
XOR::XOR() {
	width = 60;
	height = 60;
	arr.SetSize(10);
	arr.Add(pos);
}

void XOR::SetPoint(int x, int y) {
	//  curve that code made down part of curve in XOR
	// there are 3 curve at XOR gate so 
	//BeziePT mean most right and upper side of curve 

	//
	locateX = x;
	locateY = y;

	//
	//▼XOR이 그려지는 Rect 을 만듭니다. 
	rect.SetRect(x, y, x + width, y + height);

	BezierPt[0].SetPoint(x + 10+20, y);
	BezierPt[1].SetPoint(x + 10+20 + 7, y + 3);
	BezierPt[2].SetPoint(x + 10+20 + 25, y);
	BezierPt[3].SetPoint(x + 10+50, y + 30);

	//▼BeziePT2 mean most right and bottom side of curve 
	BezierPt2[0].SetPoint(x + 20+10, y + 60);
	BezierPt2[1].SetPoint(x +10+20 + 7, y + 60 - 3);
	BezierPt2[2].SetPoint(x + 10+20 + 25, y + 60);
	BezierPt2[3].SetPoint(x + 10+50, y + 30);

	//▼BeziePT3 mean most left side curve at XOR Gate  
	BezierPt3[0].SetPoint(x+10, y);
	BezierPt3[1].SetPoint(x +10+ 20, y + 30);
	BezierPt3[2].SetPoint(x +10+20, y + 30);
	BezierPt3[3].SetPoint(x+10, y + 60);

	//▼BeziePT4 mean most left side curve at XOR Gate
	BezierPt4[0].SetPoint(x, y);
	BezierPt4[1].SetPoint(x + 20, y + 30);
	BezierPt4[2].SetPoint(x + 20, y + 30);
	BezierPt4[3].SetPoint(x, y + 60);

	pt[0].SetPoint(x+10, y);
	pt[1].SetPoint(x +10+ 20, y);

	pt2[0].SetPoint(x+10, y + 60);
	pt2[1].SetPoint(x +10+ 20, y + 60);

	
	
	//x~x+60 , y~y+60
	

	
}
CPoint* XOR::GetBezierPt() {
	return 0;
}
void XOR::DrawXOR(CDC *pDC, int x, int  y) {

	SetPoint(x, y);

	/*Test 용입니다*/
	pDC->Rectangle(rect);
	/*Test 용입니다*/

	pDC->PolyBezier(BezierPt, 4);
	pDC->PolyBezier(BezierPt2, 4);
	pDC->PolyBezier(BezierPt3, 4);
	pDC->PolyBezier(BezierPt4, 4);
	pDC->Polyline(pt, 2);
	pDC->Polyline(pt2, 2);
	
	
}


