#pragma once
// test

class OR {
public:
	typedef struct OrLogic {
		CPoint pos;		// Logic ��ġ
		int id;			// id
		int rotate;		// ȸ��
		int input1;		// �Է�1
		int input2;		// �Է�2
		int output;		// ���
		bool input1_flag;	// �Է�1 ���� ����
		bool input2_flag;	// �Է�2 ���� ����
		bool output_flag;	// ��� ���� ����
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