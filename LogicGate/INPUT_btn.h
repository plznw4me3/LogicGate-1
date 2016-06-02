#pragma once

class INPUT_btn {
public:
	typedef struct InputLogic {
		CPoint pos;
		int rotate;
		int input;
	};
	CArray<InputLogic, InputLogic&> logic;

public:
	void createLogic(CArray<InputLogic, InputLogic&> &logic, CPoint point);	// AND Logic �����
	bool makeOK(CArray<InputLogic, InputLogic&> &logic, CPoint point);	// ����� ���� ����
	void rotateLogic(CArray<InputLogic, InputLogic&> &logic, CPoint poine);	// AND Logic ������
	void drawLogic(CArray<InputLogic, InputLogic&> &logic, CDC *dc);	// Logic �׸���
	void setValue(CArray<InputLogic, InputLogic&> &logic, int input, POINT point);	// input �Է�
	int getValue(InputLogic &logic);	// output ��ȯ
};