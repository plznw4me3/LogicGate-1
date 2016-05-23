#pragma once
#include "stdafx.h"
#include <afxtempl.h>

class Gate
{

private:
	CArray <CPoint, CPoint&> arrLine;
	bool inputLine[2];
	bool outputLine;
	bool eraseFlag;
	int moveCount = 0;
	


protected:

	CRect rect;	
public:


	int locateX, locateY;
	int width, height;
	static int movedGate;
	bool MoveFlag;
	CRect GetRect();
	static CArray<Gate, Gate&> arr;
	long Gate::checkConecttedLine(Gate g, CPoint point);

	bool Gate::Erase(CDC *dc, CRect rect);
	bool Gate::Move(CPoint point, CDC *pdc);
	
	
	Gate();
	~Gate();
	
};


//Move 함수는 마우스 포인트를 찍으면 그 곳에 rgn이 있는지 확인합니다.

