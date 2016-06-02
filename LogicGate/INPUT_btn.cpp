#include "stdafx.h"
#include "INPUT_btn.h"

/* Logic 만들기 */
void INPUT_btn::createLogic(CArray<InputLogic, InputLogic&> &logic, CPoint point)
{
	InputLogic temp;

	if (logic.GetSize() == 0)
	{
		temp.pos = point;
		temp.input = 0;
		temp.rotate = 0;
		logic.Add(temp);
	}
	else
	{
		if (makeOK(logic, point))
		{
			temp.pos = point;
			temp.input = 0;
			temp.rotate = 0;
			logic.Add(temp);
		}
	}
}

/* 만들기 가능 유무 */
bool INPUT_btn::makeOK(CArray<InputLogic, InputLogic&>& logic, CPoint point)
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
void INPUT_btn::rotateLogic(CArray<InputLogic, InputLogic&> &logic, CPoint point)
{
	CRgn InputLogic;
	int r_num[] = { 0, 1, 2, 3 };

	CRgn rgn_input1, rgn_input2;

	rgn_input1.CreateRectRgn(50, 50, 80, 80);

	InputLogic.CreateRectRgn(point.x, point.y, point.x + 60, point.y + 60);

	for (int i = 0; i < logic.GetSize(); i++) {
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;

		InputLogic.SetRectRgn(x, y, x + 60, y + 60);

		if (InputLogic.PtInRegion(point)) {
			CBrush brush(RGB(255, 255, 255));
			switch (r) {
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
		}
	}
}

// Logic 그리기
void INPUT_btn::drawLogic(CArray<InputLogic, InputLogic&>& logic, CDC * dc) {
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
void INPUT_btn::setValue(CArray<InputLogic, InputLogic&>& logic, int input, POINT point)
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
int INPUT_btn::getValue(InputLogic & logic)
{
	return logic.input;
}