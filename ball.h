#pragma once
#include <iostream>
#include <cstdio>
#include "paddle.h"
class Ball
{
	float x = 300, y = 400, size = 0, velx = 0, vely = 0, radius;
	unsigned int color = 0;
	float freezeTimer = 2;

public:
	void drawBall();
	void updateBall( Paddle &p1, Paddle &p2);
	void creatBall(float x, float y, float size, unsigned int color, float radius);
};



