#pragma once


class TPP {
public:
	CString ch[3] = { _T("T"), _T("Q"), _T("Q'") };
	typedef struct TppLogic {
		CPoint pos;		// Logic ��ġ
		CPoint ch_pos[3];
		int rotate;		// ȸ��
		int input;		// �Է� T
		int clk;		// Ŭ��
		int output1;	// ��� Q
		int output2;	// ��� Q'
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// �׸��� ���ΰ�?
		bool updown;	// ���/�ϰ� ����
	};
	CArray<TppLogic, TppLogic&> logic;

public:
	void createLogic(CArray<TppLogic, TppLogic&> &logic, CPoint point);	// TPP Logic �����
	bool makeOK(CArray<TppLogic, TppLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<TppLogic, TppLogic&> &logic, CPoint poine);	// TPP Logic ������
	void drawLine(CArray<TppLogic, TppLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<TppLogic, TppLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<TppLogic, TppLogic&> &logic, int input, POINT point);	// input �Է�
	void getValue(TppLogic &logic);	// output ���
};