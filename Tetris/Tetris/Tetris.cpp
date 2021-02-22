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