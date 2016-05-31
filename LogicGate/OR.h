#pragma once


class OR {
public:
	typedef struct OrLogic {
		CPoint pos;
		int rotate;
		int input1;
		int input2;
		int output;
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;
	};
	CArray<OrLogic, OrLogic&> logic;

public:
	void createLogic(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// OR Logic �����
	bool makeOK(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<OrLogic, OrLogic&> &logic, CPoint poine);	// OR Logic ������
	void drawLine(CArray<OrLogic, OrLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(OrLogic &logic, POINT *pt, POINT *pt_lb, POINT *pt_b);	// Logic �׸���
	void setValue(CArray<OrLogic, OrLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(OrLogic &logic);	// output ��ȯ
};