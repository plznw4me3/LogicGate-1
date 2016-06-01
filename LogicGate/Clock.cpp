#include "stdafx.h"
#include "Clock.h"
#include "LogicGate.h"

/* 시간 초기화 */
void Clock::Reset() {
	// sec 초기화
	sec[0][0] = 1;
	sec[0][1] = 1;
	sec[0][2] = 1;
	sec[0][3] = 1;
	sec[0][4] = 1;
	sec[0][5] = 1;
	sec[0][6] = 0;
	sec[1][0] = 1;
	sec[1][1] = 1;
	sec[1][2] = 1;
	sec[1][3] = 1;
	sec[1][4] = 1;
	sec[1][5] = 1;
	sec[1][6] = 0;

	// ms 초기화
	ms[0][0] = 1;
	ms[0][1] = 1;
	ms[0][2] = 1;
	ms[0][3] = 1;
	ms[0][4] = 1;
	ms[0][5] = 1;
	ms[0][6] = 0;
	ms[1][0] = 1;
	ms[1][1] = 1;
	ms[1][2] = 1;
	ms[1][3] = 1;
	ms[1][4] = 1;
	ms[1][5] = 1;
	ms[1][6] = 0;

	clk_sec = 0;
	clk_ms = 0;
	flag = false;
}

/* 시간 변환 */
void Clock::StopWatch(int clk_sec, int clk_ms)
{
	int sec1, sec2;
	int ms1, ms2;

	// 각 자리수 구분
	sec1 = clk_sec / 10;
	sec2 = clk_sec % 10;
	ms1 = clk_ms / 10;
	ms2 = clk_ms % 10;

	switch (sec1) {	// sec 십의 자리
	case 0:
		sec[0][0] = 1;
		sec[0][1] = 1;
		sec[0][2] = 1;
		sec[0][3] = 1;
		sec[0][4] = 1;
		sec[0][5] = 1;
		sec[0][6] = 0;
		break;
	case 1:
		sec[0][0] = 0;
		sec[0][1] = 1;
		sec[0][2] = 1;
		sec[0][3] = 0;
		sec[0][4] = 0;
		sec[0][5] = 0;
		sec[0][6] = 0;
		break;
	case 2:
		sec[0][0] = 1;
		sec[0][1] = 1;
		sec[0][2] = 0;
		sec[0][3] = 1;
		sec[0][4] = 1;
		sec[0][5] = 0;
		sec[0][6] = 1;
		break;
	case 3:
		sec[0][0] = 1;
		sec[0][1] = 1;
		sec[0][2] = 1;
		sec[0][3] = 1;
		sec[0][4] = 0;
		sec[0][5] = 0;
		sec[0][6] = 1;
		break;
	case 4:
		sec[0][0] = 0;
		sec[0][1] = 1;
		sec[0][2] = 1;
		sec[0][3] = 0;
		sec[0][4] = 0;
		sec[0][5] = 1;
		sec[0][6] = 1;
		break;
	case 5:
		sec[0][0] = 1;
		sec[0][1] = 0;
		sec[0][2] = 1;
		sec[0][3] = 1;
		sec[0][4] = 0;
		sec[0][5] = 1;
		sec[0][6] = 1;
		break;
	}
	switch (sec2) { // sec 일의 자리
	case 0:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 1;
		sec[1][5] = 1;
		sec[1][6] = 0;
		break;
	case 1:
		sec[1][0] = 0;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 0;
		sec[1][4] = 0;
		sec[1][5] = 0;
		sec[1][6] = 0;
		break;
	case 2:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 0;
		sec[1][3] = 1;
		sec[1][4] = 1;
		sec[1][5] = 0;
		sec[1][6] = 1;
		break;
	case 3:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 0;
		sec[1][5] = 0;
		sec[1][6] = 1;
		break;
	case 4:
		sec[1][0] = 0;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 0;
		sec[1][4] = 0;
		sec[1][5] = 1;
		sec[1][6] = 1;
		break;
	case 5:
		sec[1][0] = 1;
		sec[1][1] = 0;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 0;
		sec[1][5] = 1;
		sec[1][6] = 1;
		break;
	case 6:
		sec[1][0] = 1;
		sec[1][1] = 0;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 1;
		sec[1][5] = 1;
		sec[1][6] = 1;
		break;
	case 7:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 0;
		sec[1][4] = 0;
		sec[1][5] = 1;
		sec[1][6] = 0;
		break;
	case 8:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 1;
		sec[1][5] = 1;
		sec[1][6] = 1;
		break;
	case 9:
		sec[1][0] = 1;
		sec[1][1] = 1;
		sec[1][2] = 1;
		sec[1][3] = 1;
		sec[1][4] = 0;
		sec[1][5] = 1;
		sec[1][6] = 1;
		break;
	}

	switch (ms1) { // ms 십의 자리
	case 0:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 1;
		ms[0][5] = 1;
		ms[0][6] = 0;
		break;
	case 1:
		ms[0][0] = 0;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 0;
		ms[0][4] = 0;
		ms[0][5] = 0;
		ms[0][6] = 0;
		break;
	case 2:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 0;
		ms[0][3] = 1;
		ms[0][4] = 1;
		ms[0][5] = 0;
		ms[0][6] = 1;
		break;
	case 3:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 0;
		ms[0][5] = 0;
		ms[0][6] = 1;
		break;
	case 4:
		ms[0][0] = 0;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 0;
		ms[0][4] = 0;
		ms[0][5] = 1;
		ms[0][6] = 1;
		break;
	case 5:
		ms[0][0] = 1;
		ms[0][1] = 0;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 0;
		ms[0][5] = 1;
		ms[0][6] = 1;
		break;
	case 6:
		ms[0][0] = 1;
		ms[0][1] = 0;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 1;
		ms[0][5] = 1;
		ms[0][6] = 1;
		break;
	case 7:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 0;
		ms[0][4] = 0;
		ms[0][5] = 1;
		ms[0][6] = 0;
		break;
	case 8:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 1;
		ms[0][5] = 1;
		ms[0][6] = 1;
		break;
	case 9:
		ms[0][0] = 1;
		ms[0][1] = 1;
		ms[0][2] = 1;
		ms[0][3] = 1;
		ms[0][4] = 0;
		ms[0][5] = 1;
		ms[0][6] = 1;
		break;
	}
	switch (ms2) { // 초 두번째 자리
	case 0:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 1;
		ms[1][5] = 1;
		ms[1][6] = 0;
		break;
	case 1:
		ms[1][0] = 0;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 0;
		ms[1][4] = 0;
		ms[1][5] = 0;
		ms[1][6] = 0;
		break;
	case 2:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 0;
		ms[1][3] = 1;
		ms[1][4] = 1;
		ms[1][5] = 0;
		ms[1][6] = 1;
		break;
	case 3:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 0;
		ms[1][5] = 0;
		ms[1][6] = 1;
		break;
	case 4:
		ms[1][0] = 0;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 0;
		ms[1][4] = 0;
		ms[1][5] = 1;
		ms[1][6] = 1;
		break;
	case 5:
		ms[1][0] = 1;
		ms[1][1] = 0;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 0;
		ms[1][5] = 1;
		ms[1][6] = 1;
		break;
	case 6:
		ms[1][0] = 1;
		ms[1][1] = 0;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 1;
		ms[1][5] = 1;
		ms[1][6] = 1;
		break;
	case 7:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 0;
		ms[1][4] = 0;
		ms[1][5] = 1;
		ms[1][6] = 0;
		break;
	case 8:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 1;
		ms[1][5] = 1;
		ms[1][6] = 1;
		break;
	case 9:
		ms[1][0] = 1;
		ms[1][1] = 1;
		ms[1][2] = 1;
		ms[1][3] = 1;
		ms[1][4] = 0;
		ms[1][5] = 1;
		ms[1][6] = 1;
		break;
	}
}

/* 시간 그리기 */
void Clock::DrawCLK(CDC *dc)
{
	CBitmap ch_black, ch_gray, cw_black, cw_gray;
	ch_black.LoadBitmapW(height_black);
	ch_gray.LoadBitmapW(height_gray);
	cw_black.LoadBitmapW(width_black);
	cw_gray.LoadBitmapW(width_gray);

	CDC h_black, h_gray, w_black, w_gray;
	h_black.CreateCompatibleDC(dc);
	h_gray.CreateCompatibleDC(dc);
	w_black.CreateCompatibleDC(dc);
	w_gray.CreateCompatibleDC(dc);
	h_black.SelectObject(&ch_black);
	h_gray.SelectObject(&ch_gray);
	w_black.SelectObject(&cw_black);
	w_gray.SelectObject(&cw_gray);

	// sec 그리기
	if (sec[0][0] == 0)
		dc->StretchBlt(20, 30, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);			// a
	else
		dc->StretchBlt(20, 30, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// a
	if (sec[0][1] == 0)
		dc->StretchBlt(105, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// b
	else
		dc->StretchBlt(105, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// b
	if (sec[0][2] == 0)
		dc->StretchBlt(105, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// c
	else
		dc->StretchBlt(105, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// c
	if (sec[0][3] == 0)
		dc->StretchBlt(20, 230, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);		// d
	else
		dc->StretchBlt(20, 230, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// d
	if (sec[0][4] == 0)
		dc->StretchBlt(0, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);			// e
	else
		dc->StretchBlt(0, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// e
	if (sec[0][5] == 0)
		dc->StretchBlt(0, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);			// f
	else
		dc->StretchBlt(0, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);			// f
	if (sec[0][6] == 0)
		dc->StretchBlt(20, 130, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);		// g
	else
		dc->StretchBlt(20, 130, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// g

	if (sec[1][0] == 0)
		dc->StretchBlt(20 + 150, 30, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// a
	else
		dc->StretchBlt(20 + 150, 30, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);	// a
	if (sec[1][1] == 0)
		dc->StretchBlt(105 + 150, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// b
	else
		dc->StretchBlt(105 + 150, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);	// b
	if (sec[1][2] == 0)
		dc->StretchBlt(105 + 150, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// c
	else
		dc->StretchBlt(105 + 150, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);// c
	if (sec[1][3] == 0)
		dc->StretchBlt(20 + 150, 230, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// d
	else
		dc->StretchBlt(20 + 150, 230, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);	// d
	if (sec[1][4] == 0)
		dc->StretchBlt(0 + 150, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// e
	else
		dc->StretchBlt(0 + 150, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);	// e
	if (sec[1][5] == 0)
		dc->StretchBlt(0 + 150, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// f
	else
		dc->StretchBlt(0 + 150, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);	// f
	if (sec[1][6] == 0)
		dc->StretchBlt(20 + 150, 130, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// g
	else
		dc->StretchBlt(20 + 150, 130, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);	// g


																					// ms 그리기
	if (ms[0][0] == 0)
		dc->StretchBlt(420, 30, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);		// a
	else
		dc->StretchBlt(420, 30, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// a
	if (ms[0][1] == 0)
		dc->StretchBlt(505, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// b
	else
		dc->StretchBlt(505, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// b
	if (ms[0][2] == 0)
		dc->StretchBlt(505, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// c
	else
		dc->StretchBlt(505, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// c
	if (ms[0][3] == 0)
		dc->StretchBlt(420, 230, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);		// d
	else
		dc->StretchBlt(420, 230, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// d
	if (ms[0][4] == 0)
		dc->StretchBlt(400, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// e
	else
		dc->StretchBlt(400, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// e
	if (ms[0][5] == 0)
		dc->StretchBlt(400, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);		// f
	else
		dc->StretchBlt(400, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);		// f
	if (ms[0][6] == 0)
		dc->StretchBlt(420, 130, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);		// g
	else
		dc->StretchBlt(420, 130, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);		// g

	if (ms[1][0] == 0)
		dc->StretchBlt(420 + 150, 30, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// a
	else
		dc->StretchBlt(420 + 150, 30, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);	// a
	if (ms[1][1] == 0)
		dc->StretchBlt(505 + 150, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// b
	else
		dc->StretchBlt(505 + 150, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);	// b
	if (ms[1][2] == 0)
		dc->StretchBlt(505 + 150, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// c
	else
		dc->StretchBlt(505 + 150, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);// c
	if (ms[1][3] == 0)
		dc->StretchBlt(420 + 150, 230, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// d
	else
		dc->StretchBlt(420 + 150, 230, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);// d
	if (ms[1][4] == 0)
		dc->StretchBlt(400 + 150, 145, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// e
	else
		dc->StretchBlt(400 + 150, 145, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);// e
	if (ms[1][5] == 0)
		dc->StretchBlt(400 + 150, 45, 100, 100, &h_gray, 0, 0, 100, 100, SRCCOPY);	// f
	else
		dc->StretchBlt(400 + 150, 45, 100, 100, &h_black, 0, 0, 100, 100, SRCCOPY);	// f
	if (ms[1][6] == 0)
		dc->StretchBlt(420 + 150, 130, 100, 100, &w_gray, 0, 0, 100, 100, SRCCOPY);	// g
	else
		dc->StretchBlt(420 + 150, 130, 100, 100, &w_black, 0, 0, 100, 100, SRCCOPY);// g
}

/* 시간 증가 */
void Clock::IncCLK()
{
	clk_ms++;

	if (clk_ms == 100) {
		clk_sec++;
		clk_ms = 0;
	}

	if (clk_sec == 60) {
		clk_sec = 0;
	}
}
