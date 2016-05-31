#pragma once


class NOT {
public:
	typedef struct NotLogic {
		CPoint pos;
		int rotate;
		int input;
		int output;
		CArray<POINT, POINT&> *in_line;
		bool drawing;
	};
	CArray<NotLogic, NotLogic&> logic;

public:
	void createLogic(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// NOT Logic 만들기
	bool makeOK(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<NotLogic, NotLogic&> &logic, CPoint poine);	// NOT Logic 돌리기
	void drawLine(CArray<NotLogic, NotLogic&> &logic, CPoint point, bool &flag);	// Line 그리기
	void drawLogic(NotLogic &logic, POINT *pt, POINT *pt_e);	// Logic 그리기
	void setValue(CArray<NotLogic, NotLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(NotLogic &logic);	// output 반환
};