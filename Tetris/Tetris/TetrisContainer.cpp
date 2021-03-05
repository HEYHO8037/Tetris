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
		deleteTetris = false;
	}
}



void TetrisContainer::ShowTetris()
{
	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;
			calculateTetris = (*(*(saveTetris + y) + x)); //TetrisMember의 주소값을 Y씩 더한 다음에 값을 가져오고(첫번째 가져오기) 다시 X씩 더한 다음 값을 가져옴(2차원 배열)
			if (calculateTetris == exist)
			{
				(*(map + height))[width] += calculateTetris;
			}
		}
	}
}

void TetrisContainer::MoveTetris(int xORy, int direction)
{

	if (xORy == dirDown)
	{
		MoveDeleteTetris();
		tetris->ChangePosY(direction);
		ShowTetris();
		CheckTetris();
		if (crashTetris == true)
		{
			MoveDeleteTetris();
			if (direction == PLUS)
			{
				tetris->ChangePosY(MINUS);
			}
		}
		else
		{
			MoveDeleteTetris();
		}

	}
	else if (xORy == dirLeft || xORy == dirRight)
	{
		MoveDeleteTetris();
		tetris->ChangePosX(direction);
	}
}

void TetrisContainer::RotateTetris()
{
	MoveDeleteTetris();

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			calculateTetris = (*(*(saveTetris + y) + x)); //TetrisMember의 주소값을 Y씩 더한 다음에 값을 가져오고(첫번째 가져오기) 다시 X씩 더한 다음 값을 가져옴(2차원 배열)
			saveRotateTetris[x][y] = calculateTetris;
		}
	}

	for (int y = initZero; tetrisMaxY < 4; y++)
	{
		for (int x = initZero; tetrisMaxX < 4; x++)
		{
			tetris->setTetrisMember(saveRotateTetris[y][x]);
		}
	}
}

void TetrisContainer::MoveDeleteTetris()
{
	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			calculateTetris = (*(*(saveTetris + y) + x));
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;

			if ((*(map + height))[width] == exist && 
				(*(map + height))[width] == calculateTetris)
			{
				(*(map + height))[width] = 0;
			}
		}
	}
}
void TetrisContainer::CheckTetris()
{
	int checkMapTetris;

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			height = tetris->getposY()+y;
			width = tetris->getposX()+x;
			checkMapTetris = (*(map + height))[width];

			if (checkMapTetris > exist)
			{
				crashTetris = true;
				(*(map + height))[width] = exist;
			}
		}
	}
}

void TetrisContainer::LineProcess()
{
	isTetrisStop = tetris->getIsChecked();
	if (isTetrisStop == true)
	{
		lineCont->LineCheck();
		lineCont->LineDelete();
		lineCont->LineMove();
		lineCont->LineCreate();
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