#pragma once

class INPUT_btn {
public:
	typedef struct InputLogic {
		CPoint pos;
		int rotate;
		int input;
	};
	CArray<InputLogic, InputLogic&> logic;

public:
	void createLogic(CArray<InputLogic, InputLogic&> &logic, CPoint point);	// AND Logic 만들기
	bool makeOK(CArray<InputLogic, InputLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<InputLogic, InputLogic&> &logic, CPoint poine);	// AND Logic 돌리기
	void drawLogic(CArray<InputLogic, InputLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<InputLogic, InputLogic&> &logic, int input, POINT point);	// input 입력
	int getValue(InputLogic &logic);	// output 반환
};