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


Ball creatBall(float x, float y, float size, unsigned int color)
{

	Ball b;
	b.x = x;
	b.y = y;
	b.size = size;
	b.color = color;

	b.velx = 8;
	b.vely = 8;

	return b;
}

void drawBall(const Ball &b)
{
	sfw::drawCircle(b.x, b.y, b.size, 12, b.color);
}

struct Paddle
{
	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color = 0;

};


void updateBall(Ball &b, Paddle &p1, Paddle &p2)
{



	if (b.x < 0)
	{
		//p1.score++;
		//b.freezeTimer = 2;
		//
		//printf("%d to %d \n", p1.score, p2.score);
		//b.x = 30;
		//b.y = 300;
		
		
		b.velx *= -1;
	}


	if (b.x > 800)
	{
		//p2.score++;
		//b.freezeTimer = 2;
		//printf("%d to %d \n", p1.score, p2.score);
		//b.x = 770;
		//b.y = 300;
		//b.velx *= -1;




		b.velx *= -1;


	}
	if (b.y < 0)
		b.vely *= -1;

	if (b.y > 600)
		b.vely *= -1;

	b.x += b.velx;
	b.y += b.vely;


}





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

//void drawScore(unsigned font, int p1score, int p2score)
//{
//	char buffer[64] = { 0 };
//	sprintf_s(buffer, "%d", p1score);
//	sfw::drawString(font, buffer, 650, 600, 40, 40);
//
//	sprintf_s(buffer, "%d", p2score);
//	sfw::drawString(font, buffer, 100, 600, 40, 40);
//}

void drawWin(unsigned font)
{

	sfw::drawString(font, "Game over player 2 wins", 160, 600, 20, 20);


}

void drawWin2(unsigned font)
{

	sfw::drawString(font, "Game over player 1 wins", 160, 600, 20, 20);


}

