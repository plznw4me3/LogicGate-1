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
	//gate �� ���� ����Ǿ� �մ��� Ȯ���մϴ� 
	//���� �Ǿ� ������ ���� ����ϴ� .
	

	//���õ� ������ ����ϴ�
	dc->SelectStockObject(NULL_BRUSH);
	dc->Rectangle(rect);
	


	//����� ���� �����մϴ�
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


//���� ����� ���� �ľ��� ����� ���� ���� ���ϴ�.

long Gate::checkConecttedLine(Gate g , CPoint point) {
	//����� �� �ϳ��ΰɷ� 10000
	
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