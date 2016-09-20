#include "ball.h"
#include <iostream>
#include <cstdio>
#include "paddle.h"
#include "sfwdraw.h"
#include <math.h>
using namespace sfw;

void Ball::creatBall(float a_x, float a_y, float a_size, unsigned int a_color,float a_radius)
{

	Ball b;
	x = a_x;
	y = a_y;
	size = a_size;
	color = a_color;
	radius = a_radius;
	velx = 5;
	vely = 5;
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

	if ((x < x) && y > y && y < (y + size))
	{
		velx *= -1;
		x = x + radius;
	}
	if ((x > x) && y > y && y < (y + size))
	{
		velx *= -1;
		x = x - radius;
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

