#pragma once
#include "stdafx.h"
#include "Gate.h"

class NOR : public Gate
{
public:
	NOR();
	~NOR();


private:

	int locateX;
	int locateY;
	CPoint pos;
	CPoint pt[3];
	CPoint pt2[3];
	CPoint BezierPt[4];
	CPoint BezierPt2[4];
	CPoint BezierPt3[4];
	CPoint BezierPt4[4];

	int rotate;
	int input;
	int output;
	CArray<CPoint, CPoint&> arr;

public:
	CPoint* GetBezierPt();
	void DrawNOR(CDC *pDC, int x, int y);
	void SetPoint(int x, int y);

};
