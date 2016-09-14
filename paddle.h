#pragma once


struct Paddle
{
	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color = 0;
	int score = 0;
};

void updatePaddle(Paddle &p);

Paddle createPaddle(float x, float y, float size, char up, char down, unsigned int color, int score);
