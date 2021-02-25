#include "TetrisContainer.h"

TetrisContainer::TetrisContainer()
{
	tetris = initPointer;
	int(*map)[MaxMapX] = nullptr;
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
	int width;
	int height;
	int calculateTetris;
	const int (*saveTetris)[4] = *tetris->getTetrisMember();

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;
			calculateTetris = (*(*(saveTetris+y)+x)); //TetrisMember의 주소값을 Y씩 더한 다음에 값을 가져오고(첫번째 가져오기) 다시 X씩 더한 다음 값을 가져옴(2차원 배열)

			map[height][width] += calculateTetris;
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