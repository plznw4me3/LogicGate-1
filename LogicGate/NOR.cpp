#include "stdafx.h"
#include "NOR.h"

NOR::NOR()
{
}


NOR::~NOR()
{
}


void NOR::SetPoint(int x, int y) {
	//  curve that code made down part of curve in nor
	// there are 3 curve at NOR gate so 
	//BeziePT mean most right and upper side of curve 
	BezierPt[0].SetPoint(x + 20, y);
	BezierPt[1].SetPoint(x + 20 + 7, y + 3);
	BezierPt[2].SetPoint(x + 20 + 25, y);
	BezierPt[3].SetPoint(x + 50, y + 30);

	//°ÂBeziePT2 mean most right and bottom side of curve 
	BezierPt2[0].SetPoint(x + 20, y + 60);
	BezierPt2[1].SetPoint(x + 20 + 7, y + 60 - 3);
	BezierPt2[2].SetPoint(x + 20 + 25, y + 60);
	BezierPt2[3].SetPoint(x + 50, y + 30);

	//°ÂBeziePT3 mean most left side curve at NOR Gate  
	BezierPt3[0].SetPoint(x, y);
	BezierPt3[1].SetPoint(x + 20, y + 30);
	BezierPt3[2].SetPoint(x + 20, y + 30);
	BezierPt3[3].SetPoint(x, y + 60);


	pt[0].SetPoint(x, y);
	pt[1].SetPoint(x + 20, y);

	pt2[0].SetPoint(x, y + 60);
	pt2[1].SetPoint(x + 20, y + 60);


}
CPoint* NOR::GetBezierPt() {
	return 0;
}