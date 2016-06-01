#pragma once

class Clock : public CWnd {
public:
	int sec[2][7];	// bitmap�� sec
	int ms[2][7];	// bitmap�� ms
	int clk_sec;	// ���� sec
	int clk_ms;		// ���� ms
	bool flag;		// ���� ����

public:
	void Reset();	// �ð� �ʱ�ȭ
	void StopWatch(int clk_sec, int clk_ms);	// �ð� ��ȯ
	void DrawCLK(CDC *dc);	// �ð� �׸���
	void IncCLK();	// �ð� ����
};