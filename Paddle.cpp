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
	x = a_x;
	y = a_y;
	size = a_size;
	up = a_up;
	down = a_down;
	color = a_color;
	score = a_score;
}


void Paddle::updatePaddle()
{
	//sfw::drawLine(p.x, p.y, p.x, p.y + p.size, p.color);

	if (sfw::getKey(up) && y < 500)
		y += 12;

	if (sfw::getKey(down) && y > 0)
		y -= 12;


	
}

void Paddle::drawPaddle()
{
	drawLine(x, y, x, y + size, GREEN);
}