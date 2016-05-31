#include "stdafx.h"
#include "DPP.h"

/* DPP Logic ����� */
void DPP::createLogic(CArray<DppLogic, DppLogic&> &logic, CPoint point)
{
	DppLogic temp;

	if (logic.GetSize() == 0) {	// ó�� Logic �����
		temp.pos = point;
		temp.input = 2;
		temp.output = 2;
		temp.rotate = 0;
		temp.ch_pos[0] = { point.x, point.y };
		temp.ch_pos[1] = { point.x + 40, point.y };
		temp.ch_pos[2] = { point.x + 40, point.y + 40 };
		temp.in_line = new CArray<POINT, POINT&>;
		temp.drawing = false;

		logic.Add(temp);
	}
	else {	// �� ��° ���� Logic �����
		if (makeOK(logic, point)) {
			temp.pos = point;
			temp.input = 2;
			temp.output = 2;
			temp.rotate = 0;
			temp.ch_pos[0] = { point.x, point.y };
			temp.ch_pos[1] = { point.x + 40, point.y };
			temp.ch_pos[2] = { point.x + 40, point.y + 40 };
			temp.in_line = new CArray<POINT, POINT&>;
			temp.drawing = false;

			logic.Add(temp);
		}
	}
}

/* ����� ���� ���� */
bool DPP::makeOK(CArray<DppLogic, DppLogic&>& logic, CPoint point)
{
	bool permit = true;

	for (int i = 0; i < logic.GetSize(); i++) {
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;

		// ���� �ȿ� �ۼ��� Logic�� �ִٸ� ����� �Ұ�
		if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
			permit = false;
		}
	}

	return permit;
}

/* DPP Logic ������ */
void DPP::rotateLogic(CArray<DppLogic, DppLogic&> &logic, CPoint point)
{
	int r_num[] = { 0, 1, 2, 3 };

	for (int i = 0; i<logic.GetSize(); i++) {
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
			switch (r) {	// ���� �� ����� Logic ������
			case 0:
				logic[i].rotate = r_num[1];
				break;
			case 1:
				logic[i].rotate = r_num[2];
				break;
			case 2:
				logic[i].rotate = r_num[3];
				break;
			case 3:
				logic[i].rotate = r_num[0];
				break;
			default:
				break;
			}
			// ���� ���� �ʱ�ȭ
			logic[i].in_line->RemoveAll();
			logic[i].input = 2;
			logic[i].output = 2;
		}
	}
}

/* Line �׸��� */
void DPP::drawLine(CArray<DppLogic, DppLogic&> &logic, CPoint point, bool &flag)
{
	for (int i = 0; i < logic.GetSize(); i++) {
		POINT temp;
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		if (!flag) {	// �׸��� ����
			if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
				flag = true;

				// �̹� �Է¼��� �׷��� ��� �ʱ�ȭ
				if (logic[i].in_line->GetSize() != 0) {
					logic[i].in_line->RemoveAll();
					logic[i].input = 2;
				}

				switch (r) {
				case 0:
					temp.x = x;
					temp.y = y + 15;
					break;
				case 1:
					temp.x = x + 45;
					temp.y = y;
					break;
				case 2:
					temp.x = x + 60;
					temp.y = y + 15;
					break;
				case 3:
					temp.x = x + 15;
					temp.y = y + 60;
					break;
				default:
					break;
				}
				logic[i].in_line->Add(temp);
				logic[i].drawing = true;
			}
		}

		if (flag) {	// �׸��� �Ϸ�
			if ((point.x >= 50) && (point.x <= 80) && (point.y >= 50) && (point.y <= 80)) {
				if (logic[i].drawing) {	// input1�� ����
					temp.x = 65;
					temp.y = 65;
					logic[i].in_line->Add(temp);
					logic[i].drawing = false;
					flag = false;
				}
			}
			if ((point.x >= 50) && (point.x <= 80) && (point.y >= 150) && (point.y <= 180)) {
				if (logic[i].drawing) {	// input2�� ����
					temp.x = 65;
					temp.y = 165;
					logic[i].in_line->Add(temp);
					logic[i].drawing = false;
					flag = false;
				}
			}
		}
	}
}

/* Logic �׸��� */
void DPP::drawLogic(DppLogic & logic, POINT *pt)
{
	int x = logic.pos.x;
	int y = logic.pos.y;
	int r = logic.rotate;

	switch (logic.rotate) {
	case 0:
		pt[0] = { x, y + 35 };
		pt[1] = { x + 10, y + 30 };
		pt[2] = { x, y + 25 };
		pt[3] = { x, y };
		pt[4] = { x + 60, y };
		pt[5] = { x + 60, y + 60 };
		pt[6] = { x, y + 60 };
		pt[7] = pt[2];
		logic.ch_pos[0] = { x + 5, y + 5 };
		logic.ch_pos[1] = { x + 40, y + 5 };
		logic.ch_pos[2] = { x + 40, y + 40 };
		break;
	case 1:
		pt[0] = { x + 25, y };
		pt[1] = { x + 30, y + 10 };
		pt[2] = { x + 35, y };
		pt[3] = { x + 60, y };
		pt[4] = { x + 60, y + 60 };
		pt[5] = { x, y + 60 };
		pt[6] = { x, y };
		pt[7] = pt[2];
		logic.ch_pos[0] = { x + 40, y + 5 };
		logic.ch_pos[1] = { x + 40, y + 40 };
		logic.ch_pos[2] = { x + 5, y + 40 };
		break;
	case 2:
		pt[0] = { x + 60, y + 35 };
		pt[1] = { x + 50, y + 30 };
		pt[2] = { x + 60, y + 25 };
		pt[3] = { x + 60, y };
		pt[4] = { x, y };
		pt[5] = { x, y + 60 };
		pt[6] = { x + 60, y + 60 };
		pt[7] = pt[2];
		logic.ch_pos[0] = { x + 40, y + 5 };
		logic.ch_pos[1] = { x + 5, y + 5 };
		logic.ch_pos[2] = { x + 5, y + 40 };
		break;
	case 3:
		pt[0] = { x + 25, y + 60 };
		pt[1] = { x + 30, y + 50 };
		pt[2] = { x + 35, y + 60 };
		pt[3] = { x + 60, y + 60 };
		pt[4] = { x + 60, y };
		pt[5] = { x, y };
		pt[6] = { x, y + 60 };
		pt[7] = pt[2];
		logic.ch_pos[0] = { x + 5, y + 40 };
		logic.ch_pos[1] = { x + 5, y + 5 };
		logic.ch_pos[2] = { x + 40, y + 5 };
		break;
	default:
		break;
	}
}

/* input �Է� */
void DPP::setValue(CArray<DppLogic, DppLogic&>& logic, int input, POINT point)
{	// �ش� point���� ������ ���� ����� ��� �ش� input�� �Է�
	for (int i = 0; i < logic.GetSize(); i++) {
		CString x, y;
		x.Format(_T("%d"), logic[i].in_line->GetAt(logic[i].in_line->GetSize() - 1).x);
		y.Format(_T("%d"), logic[i].in_line->GetAt(logic[i].in_line->GetSize() - 1).y);
		if ((_ttoi(x) == point.x) && (_ttoi(y) == point.y)) {
			logic[i].input = input;
		}
	}
}

/* output ��� */
void DPP::getValue(DppLogic & logic)
{
	if (logic.updown) {
		if (logic.clk == 1) {
			if (logic.input == 1)
				logic.output1 = 1;
			else if (logic.input == 0)
				logic.output1 = 0;
		}
	}
	else {
		if (logic.clk == 0) {
			if (logic.input == 1)
				logic.output2 = 0;
			else if (logic.input == 0)
				logic.output2 = 1;
		}
	}
}