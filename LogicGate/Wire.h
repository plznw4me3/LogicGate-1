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

	//���� �����Ҷ� ���� ���� ���� ���� ������� Ȯ���մϴ�.
	//����� ���� �ϳ��� ��ó�� �����Դϴ�.
	
};

