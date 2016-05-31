#pragma once


class OR {
public:
	typedef struct OrLogic {
		CPoint pos;		// Logic ��ġ
		int rotate;		// ȸ��
		int input1;		// �Է�1
		int input2;		// �Է�2
		int output;		// ���
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;	// �׸��� ���ΰ�?
	};
	CArray<OrLogic, OrLogic&> logic;

public:
	void createLogic(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// OR Logic �����
	bool makeOK(CArray<OrLogic, OrLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<OrLogic, OrLogic&> &logic, CPoint poine);	// OR Logic ������
	void drawLine(CArray<OrLogic, OrLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<OrLogic, OrLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<OrLogic, OrLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(OrLogic &logic);	// output ��ȯ
};