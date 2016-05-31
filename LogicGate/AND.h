#pragma once


class AND {
public:
	typedef struct AndLogic {
		CPoint pos;
		int rotate;
		int input1;
		int input2;
		int output;
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;
	};
	CArray<AndLogic, AndLogic&> logic;

public:
	void createLogic(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// AND Logic 만들기
	bool makeOK(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<AndLogic, AndLogic&> &logic, CPoint poine);	// AND Logic 돌리기
	void drawLine(CArray<AndLogic, AndLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(AndLogic &logic, POINT *pt, POINT *pt_b);	// Logic 그리기
	void setValue(CArray<AndLogic, AndLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(AndLogic &logic);	// output 반환
};