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
		int x = logic[i].pos.x;
		int y = logic[i].pos.y;
		int r = logic[i].rotate;
		POINT pt[3];
		CRect rect;

		dc->Rectangle(x, y, x + 30, y + 30);

		switch (logic[i].rotate) {
		case 0:
			pt[0] = { x + 30, y + 15 };
			pt[1] = { x + 45, y + 15 };
			dc->Polygon(pt, 2);
			dc->TextOutW(x - 17, y + 7, CString(_T("IN")));
			break;
		case 1:
			pt[0] = { x + 15, y };
			pt[1] = { x + 15, y - 15 };
			dc->Polygon(pt, 2);
			dc->TextOutW(x + 7, y + 32, CString(_T("IN")));
			break;
		case 2:
			pt[0] = { x , y + 15 };
			pt[1] = { x - 15, y + 15 };
			dc->Polygon(pt, 2);
			dc->TextOutW(x + 32, y + 7, CString(_T("IN")));
			break;
		case 3:
			pt[0] = { x + 15, y + 30 };
			pt[1] = { x + 15, y + 45 };
			dc->Polygon(pt, 2);
			dc->TextOutW(x + 7, y - 17, CString(_T("IN")));
			break;
		default:
			break;
		}
		CString str;
		str.Format(_T("%d"), logic[i].input);
		dc->TextOutW(logic[i].pos.x + 10, logic[i].pos.y + 7, str);
	}
}

/* input 입력 */
void INPUT_btn::setValue(CArray<InputLogic, InputLogic&>& logic, int input, POINT point)
{	// 해당 point값에 마지막 선이 연결된 경우 해당 input값 입력
	CRgn input_rgn;
	input_rgn.CreateRectRgn(point.x, point.y, point.x + 30, point.y + 30);

	for (int i = 0; i < logic.GetSize(); i++) {
		input_rgn.SetRectRgn(logic[i].pos.x, logic[i].pos.y, logic[i].pos.x + 30, logic[i].pos.y + 30);
		if (input_rgn.PtInRegion(point)) {
			if (logic[i].input == 0)
				logic[i].input = 1;
			else
				logic[i].input = 0;

		}
	}
}

/* output 반환 */
int INPUT_btn::getValue(InputLogic & logic)
{
	return logic.input;
}