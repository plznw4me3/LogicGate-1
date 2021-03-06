#include "stdafx.h"
#include "NAND.h"


/* Logic 만들기 */
void NAND::createLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint point)
{
	NAndLogic temp;

	if (logic.GetSize() == 0) {	// 처음 Logic 만들기
		temp.pos = point;
		temp.id = 4000 + logic.GetSize();
		temp.input1 = 2;
		temp.input2 = 2;
		temp.output = 2;
		temp.rotate = 0;
		temp.input1_flag = false;
		temp.input2_flag = false;
		temp.output_flag = false;
		temp.in_line1 = new CArray<POINT, POINT&>;
		temp.in_line2 = new CArray<POINT, POINT&>;
		temp.drawing = false;

		logic.Add(temp);
	}
	else {	// 두 번째 이후 Logic 만들기
		if (makeOK(logic, point)) {
			temp.pos = point; 
			temp.id = 4000 + logic.GetSize();
			temp.input1 = 2;
			temp.input2 = 2;
			temp.output = 2;
			temp.rotate = 0;
			temp.input1_flag = false;
			temp.input2_flag = false;
			temp.output_flag = false;
			temp.in_line1 = new CArray<POINT, POINT&>;
			temp.in_line2 = new CArray<POINT, POINT&>;
			temp.drawing = false;

			logic.Add(temp);
		}
	}
}

/* 만들기 가능 유무 */
bool NAND::makeOK(CArray<NAndLogic, NAndLogic&> &logic, CPoint point)
{
	bool permit = true;

	for (int i = 0; i < logic.GetSize(); i++) {
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;

		// 영역 안에 작성된 Logic이 있다면 만들기 불가
		if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
			permit = false;
		}
	}

	return permit;
}

/* Logic 돌리기 */
void NAND::rotateLogic(CArray<NAndLogic, NAndLogic&> &logic, CPoint point)
{
	int r_num[] = { 0, 1, 2, 3 };

	for (int i = 0; i<logic.GetSize(); i++) {
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
			switch (r) {	// 기존 선 지우고 Logic 돌리기
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
			logic[i].in_line1->RemoveAll();
			logic[i].in_line2->RemoveAll();
			logic[i].input1 = 2;
			logic[i].input2 = 2;
			logic[i].output = 2;
			logic[i].input1_flag = false;
			logic[i].input2_flag = false;
			logic[i].output_flag = false;
		}
	}
}

/* Line 그리기 */
void NAND::drawLine(CArray<NAndLogic, NAndLogic&> &logic, CPoint point, bool &flag)
{
	for (int i = 0; i < logic.GetSize(); i++) {
		POINT temp;
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		if (!flag) {	// 그리기 시작
			if ((point.x >= x) && (point.x <= x + 60) && (point.y >= y) && (point.y <= y + 60)) {
				flag = true;

				// 이미 입력선이 그려진 경우 초기화
				if (!(logic[i].in_line1->GetSize()) && !(logic[i].in_line2->GetSize())) {
					logic[i].in_line1->RemoveAll();
					logic[i].in_line2->RemoveAll();
					logic[i].input1 = 2;
					logic[i].input2 = 2;
				}

				if (logic[i].input1 == 2) {
					switch (r) {	// input1이 입력되지 않은 경우
					case 0:
						temp.x = x;
						temp.y = y + 10;
						break;
					case 1:
						temp.x = x + 10;
						temp.y = y;
						break;
					case 2:
						temp.x = x + 60;
						temp.y = y + 10;
						break;
					case 3:
						temp.x = x + 10;
						temp.y = y + 60;
						break;
					default:
						break;
					}
					logic[i].in_line1->Add(temp);
				}
				else if (logic[i].input2 == 2) {	// input1이 입력되고 input2가 입력되지 않은 경우
					switch (r) {
					case 0:
						temp.x = x;
						temp.y = y + 50;
						break;
					case 1:
						temp.x = x + 50;
						temp.y = y;
						break;
					case 2:
						temp.x = x + 60;
						temp.y = y + 50;
						break;
					case 3:
						temp.x = x + 50;
						temp.y = y + 60;
						break;
					default:
						break;
					}
					logic[i].in_line2->Add(temp);
				}
				logic[i].drawing = true;
			}
		}

		if (flag) {	// 그리기 완료
			if ((point.x >= 50) && (point.x <= 80) && (point.y >= 50) && (point.y <= 80)) {
				if (logic[i].drawing) {	// input1과 연결
					temp.x = 65;
					temp.y = 65;
					logic[i].input1 = 0;

					logic[i].in_line1->Add(temp);

					logic[i].drawing = false;
					flag = false;
				}
			}
			else if ((point.x >= 50) && (point.x <= 80) && (point.y >= 150) && (point.y <= 180)) {
				if (logic[i].drawing) {	// input2와 연결
					temp.x = 65;
					temp.y = 165;
					logic[i].input2 = 0;

					logic[i].in_line2->Add(temp);
					logic[i].drawing = false;
					flag = false;
				}
			}
		}
	}
}

/* Logic 그리기 */
void NAND::drawLogic(CArray<NAndLogic, NAndLogic&> &logic, CDC *dc)
{
	for (int i = 0; i < logic.GetSize(); i++) {
		POINT pt[4];
		POINT pt_b[4];
		POINT pt_e[2];
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		switch (logic[i].rotate) {
		case 0:
			pt[0] = { x + 30, y };
			pt[1] = { x, y };
			pt[2] = { x, y + 60 };
			pt[3] = { x + 30, y + 60 };
			pt_b[0] = { x + 30, y };
			pt_b[1] = { x + 50, y + 26 };
			pt_b[2] = { x + 50, y + 36 };
			pt_b[3] = { x + 30, y + 60 };
			pt_e[0] = { x + 45, y + 26 };
			pt_e[1] = { x + 55, y + 36 };
			break;
		case 1:
			pt[0] = { x, y + 30 };
			pt[1] = { x, y };
			pt[2] = { x + 60, y };
			pt[3] = { x + 60, y + 30 };
			pt_b[0] = { x, y + 30 };
			pt_b[1] = { x + 26, y + 50 };
			pt_b[2] = { x + 36, y + 50 };
			pt_b[3] = { x + 60, y + 30 };
			pt_e[0] = { x + 26, y + 45 };
			pt_e[1] = { x + 36, y + 55 };
			break;
		case 2:
			pt[0] = { x + 30, y };
			pt[1] = { x + 60, y };
			pt[2] = { x + 60, y + 60 };
			pt[3] = { x + 30, y + 60 };
			pt_b[0] = { x + 30, y };
			pt_b[1] = { x + 10, y + 26 };
			pt_b[2] = { x + 10, y + 36 };
			pt_b[3] = { x + 30, y + 60 };
			pt_e[0] = { x + 5, y + 26 };
			pt_e[1] = { x + 15, y + 36 };
			break;
		case 3:
			pt[0] = { x, y + 30 };
			pt[1] = { x, y + 60 };
			pt[2] = { x + 60, y + 60 };
			pt[3] = { x + 60, y + 30 };
			pt_b[0] = { x, y + 30 };
			pt_b[1] = { x + 26, y + 10 };
			pt_b[2] = { x + 36, y + 10 };
			pt_b[3] = { x + 60, y + 30 };
			pt_e[0] = { x + 25, y + 5 };
			pt_e[1] = { x + 36, y + 15 };
			break;
		default:
			break;
		}

		dc->Polyline(pt, 4);
		dc->PolyBezier(pt_b, 4);
		dc->Ellipse(pt_e[0].x, pt_e[0].y, pt_e[1].x, pt_e[1].y);
	}
}

/* input 입력 */
void NAND::setValue(CArray<NAndLogic, NAndLogic&> &logic, int input, POINT point)
{	// 해당 point값에 마지막 선이 연결된 경우 해당 input값 입력
	for (int i = 0; i < logic.GetSize(); i++) {
		CString x1, y1, x2, y2;
		x1.Format(_T("%d"), logic[i].in_line1->GetAt(logic[i].in_line1->GetSize() - 1).x);
		y1.Format(_T("%d"), logic[i].in_line1->GetAt(logic[i].in_line1->GetSize() - 1).y);
		x2.Format(_T("%d"), logic[i].in_line2->GetAt(logic[i].in_line2->GetSize() - 1).x);
		y2.Format(_T("%d"), logic[i].in_line2->GetAt(logic[i].in_line2->GetSize() - 1).y);

		if ((_ttoi(x1) == point.x) && (_ttoi(y1) == point.y)) {
			logic[i].input1 = input;
		}
		if ((_ttoi(x2) == point.x) && (_ttoi(y2) == point.y)) {
			logic[i].input2 = input;
		}
	}
}

/* output 반환 */
int NAND::getValue(NAndLogic &logic)
{
	if ((logic.input1 == 1) && (logic.input2 == 1))
		logic.output = 0;
	else
		logic.output = 1;

	return logic.output;
}