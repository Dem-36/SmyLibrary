#ifndef _DISPLAYFPS_H_
#define _DISPLAYFPS_H_

#include"DxLib.h"

#define N 60
#define FPS 60

class DisplayFPS {
public:
	DisplayFPS() {
		startTime = 0;
		count = 0;
		fps = 0.0f;
	}

	bool Update() {
		if (count == 0)
			startTime = GetNowCount();//PC���N�����Ă���̕b���i�~���P��)
		if (count == N) {
			int t = GetNowCount();
			fps = 1000.0f / ((t - startTime) / (float)N);
			count = 0;
			startTime = t;
		}
		count++;
		return true;
	}

	void Draw() {
		//%.1f = float�^��Format���Z�q .1 = �����_���ʂ܂ŕ\��
		DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", fps);
	}

	void Wait() {
		int tookTime = GetNowCount() - startTime;
		int waitTime = count * 1000 / FPS - tookTime;
		if (waitTime > 0) {
			Sleep(waitTime);
		}
	}

private:
	int startTime;
	int count;
	float fps;
};

#endif