#pragma once


class DPP {
public:
	CString ch[3] = { _T("D"), _T("Q"), _T("Q'") };
	typedef struct DppLogic {
		CPoint pos;		// Logic 위치
		CPoint ch_pos[3];
		int rotate;		// 회전
		int input;		// 입력 D
		int clk;		// 클럭
		int output1;	// 결과 Q
		int output2;	// 결과 Q'
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// 그리는 중인가?
		bool updown;	// 상승/하강 엣지
	};
	CArray<DppLogic, DppLogic&> logic;

public:
	void createLogic(CArray<DppLogic, DppLogic&> &logic, CPoint point);	// DPP Logic 만들기
	bool makeOK(CArray<DppLogic, DppLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<DppLogic, DppLogic&> &logic, CPoint poine);	// DPP Logic 돌리기
	void drawLine(CArray<DppLogic, DppLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(CArray<DppLogic, DppLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<DppLogic, DppLogic&> &logic, int input, POINT point);	// input 입력
	void getValue(DppLogic &logic);	// output 계산
};