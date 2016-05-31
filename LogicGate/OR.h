#pragma once


class OR {
public:
	typedef struct OrLogic {
		CPoint pos;		// Logic 위치
		int rotate;		// 회전
		int input1;		// 입력1
		int input2;		// 입력2
		int output;		// 출력
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;	// 그리는 중인가?
	};
	CArray<OrLogic, OrLogic&> logic;

public:
	void createLogic(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// OR Logic 만들기
	bool makeOK(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<OrLogic, OrLogic&> &logic, CPoint poine);	// OR Logic 돌리기
	void drawLine(CArray<OrLogic, OrLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(CArray<OrLogic, OrLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<OrLogic, OrLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(OrLogic &logic);	// output 반환
};