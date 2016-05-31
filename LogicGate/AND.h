#pragma once


class AND {
public:
	typedef struct AndLogic {
		CPoint pos;
		int rotate;
		int input1;
		int input2;
		int output;
		CArray<POINT, POINT&> *in_line1;
		CArray<POINT, POINT&> *in_line2;
		bool drawing;
	};
	CArray<AndLogic, AndLogic&> logic;

public:
	void createLogic(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// AND Logic �����
	bool makeOK(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<AndLogic, AndLogic&> &logic, CPoint poine);	// AND Logic ������
	void drawLine(CArray<AndLogic, AndLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(AndLogic &logic, POINT *pt, POINT *pt_b);	// Logic �׸���
	void setValue(CArray<AndLogic, AndLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(AndLogic &logic);	// output ��ȯ
};