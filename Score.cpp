#include "sfwdraw.h"
#include "score.h"
#include <iostream>
#include <cstdio>
using namespace sfw;

void drawScore(unsigned font, int score1, int score2)
{
	char buffer[80] = { 0 };
	sprintf_s(buffer, "%d", score2);
	drawString(font, buffer, 700, 500, 20, 20);

	sprintf_s(buffer, "%d", score1);
	drawString(font, buffer, 100, 500, 20, 20);
}

void win(unsigned font)
{
	drawString(font, "Game over Player 1 wins", 300, 500, 10, 10);
}

void win2(unsigned font)
{
	drawString(font, "Game over Player 2 wins", 300, 500, 10, 10);
}

