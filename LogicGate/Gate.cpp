#include "stdafx.h"
#include "Gate.h"
#include "XOR.h"

Gate::Gate()
{
	locateX = 0; locateY = 0;
	
}


Gate::~Gate()
{
}


bool Gate::Move(CPoint point , CDC *pdc) {

	return true;
}


bool Gate::Erase(CDC *dc , CRect rect) {
	//gate 에 선이 연결되어 잇는지 확인합니다 
	//연결 되어 잇으면 선도 지웁니다 .
	

	//선택된 영역을 지웁니다
	dc->SelectStockObject(NULL_BRUSH);
	dc->Rectangle(rect);
	


	//연결된 선을 삭제합니다
	dc->SelectStockObject(NULL_PEN);
	for (int i = 0; i < arrLine.GetSize();i++){
		if (i = arrLine.GetSize() - 1) {
			dc->MoveTo(this->arrLine.GetAt(i));
			dc->LineTo(this->arrLine.GetAt(i + 1));
		}
		else
		{
			return 0;
		}
	} // end of for loop
	return true;
}


//현재 연결된 선을 파악해 연결된 선은 굵어 집니다.

long Gate::checkConecttedLine(Gate g , CPoint point) {
	//출력은 늘 하나인걸로 10000
	
	int result = 0;
	if (inputLine[0] == true) {
		result + 1;
		return result;}
	if (inputLine[1] == true) {
		return result + 10;
		}
	if (outputLine == true) {
		result + 100000000;
		return result;
	}
			return result;
}

CRect Gate::GetRect() {
	return this->rect;
}