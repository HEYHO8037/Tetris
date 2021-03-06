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
		CheckTetrisDown();
		if (crashTetrisY == false)
		{
			tetris->ChangePosY(direction);
		}
	}
	else if (xORy == dirLeft || xORy == dirRight)
	{
		CheckTetrisLR(direction);
		if (crashTetrisX == false)
		{
			tetris->ChangePosX(direction);
		}
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

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
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
void TetrisContainer::CheckTetrisLR(int direction)
{
	int checkMapTetris = initZero;
	int crashNum = initZero;
	int crashPosY = initZero;
	int crashPosX = initZero;

	for (int num = initZero; num < MaxSaveNum; num++)
	{
		saveCrashX[num] = noInside;
		saveCrashY[num] = noInside;
	}

	MoveDeleteTetris();
	tetris->ChangePosX(direction);
	ShowTetris();

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;

			checkMapTetris = (*(map + height))[width];

			if (checkMapTetris > exist)
			{
				crashTetrisX = true;			
				saveCrashX[crashNum] = width;
				saveCrashY[crashNum] = height;
				crashNum++;
			}
		}
	}

	MoveDeleteTetris();

	if (direction == PLUS)
	{
		tetris->ChangePosX(MINUS);
	}
	else if (direction == MINUS)
	{
		tetris->ChangePosX(PLUS);
	}
	
	if (crashTetrisX == true)
	{
		if (saveCrashX[initZero] != noInside && saveCrashY[initZero] != noInside)
		{
			for (int num = initZero; num < crashNum; num++)
			{
				crashPosX = saveCrashX[num];
				crashPosY = saveCrashY[num];
				(*(map + crashPosY))[crashPosX] = exist;
			}
		}
		else
		{
			crashTetrisX = false;
		}

	}
	else
	{
		crashTetrisX = false;
	}
}

void TetrisContainer::CheckTetrisDown()
{
	int checkMapTetris = initZero;
	int crashNum = initZero;
	int crashPosY = initZero;
	int crashPosX = initZero;

	for (int num = initZero; num < MaxSaveNum; num++)
	{
		saveCrashX[num] = noInside;
		saveCrashY[num] = noInside;
	}

	MoveDeleteTetris();
	tetris->ChangePosY(PLUS);
	ShowTetris();

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;

			checkMapTetris = (*(map + height))[width];

			if (checkMapTetris > exist && width < mapX && height < mapY)
			{
				crashTetrisY = true;
				saveCrashX[crashNum] = width;
				saveCrashY[crashNum] = height;
				crashNum++;
			}
		}
	}

	MoveDeleteTetris();
	tetris->ChangePosY(MINUS);

	if (crashTetrisY == true)
	{
		for (int num = initZero; num < 4; num++)
		{
			crashPosX = saveCrashX[num];
			crashPosY = saveCrashY[num];
			(*(map + crashPosY))[crashPosX] = exist;
		}
			tetris->ChangeisChecked();
	}
	else
	{
		crashTetrisY = false;
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
	bool tetrisGetChecked = tetris->getIsChecked();
	if (tetrisGetChecked == true)
	{
		deleteTetris = true;
		crashTetrisY = false;
		crashTetrisX = false;
		delete tetris;
	}
}

void TetrisContainer::DeleteLineContainer()
{
	delete lineCont;
}