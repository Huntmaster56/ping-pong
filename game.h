#pragma once
#include "sfwdraw.h"
#include <iostream>
#include <time.h>
#include <cstdio>
#include <random>

//void creatPaddle(float &acc, float &acc2)

struct Ball
{
	float x = 300, y = 400, size = 0, velx = 0, vely = 0;
	unsigned int color = 0;
	float freezeTimer = 2;
};

float randRange(int start, int end)
{
	srand(time(0));
	return rand() % (end - start + 1) + start;
}

Ball creatBall(float x, float y, float size, unsigned int color)
{

	Ball b;
	b.x = x;
	b.y = y;
	b.size = size;
	b.color = color;
	b.velx = randRange(5, 10);
	b.vely = randRange(5, 10);


	return b;
}

void drawBall(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
}


int updateBall(Ball &b, Paddle &p1, Paddle &p2)
{
	b.freezeTimer -= sfw::getDeltaTime();
	if (b.freezeTimer > 0) return;

	if (b.x < 0)
		b.velx *= -1;

	if (b.x > 800)
		b.velx *= -1;

	if (b.y < 0)
		b.vely *= -1;

	if (b.y > 600)
		b.vely *= -1;

	b.x += b.velx;
	b.y += b.vely;

	return b.x;
}


struct Paddle
{
	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color= 0;
	
};


Paddle createPaddle(float x, float y, float size, char up, char down, unsigned int color)
{
	Paddle p;
	p.x = x;
	p.y = y;
	p.size = size;

	p.up = up;
	p.down = down;

	p.color = color;

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

