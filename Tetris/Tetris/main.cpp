#include "Game.h"
int main(void)
{
	system("mode con cols=40 lines=50");
	Game* game = new Game();

	game->Init();
	game->Update();
	game->Release();

	delete game;
	return 0;
}