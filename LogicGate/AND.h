#pragma once


class AND {
public:
	static int id_num;
	typedef struct AndLogic {
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
	CArray<AndLogic, AndLogic&> logic;

public:
	void createLogic(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// AND Logic �����
	bool makeOK(CArray<AndLogic, AndLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<AndLogic, AndLogic&> &logic, CPoint poine);	// AND Logic ������
	void drawLine(CArray<AndLogic, AndLogic&> &logic, CPoint point, bool &flag);	// �� �׸���
	void drawLogic(CArray<AndLogic, AndLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<AndLogic, AndLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(AndLogic &logic);	// output ��ȯ
};