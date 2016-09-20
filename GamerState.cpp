#include "sfwdraw.h"
#include "GameState.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"

void GameState::create(unsigned a_f, unsigned a_d, unsigned a_g)
{
	f = a_f;
	d = a_d;
	g = a_g;

	p1.createPaddle(20, 250, 100, 'W', 'S', BLUE, 0);
	p2.createPaddle(780, 250, 100, 'I', 'K', RED, 0);
}

void GameState::update()
{
	float acc = 10;
	float acc2 = 10;
	Ball b[5]; // you need an array of balls.

	for (int i = 0; i < 5; ++i)
		b[i].creatBall(400, 600 / 2, 20, GREEN, 20);

	int nActiveBalls = 1;
	bool gameOver = false;


	if (!gameOver)
	{

		// loop through update/draw active balls
		for (int i = 0; i < nActiveBalls && i < 5; ++i)
		{
			b[i].drawBall();
			b[i].updateBall(p1, p2);
		}

		p1.updatePaddle();
		p2.updatePaddle();



		drawScore(d, p1.score, p2.score);
		if (p1.score >= 20)
		{
			gameOver = true;
			drawWin(d);
		}
		if (p2.score >= 20)
		{
			gameOver = true;
			drawWin2(d);
		}
	}
	float timer = 5.f;
	while (sfw::stepContext())
	{
		// Timer needs to count down
		timer -= sfw::getDeltaTime();
		if (timer < 0)	// when timer finishes
		{
			nActiveBalls++; // increment active ball count
			timer = 3.f; // reset timer
		}
	}
}

void GameState::draw()
{
	drawTexture(g, 0, 600, 800, 600, 0, false);
	drawScore(d, p1.score, p2.score);
}

APP_STATE GameState::next()
{
	if (getKey('V'))
	{
		return ENTER_OPTION;
	}
	if (getKey('E'))
	{
		return ENTER_DEPART;
	}
	return GAMESTATE;
}