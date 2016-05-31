#pragma once


class NAND {
public:
	typedef struct NAndLogic {
		CPoint pos;		// Logic 위치
		int rotate;		// 회전
		int input1;		// 입력1
		int input2;		// 입력2
		int output;		// 출력
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;	// 그리는 중인가?
	};
	CArray<NAndLogic, NAndLogic&> logic;

public:
	void createLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// NAND Logic 만들기
	bool makeOK(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint poine);	// NAND Logic 돌리기
	void drawLine(CArray<NAndLogic, NAndLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(CArray<NAndLogic, NAndLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<NAndLogic, NAndLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(NAndLogic &logic);	// output 반환
};