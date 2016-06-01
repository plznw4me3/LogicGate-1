#pragma once


class TPP {
public:
	CString ch[3] = { _T("T"), _T("Q"), _T("Q'") };
	typedef struct TppLogic {
		CPoint pos;		// Logic 위치
		CPoint ch_pos[3];
		int rotate;		// 회전
		int input;		// 입력 T
		int clk;		// 클럭
		int output1;	// 결과 Q
		int output2;	// 결과 Q'
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// 그리는 중인가?
		bool updown;	// 상승/하강 엣지
	};
	CArray<TppLogic, TppLogic&> logic;

public:
	void createLogic(CArray<TppLogic, TppLogic&> &logic, CPoint point);	// TPP Logic 만들기
	bool makeOK(CArray<TppLogic, TppLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<TppLogic, TppLogic&> &logic, CPoint poine);	// TPP Logic 돌리기
	void drawLine(CArray<TppLogic, TppLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(CArray<TppLogic, TppLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<TppLogic, TppLogic&> &logic, int input, POINT point);	// input 입력
	void getValue(TppLogic &logic);	// output 계산
};