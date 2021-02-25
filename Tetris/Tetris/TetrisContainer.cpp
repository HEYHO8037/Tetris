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
			calculateTetris = (*(*(saveTetris+y)+x)); //TetrisMember�� �ּҰ��� Y�� ���� ������ ���� ��������(ù��° ��������) �ٽ� X�� ���� ���� ���� ������(2���� �迭)

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