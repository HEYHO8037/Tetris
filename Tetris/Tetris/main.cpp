#include "Game.h"
int main(void)
{
	int score = 0;
	Graphics* gph = new Graphics();
	TetrisContainer* ts = new TetrisContainer(gph->tetrisMap);

	gph->InitMap(score);
	ts->InitTetris();
	ts->ShowTetris();

	gph->UpdateMap();

	return 0;
}