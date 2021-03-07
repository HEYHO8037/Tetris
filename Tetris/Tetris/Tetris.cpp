#include "Tetris.h"

Tetris::Tetris()
{
	srand(time(NULL));
	randNum = rand() % maxMember;

	for (int height = 0; height < tetrisMaxY; height++)
	{
		for (int length = 0; length < tetrisMaxX; length++)
		{
			tetrisSelectMember[height][length] = tetrisMember[randNum][height][length];
		}
	}
	posX = initTetrisX;
	posY = initTetrisY;
	isChecked = false;
}


void Tetris::ChangePosX(int plusminus)
{
	if (plusminus == PLUS)
	{
		posX++;
	}
	else if(plusminus == MINUS)
	{
		posX--;
	}
}

void Tetris::ChangePosY(int plusminus)
{
	if (plusminus == PLUS)
	{
		posY++;
	}
	else if (plusminus == MINUS)
	{
		posY--;
	}
}

void Tetris::ChangeisChecked()
{
	isChecked = !isChecked;
}

const int Tetris::getposX()
{
	return posX;
}

int Tetris::getposY()
{
	return posY;
}

const bool Tetris::getIsChecked()
{
	return isChecked;
}

const TetrisType* Tetris::getTetrisMember()
{
	 return &tetrisSelectMember;
}

const void Tetris::setTetrisMember(int settingMember[4][4])
{
	saveSettingMember = settingMember;
	
	for (int y = initZero; y < blockNum; y++)
	{
		for (int x = initZero; x < blockNum; x++)
		{
			tetrisSelectMember[y][x] = *(*(saveSettingMember + y) + x);
		}
	}
}