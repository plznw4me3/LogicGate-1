#include "stdafx.h"
#include "NOT.h"

/* Logic 만들기 */
void NOT::createLogic(CArray<NotLogic, NotLogic&> &logic, CPoint point)
{
	NotLogic temp;

	if (logic.GetSize() == 0) {	// 처음 Logic 만들기
		temp.pos = point;
		temp.id = 3000 + logic.GetSize();
		temp.input = 2;
		temp.output = 2;
		temp.rotate = 0;
		temp.input_flag = false;
		temp.output_flag = false;
		temp.in_line = new CArray<POINT, POINT&>;
		temp.drawing = false;

		logic.Add(temp);
	}
	else {	// 두 번째 이후 Logic 만들기
		if (makeOK(logic, point)) {
			temp.pos = point;
			temp.id = 3000 + logic.GetSize();
			temp.input = 2;
			temp.output = 2;
			temp.rotate = 0;
			temp.input_flag = false;
			temp.output_flag = false;
			temp.in_line = new CArray<POINT, POINT&>;
			temp.drawing = false;

			logic.Add(temp);
		}
	}
}

/* 만들기 가능 유무 */
bool NOT::makeOK(CArray<NotLogic, NotLogic&>& logic, CPoint point)
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
void NOT::rotateLogic(CArray<NotLogic, NotLogic&> &logic, CPoint point)
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
			// 기존 정보 초기화
			logic[i].in_line->RemoveAll();
			logic[i].input = 2;
			logic[i].output = 2;
			logic[i].input_flag = false;
			logic[i].output_flag = false;
		}
	}
}

/* Line 그리기 */
void NOT::drawLine(CArray<NotLogic, NotLogic&> &logic, CPoint point, bool &flag)
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
				if (logic[i].in_line->GetSize() != 0) {
					logic[i].in_line->RemoveAll();
					logic[i].input = 2;
				}

				switch (r) {
				case 0:
					temp.x = x;
					temp.y = y + 30;
					break;
				case 1:
					temp.x = x + 30;
					temp.y = y;
					break;
				case 2:
					temp.x = x + 40;
					temp.y = y + 30;
					break;
				case 3:
					temp.x = x + 30;
					temp.y = y + 40;
					break;
				default:
					break;
				}
				logic[i].in_line->Add(temp);
				logic[i].drawing = true;
			}
		}

		if (flag) {	// 그리기 완료
			if ((point.x >= 50) && (point.x <= 80) && (point.y >= 50) && (point.y <= 80)) {
				if (logic[i].drawing) {	// input1과 연결
					temp.x = 65;
					temp.y = 65;
					logic[i].in_line->Add(temp);
					logic[i].drawing = false;
					flag = false;
				}
			}
			if ((point.x >= 50) && (point.x <= 80) && (point.y >= 150) && (point.y <= 180)) {
				if (logic[i].drawing) {	// input2와 연결
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

// Logic 그리기
void NOT::drawLogic(CArray<NotLogic, NotLogic&>& logic, CDC * dc) {
	for (int i = 0; i < logic.GetSize(); i++) {
		POINT pt[3];
		POINT pt_e[2];
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		switch (logic[i].rotate) {
		case 0:
			pt[0] = { x, y };
			pt[1] = { x + 30, y + 30 };
			pt[2] = { x, y + 60 };
			pt_e[0] = { x + 30, y + 26 };
			pt_e[1] = { x + 40, y + 36 };
			break;
		case 1:
			pt[0] = { x, y };
			pt[1] = { x + 30, y + 30 };
			pt[2] = { x + 60, y };
			pt_e[0] = { x + 26, y + 30 };
			pt_e[1] = { x + 36, y + 40 };
			break;
		case 2:
			pt[0] = { x + 40, y };
			pt[1] = { x + 10, y + 30 };
			pt[2] = { x + 40, y + 60 };
			pt_e[0] = { x, y + 26 };
			pt_e[1] = { x + 10, y + 36 };
			break;
		case 3:
			pt[0] = { x, y + 40 };
			pt[1] = { x + 30, y + 10 };
			pt[2] = { x + 60, y + 40 };
			pt_e[0] = { x + 26, y };
			pt_e[1] = { x + 36, y + 10 };
			break;
		default:
			break;
		}

		dc->Polygon(pt, 3);
		dc->Ellipse(pt_e[0].x, pt_e[0].y, pt_e[1].x, pt_e[1].y);
	}
}

/* input 입력 */
void NOT::setValue(CArray<NotLogic, NotLogic&>& logic, int input, POINT point)
{	// 해당 point값에 마지막 선이 연결된 경우 해당 input값 입력
	for (int i = 0; i < logic.GetSize(); i++) {
		CString x, y;
		x.Format(_T("%d"), logic[i].in_line->GetAt(logic[i].in_line->GetSize() - 1).x);
		y.Format(_T("%d"), logic[i].in_line->GetAt(logic[i].in_line->GetSize() - 1).y);
		if ((_ttoi(x) == point.x) && (_ttoi(y) == point.y)) {
			logic[i].input = input;
		}
	}
}

/* output 반환 */
int NOT::getValue(NotLogic & logic)
{
	if (logic.input == 0)
		logic.output = 1;
	else
		logic.output = 0;

	return logic.output;
}


