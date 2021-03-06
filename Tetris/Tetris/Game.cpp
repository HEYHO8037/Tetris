#include "Game.h"

void Game::Init()
{
	graphics = new Graphics();
	tetrisCont = new TetrisContainer(graphics->tetrisMap);

	graphics->CreateBuffer();
	graphics->InitMap(score);
}

void Game::Update()
{
	while (true)
	{
		graphics->ClearBuffer();
		graphics->UpdateMap();
		graphics->FlippingBuffer();

		tetrisCont->InitTetris();

		
		if (_kbhit())
		{
			keyNum = _getch();
			if (keyNum == arrowPress)
			{
				keyNum = _getch();
				switch (keyNum)
				{
				case arrowLeft:
					tetrisCont->MoveTetris(dirLeft, MINUS);
					break;
				case arrowRight:
					tetrisCont->MoveTetris(dirRight, PLUS);
					break;
				case arrowDown:
					tetrisCont->MoveTetris(dirDown, PLUS);
					break;
				}
			}
			else
			{
				if (keyNum == spaceBar)
				{
					tetrisCont->RotateTetris();
				}
			}
		}

		tetrisCont->MoveTetris(dirDown, PLUS);
		tetrisCont->ShowTetris();
		tetrisCont->DeleteTetris();

		Sleep(100);
	}
}

void Game::Release()
{
	delete tetrisCont;
	delete graphics;
}