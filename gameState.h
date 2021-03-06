#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include "ball.h"
#include "score.h"
#include "constdecl.h"
using namespace sfw;

class GameState
{
private:

	unsigned f;
	unsigned d;
	unsigned g;

	Paddle p1;
	Paddle p2;
	Ball b1;
	int nActiveBalls = 1;
	Ball b[5];

	bool gameOver;
	float timer;

public:
	void create(unsigned f, unsigned d, unsigned g);
	void update();
	void draw();
	APP_STATE next();
};
