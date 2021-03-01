#include "Game.h"
int main(void)
{
	int score = 0;
	Graphics* gph = new Graphics();
	TetrisContainer* ts = new TetrisContainer(gph->tetrisMap);

	gph->InitMap(score);
	gph->CreateBuffer();
	gph->ClearBuffer();

	ts->InitTetris();

	ts->ShowTetris();

	gph->UpdateMap();
	gph->FlippingBuffer();



	gph->DeleteBuffer();
	delete ts;
	delete gph;
	return 0;
}