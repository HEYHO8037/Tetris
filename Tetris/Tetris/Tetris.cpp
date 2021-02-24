#include "Tetris.h"

Tetris::Tetris()
{
	srand(time(NULL));
	randNum = rand() % maxMember;

	for (int height = 0; height < maxY; height++)
	{
		for (int length = 0; length < maxX; length++)
		{
			tetrisSelectMember[height][length] = tetrisMember[randNum][height][length];
		}
	}

	posX = initX;
	posY = initY;
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
	else
	{
		return;
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
	else
	{
		return;
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

const int Tetris::getposY()
{
	return posY;
}

const bool Tetris::getIsChecked()
{
	return isChecked;
}

const int* Tetris::getTetrisMember()
{
	return *tetrisSelectMember;
}