#pragma once


class Paddle
{
public:
	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color;
	float speed;
	int score = 0;


void createPaddle(float x, float y, float size, char up, char down, unsigned int color, int score);

void updatePaddle();

void drawPaddle();
};
