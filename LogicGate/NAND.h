#pragma once


class NAND {
public:
	typedef struct NAndLogic {
		CPoint pos;		// Logic ��ġ
		int rotate;		// ȸ��
		int input1;		// �Է�1
		int input2;		// �Է�2
		int output;		// ���
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;	// �׸��� ���ΰ�?
	};
	CArray<NAndLogic, NAndLogic&> logic;

public:
	void createLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// NAND Logic �����
	bool makeOK(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint poine);	// NAND Logic ������
	void drawLine(CArray<NAndLogic, NAndLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<NAndLogic, NAndLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<NAndLogic, NAndLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(NAndLogic &logic);	// output ��ȯ
};