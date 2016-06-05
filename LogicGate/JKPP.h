#pragma once


class JKPP {
public:
	CString ch[4] = { _T("J"), _T("K"), _T("Q"), _T("Q'") };
	typedef struct JKppLogic {
		CPoint pos;		// Logic ��ġ
		CPoint ch_pos[4];
		int id;			// id
		int rotate;		// ȸ��
		int input1;		// �Է�1 J
		int input2;		// �Է�2 K
		int clk;		// Ŭ��
		int output1;	// ��� Q
		int output2;	// ��� Q'
		bool input1_flag;	// �Է� J ���� ����
		bool input2_flag;	// �Է� K ���� ����
		bool output1_flag;	// ��� Q ���� ����
		bool output2_flag;	// ��� Q' ���� ����
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// �׸��� ���ΰ�?
		bool updown;	// ���/�ϰ� ����
	};
	CArray<JKppLogic, JKppLogic&> logic;

public:
	void createLogic(CArray<JKppLogic, JKppLogic&> &logic, CPoint point);	// JKPP Logic �����
	bool makeOK(CArray<JKppLogic, JKppLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<JKppLogic, JKppLogic&> &logic, CPoint poine);	// JKPP Logic ������
	void drawLine(CArray<JKppLogic, JKppLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<JKppLogic, JKppLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<JKppLogic, JKppLogic&> &logic, int input, POINT point);	// input �Է�
	void getValue(JKppLogic &logic);	// output ���
};