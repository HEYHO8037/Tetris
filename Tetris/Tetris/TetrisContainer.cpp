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

void TetrisContainer::RotateTetris(int direction)
{

	MoveDeleteTetris();

	if (direction == rotate)
	{
		for (int y = initZero; y < tetrisMaxY; y++)
		{
			for (int x = initZero; x < tetrisMaxX; x++)
			{
				calculateTetris = (*(*(saveTetris + y) + x)); //TetrisMember의 주소값을 Y씩 더한 다음에 값을 가져오고(첫번째 가져오기) 다시 X씩 더한 다음 값을 가져옴(2차원 배열)
				saveRotateTetris[MaxBlockNum-x][y] = calculateTetris; // 3,2,1,0 순으로 순차적으로 그린다.
			}
		}

		tetris->setTetrisMember(saveRotateTetris);
	}
	else if (direction == reRotate)
	{
		for (int y = initZero; y < tetrisMaxY; y++)
		{
			for (int x = MaxBlockNum; x >= initZero; x--)
			{
				calculateTetris = (*(*(saveTetris + x) + y)); //TetrisMember의 주소값을 Y씩 더한 다음에 값을 가져오고(첫번째 가져오기) 다시 X씩 더한 다음 값을 가져옴(2차원 배열)
				saveRotateTetris[y][MaxBlockNum-x] = calculateTetris;
			}
		}

		tetris->setTetrisMember(saveRotateTetris);
	}
}

void TetrisContainer::CheckAndRotateTetris()
{
	CheckRotateTetris();
	if (crashTetrisRotate == false)
	{
		RotateTetris(rotate);
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

			if (checkMapTetris > exist && width < mapX && width >= zero)
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

			if (checkMapTetris > exist
				&& width < mapX && width > zero
				&& height < mapY && height > zero)
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
void TetrisContainer::CheckRotateTetris()
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
	RotateTetris(rotate);
	ShowTetris();

	for (int y = initZero; y < tetrisMaxY; y++)
	{
		for (int x = initZero; x < tetrisMaxX; x++)
		{
			height = tetris->getposY() + y;
			width = tetris->getposX() + x;

			checkMapTetris = (*(map + height))[width];

			if (checkMapTetris > exist
				&& width < mapX && width >= zero
				&& height < mapY && height >= zero)
			{
				crashTetrisRotate = true;
				saveCrashX[crashNum] = width;
				saveCrashY[crashNum] = height;
				crashNum++;
			}
		}
	}

	MoveDeleteTetris();

	if (crashTetrisRotate == true)
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
			crashTetrisRotate = false;
		}
	}


	RotateTetris(reRotate);
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