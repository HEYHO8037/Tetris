#include "Game.h"
int main(void)
{
	Game* game = new Game();

	game->Init();
	game->Update();
	game->Release();

	return 0;
}