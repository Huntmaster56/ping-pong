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

	for (int i = 0; i < 5; ++i)
		b[i].creatBall(400, 600 / 2, 20, GREEN, 20);

	gameOver = false;
}

void GameState::update()
{
	if (!gameOver)
	{
		// loop through update/draw active balls
		for (int i = 0; i < nActiveBalls && i < 5; ++i)
		{
			b[i].updateBall(p1, p2);
		}

		p1.updatePaddle();
		p2.updatePaddle();
		b1.updateBall(p1,p2);
		if (p1.score >= 20)
		{
			gameOver = true;
		}
		if (p2.score >= 20)
		{
			gameOver = true;
		}
	}
	
	// Timer needs to count down
	timer -= sfw::getDeltaTime();
	if (timer < 0)	// when timer finishes
	{
		nActiveBalls++; // increment active ball count
		timer = 5.f; // reset timer
	}
}

void GameState::draw()
{
	drawTexture(g, 0, 600, 800, 600, 0, false);

	// draw balls
	for (int i = 0; i < nActiveBalls && i < 5; ++i)
	{
		b[i].drawBall();
	}

	p1.drawPaddle();
	p2.drawPaddle();
	b1.drawBall();
	drawScore(d, p1.score, p2.score);

	// drawing the winner
	if (p1.score >= 20)
	{
		drawWin(d);
	}
	if (p2.score >= 20)
	{
		drawWin2(d);
	}
}

APP_STATE GameState::next()
{
	return GAMESTATE;
}
