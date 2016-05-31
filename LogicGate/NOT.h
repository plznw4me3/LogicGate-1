#pragma once


class NOT {
public:
	typedef struct NotLogic {
		CPoint pos;		// Logic ��ġ
		int rotate;		// ȸ��
		int input;		// �Է�
		int output;		// ���
		CArray<POINT, POINT&> *in_line;
		bool drawing;	// �׸��� ���ΰ�?
	};
	CArray<NotLogic, NotLogic&> logic;

public:
	void createLogic(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// NOT Logic �����
	bool makeOK(CArray<NotLogic, NotLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<NotLogic, NotLogic&> &logic, CPoint poine);	// NOT Logic ������
	void drawLine(CArray<NotLogic, NotLogic&> &logic, CPoint point, bool &flag);	// Line �׸���
	void drawLogic(NotLogic &logic, POINT *pt, POINT *pt_e);	// Logic �׸���
	void setValue(CArray<NotLogic, NotLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(NotLogic &logic);	// output ��ȯ
};