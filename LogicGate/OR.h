#pragma once


class OR {
public:
	typedef struct OrLogic {
		CPoint pos;
		int rotate;
		int input1;
		int input2;
		int output;
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;
	};
	CArray<OrLogic, OrLogic&> logic;

public:
	void createLogic(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// OR Logic 만들기
	bool makeOK(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<OrLogic, OrLogic&> &logic, CPoint poine);	// OR Logic 돌리기
	void drawLine(CArray<OrLogic, OrLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(OrLogic &logic, POINT *pt, POINT *pt_lb, POINT *pt_b);	// Logic 그리기
	void setValue(CArray<OrLogic, OrLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(OrLogic &logic);	// output 반환
};