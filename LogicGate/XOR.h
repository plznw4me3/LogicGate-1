#pragma once
#include "stdafx.h"
#include <afxtempl.h>
#include "Gate.h"
#define THICK 5

class XOR  : public Gate {


private:
	

	CRect XORrect;
	CRect inputRect, outputRect, input2Rect;
	
	CPoint pos;
	CPoint pt[3];
	CPoint pt2[3];
	CPoint BezierPt[4];
	CPoint BezierPt2[4];
	CPoint BezierPt3[4];
	CPoint BezierPt4[4];
	int rotate;
	
	bool inputState[2];
	bool outputState;
	CArray <int , int&> inputConnectId, input2CounnectId, outputConnectId;
public:
	static int Num;
	CPoint* GetBezierPt();
	void SetPoint(int x, int y);
	void DrawXOR(CDC *pDC, int x, int y);

	XOR();

};