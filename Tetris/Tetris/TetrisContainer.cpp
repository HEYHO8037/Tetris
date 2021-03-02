#include "TetrisContainer.h"

TetrisContainer::TetrisContainer()
{
	tetris = initPointer;
	int(*map)[mapX] = nullptr;
}

TetrisContainer::TetrisContainer(int getMap[mapY][mapX])
{
	map = getMap;
	lineCont = new LineContainer(getMap);
}

void TetrisContainer::InitTetris()
{
	if (deleteTetris == true)
	{
		tetris = new Tetris();
		saveTetris = *tetris->getTetrisMember();
		deleteTetris == false;
	}
}

void TetrisContainer::ShowTetris()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;
			calculateTetris = (*(*(saveTetris + y) + x)); //TetrisMember�� �ּҰ��� Y�� ���� ������ ���� ��������(ù��° ��������) �ٽ� X�� ���� ���� ���� ������(2���� �迭)
			map[height][width] += calculateTetris;
		}
	}
}

void TetrisContainer::MoveTetris(int xORy, int direction)
{

	if (xORy == dirUp || xORy == dirDown)
	{
		MoveDeleteTetris();
		tetris->ChangePosY(direction);
		ShowTetris();
	}
	else if (xORy == dirLeft || xORy == dirRight)
	{
		MoveDeleteTetris();
		tetris->ChangePosY(direction);
		ShowTetris();
	}
}
void TetrisContainer::MoveDeleteTetris()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;
			map[height][width] = 0;
		}
	}
}
void TetrisContainer::CheckTetris()
{
	int savePosition = 0;
	int saveXPos;
	int saveYPos;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;
			calculateTetris = (*(*(saveTetris + y) + x)); //TetrisMember�� �ּҰ��� Y�� ���� ������ ���� ��������(ù��° ��������) �ٽ� X�� ���� ���� ���� ������(2���� �迭)

			if (map[height][width] == calculateTetris)
			{
				saveX[savePosition] = width;
				saveY[savePosition] = height;
				savePosition++;
			}
		}
	}

	for (int position = 0; position < savePosition; position++)
	{
		saveXPos = saveX[position];
		saveYPos = ++saveY[position];

		if (map[saveYPos][saveXPos] == exist)
		{
			tetris->ChangeisChecked();
		}
	}
}


void TetrisContainer::DeleteTetris()
{
	if (tetris->getIsChecked() == true)
	{
		delete tetris;
		deleteTetris = true;
	}
}