#include "ball.h"
#include <iostream>
#include <cstdio>
#include "paddle.h"
#include "sfwdraw.h"
#include <math.h>
using namespace sfw;

void Ball::creatBall(float x, float y, float size, unsigned int color,float a_radius)
{

	Ball b;
	x = x;
	y = y;
	size = size;
	color = color;
	radius = a_radius;
	velx = 8;
	vely = 8;
}

void Ball::drawBall()
{
	drawCircle(x, y, size, 12, color);
}

void Ball::updateBall(Paddle &p1, Paddle &p2)
{
	if (x < 0)
	{
		velx *= -1;
	}

	if (x > 800)
	{
		velx *= -1;
	}
	if (y < 0)
		vely *= -1;

	if (y > 600)
		vely *= -1;

	if ((x < p1.x) && y > p1.y && y < (p1.y + p1.size))
	{
		velx *= -1;
		x = p1.x + radius;
	}
	if ((x > p2.x) && y > p2.y && y < (p2.y + p2.size))
	{
		velx *= -1;
		x = p2.x - radius;
	}
	if (x < 0)
	{
		p2.score++;
		printf("%d %d", p1.score, p2.score);
		x = 300;
	}
	if (x > 800)
	{
		p1.score++;
		printf("%d %d", p1.score, p2.score);
		x = 300;
	}
	x += velx;
	y += vely;
}

