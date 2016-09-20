#include "paddle.h"
#include <iostream>
#include <time.h>
#include <cstdio>
#include <random>
#include "game.h"
#include "sfwdraw.h"
using namespace sfw;

void Paddle::createPaddle(float a_x, float a_y, float a_size, char a_up, char a_down, unsigned int a_color, int a_score)
{
	Paddle p;
	p.x = x;
	p.y = y;
	p.size = size;
	p.up = up;
	p.down = down;
	p.color = color;
	p.score = score;


}


void Paddle::updatePaddle()
{
	//sfw::drawLine(p.x, p.y, p.x, p.y + p.size, p.color);

	if (sfw::getKey(up))
		y += 12;

	if (sfw::getKey(down))
		y -= 12;


	if (y < 0) y = 0;
	if (y > 500) y = 500;
}

void Paddle::drawPaddle()
{
	drawLine(x, y, x, y + size, GREEN);
}