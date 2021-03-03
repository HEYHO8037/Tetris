#include "Game.h"

void Game::Init()
{
	graphics = new Graphics();
	tetrisCont = new TetrisContainer(graphics->tetrisMap);
}

void Game::Update()
{
	while (true)
	{
		
	}
}

void Game::Release()
{
	delete tetrisCont;
	delete graphics;
}