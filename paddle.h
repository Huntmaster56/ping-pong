#pragma once


class Paddle
{
public:
	float x, y = 100;
	char up = 0, down = 0;
	unsigned int color;
	float speed;
	float size;
	int score = 0;

	void createPaddle(float x, float y, float size, char up, char down, unsigned int color, int score);
	void updatePaddle();
	void drawPaddle();
};
