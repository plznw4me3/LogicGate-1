#pragma once

class Clock : public CWnd {
public:
	int sec[2][7];	// bitmap용 sec
	int ms[2][7];	// bitmap용 ms
	int clk_sec;	// 현재 sec
	int clk_ms;		// 현재 ms
	bool flag;		// 진행 유무

public:
	void Reset();	// 시간 초기화
	void StopWatch(int clk_sec, int clk_ms);	// 시간 변환
	void DrawCLK(CDC *dc);	// 시간 그리기
	void IncCLK();	// 시간 증가
};