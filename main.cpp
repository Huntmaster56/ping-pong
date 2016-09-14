
#include "sfwdraw.h"
#include "game.h"
#include "ball.h"
#include "paddle.h"
#include "score.h"


void main()
{
	sfw::initContext(800, 600, "moving ball game");
	int d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	float acc = 10;
	float acc2 = 10;

	Paddle p1 = createPaddle(20, 250, 100, 'W', 'S', BLUE, 0),
		   p2 = createPaddle(780, 250, 100, 'I', 'K', RED, 0);

	Ball b = creatBall(400, 600 / 2, 20, GREEN, 20);

	sfw::setBackgroundColor(BLACK);

	bool gameOver = false;
	while (sfw::stepContext())
	{

		if (!gameOver)
		{
			updateBall(b,p1,p2);
			updatePaddle(p1);
			updatePaddle(p2);

			drawBall(b);

			drawScore(d, p1.score, p2.score);
			if (p1.score >= 10)
			{
				gameOver = true;
				drawWin(d);
			}
			if (p2.score >= 10)
			{
				gameOver = true;
				drawWin2(d);
			}
		}
		if (p1.score >= 5)
		{
			gameOver = true;
			drawWin(d);
		}
		if (p2.score >= 5)
		{
			gameOver = true;
			drawWin2(d);
		}



	}

	sfw::termContext();
	