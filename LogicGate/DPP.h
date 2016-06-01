#pragma once


class DPP {
public:
	CString ch[3] = { _T("D"), _T("Q"), _T("Q'") };
	typedef struct DppLogic {
		CPoint pos;		// Logic ��ġ
		CPoint ch_pos[3];
		int rotate;		// ȸ��
		int input;		// �Է� D
		int clk;		// Ŭ��
		int output1;	// ��� Q
		int output2;	// ��� Q'
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// �׸��� ���ΰ�?
		bool updown;	// ���/�ϰ� ����
	};
	CArray<DppLogic, DppLogic&> logic;

public:
	void createLogic(CArray<DppLogic, DppLogic&> &logic, CPoint point);	// DPP Logic �����
	bool makeOK(CArray<DppLogic, DppLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<DppLogic, DppLogic&> &logic, CPoint poine);	// DPP Logic ������
	void drawLine(CArray<DppLogic, DppLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<DppLogic, DppLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<DppLogic, DppLogic&> &logic, int input, POINT point);	// input �Է�
	void getValue(DppLogic &logic);	// output ���
};