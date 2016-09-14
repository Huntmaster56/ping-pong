#include "paddle.h"
#include <iostream>
#include <time.h>
#include <cstdio>
#include <random>
#include "game.h"
Paddle createPaddle(float x, float y, float size, char up, char down, unsigned int color, int score)
{
	Paddle p;
	p.x = x;
	p.y = y;
	p.size = size;
	p.up = up;
	p.down = down;
	p.color = color;
	p.score = score;

	return p;
}


void updatePaddle(Paddle &p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.size, p.color);

	if (sfw::getKey(p.up))
		p.y += 10;

	if (sfw::getKey(p.down))
		p.y -= 10;


	if (p.y < 0) p.y = 0;
	if (p.y > 500) p.y = 500;
}
