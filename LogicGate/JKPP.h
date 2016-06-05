#pragma once


class JKPP {
public:
	CString ch[4] = { _T("J"), _T("K"), _T("Q"), _T("Q'") };
	typedef struct JKppLogic {
		CPoint pos;		// Logic 위치
		CPoint ch_pos[4];
		int id;			// id
		int rotate;		// 회전
		int input1;		// 입력1 J
		int input2;		// 입력2 K
		int clk;		// 클럭
		int output1;	// 결과 Q
		int output2;	// 결과 Q'
		bool input1_flag;	// 입력 J 연결 유무
		bool input2_flag;	// 입력 K 연결 유무
		bool output1_flag;	// 출력 Q 연결 유무
		bool output2_flag;	// 출력 Q' 연결 유무
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// 그리는 중인가?
		bool updown;	// 상승/하강 엣지
	};
	CArray<JKppLogic, JKppLogic&> logic;

public:
	void createLogic(CArray<JKppLogic, JKppLogic&> &logic, CPoint point);	// JKPP Logic 만들기
	bool makeOK(CArray<JKppLogic, JKppLogic&> &logic, CPoint point);	// 만들기 가능 유무
	void rotateLogic(CArray<JKppLogic, JKppLogic&> &logic, CPoint poine);	// JKPP Logic 돌리기
	void drawLine(CArray<JKppLogic, JKppLogic&> &logic, CPoint point, bool &flag);	// 선 그리기
	void drawLogic(CArray<JKppLogic, JKppLogic&> &logic, CDC *dc);	// Logic 그리기
	void setValue(CArray<JKppLogic, JKppLogic&> &logic, int input, POINT point);	// input 입력
	void getValue(JKppLogic &logic);	// output 계산
};