#pragma once


class NAND {
public:
	typedef struct NAndLogic {
		CPoint pos;
		int rotate;
		int input1;
		int input2;
		int output;
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;
	};
	CArray<NAndLogic, NAndLogic&> logic;

public:
	void createLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// NAND Logic �����
	bool makeOK(CArray<NAndLogic, NAndLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint poine);	// NAND Logic ������
	void drawLine(CArray<NAndLogic, NAndLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(NAndLogic &logic, POINT *pt, POINT *pt_e, POINT *pt_b);	// Logic �׸���
	void setValue(CArray<NAndLogic, NAndLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(NAndLogic &logic);	// output ��ȯ
};