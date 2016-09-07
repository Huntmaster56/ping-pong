
#include "sfwdraw.h"
#include "game.h"



void main()
{
	sfw::initContext(800, 600, "moving ball game");


	float acc = 10;
	float acc2 = 10;

	Paddle p1 = createPaddle(20, 250, 100, 'W', 'S', BLUE),
		   p2 = createPaddle(780, 250, 100, 'I', 'K', RED);

	Ball b = creatBall(400, 600 / 2, 20, GREEN);

	sfw::setBackgroundColor(BLACK);


	while (sfw::stepContext())
	{
		updateBall(b);
		updatePaddle(p1);
		updatePaddle(p2);
	}
	sfw::termContext();
	/*		sfw::drawLine(10, acc, 10, 100 + acc, GREEN);
		//sfw::drawCircle(400, 300, 15);
		if (sfw::getKey('W'))
			acc += 7;

		if (sfw::getKey('S'))
			acc -= 7;

		if (acc < 0)acc = 0;
		if (acc > 500)acc = 500;
	*/
}