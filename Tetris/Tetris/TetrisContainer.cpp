#include "TetrisContainer.h"

TetrisContainer::TetrisContainer()
{
	tetris = initPointer;
	int(*map)[40][20] = nullptr;
}

TetrisContainer::TetrisContainer(int getMap[MaxMapY][MaxMapX])
{
	map = getMap;
	lineCont = new LineContainer(getMap);
}

void TetrisContainer::InitTetris()
{
	tetris = new Tetris();
}

void TetrisContainer::ShowTetris()
{
	int y;
	int x;
	int h;

	for (int height = 0; height < 4; height++)
	{
		for (int length = 0; length < 4; length++)
		{
			y = tetris->getposY();
			x = tetris->getposX();
			h = (*(tetris->getTetrisMember() + height) + length);

			map[tetris->getposY() + height][tetris->getposX() + length] += tetris->getTetrisMember()[height][length];
		}
	}
}

void TetrisContainer::MoveTetris(int direction)
{

}
void TetrisContainer::MoveDeleteTetris()
{

}
void TetrisContainer::CheckTetris()
{

}
void TetrisContainer::DeleteTetris()
{

}