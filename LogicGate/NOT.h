#pragma once


class NOT {
public:
	typedef struct NotLogic {
		CPoint pos;		// Logic 위치
		int id;			// id
		int rotate;		// 회전
		int input;		// 입력
		int output;		// 출력
		bool input_flag;		// 입력1 연결 유무
		bool output_flag;	// 출력 연결 유무
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// 그리는 중인가?
	};
	CArray<NotLogic, NotLogic&> logic;

public:
	void createLogic(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// NOT Logic 만들기
	bool makeOK(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<NotLogic, NotLogic&> &logic, CPoint poine);	// NOT Logic 돌리기
	void drawLine(CArray<NotLogic, NotLogic&> &logic, CPoint point, bool &flag);	// Line 그리기
	void drawLogic(CArray<NotLogic, NotLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<NotLogic, NotLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(NotLogic &logic);	// output 반환
};