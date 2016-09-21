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

	if ((x - radius < p1.x)				&&		// lef of ball < x	 of paddle 
		 y - radius < (p1.y + p1.size)	&&		// bot of ball < top of paddle
		 y + radius >  p1.y)								// top of ball > bot of paddle
	{
		velx *= -1;
		x = p1.x + radius;
	}

	if ((x + radius > p2.x) &&
		y - radius  < (p2.y + p2.size) &&
		y + radius  > p2.y)
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

