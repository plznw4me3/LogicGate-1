#pragma once
#include <afxtempl.h>
#define THICK 5
class Wire
{
public:
	Wire();
	~Wire();
public:
	CPoint polyPoint[6];
	bool Wire::makeLine(CDC *dc, CPoint point);
	void Wire::DrawLine(CDC *dc);
	
	//Wire& Wire::operator = (const Wire & w);
public:
	bool Wire::LBtnClickedFlag;
	CPoint StartPos, EndPos;
	bool makeLineFlag;
	CRect rect[2];
	CRect EndPointRect , StartPointRect;
	CRect testRect;
	bool EndPointRect_LBtnClickFlag;
	bool StartPointRect_LBtnClickFlag;
	bool checkConnectedFlag;

	//선을 연장할때 앞의 선과 뒤의 선이 연결됨을 확인합니다.
	//연결된 선은 하나의 선처럼 움직입니다.
	
};

