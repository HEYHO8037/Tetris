#include "LineContainer.h"

LineContainer::LineContainer()
{
	map = initPointer;
	lineNum = reset;
}

LineContainer::LineContainer(int getMap[40][20])
{
	map = getMap;
}

void LineContainer::LineCheck()
{
	for (int y = 0; y < edgeMapY; y++)
	{
		for (int x = 0; x < edgeMapX; x++)
		{
			if (map[y][x] == 0)
			{
				isLineChecked = false;
			}
		}
		if (isLineChecked == true)
		{
			saveLineY[lineNum] = y;
			lineNum++;
		}
	}
}

void LineContainer::LineDelete()
{
	int lineY;
	int deletecount = reset;

	if (lineNum != 0)
	{
		for (int num = 0; num < lineNum; num++)
		{
			lineY = saveLineY[num];

			if (num > 0)
			{
				lineY = lineY - deletecount;
			}

			for (int x = 0; x < edgeMapX; x++)
			{
				map[lineY][x] = reset;
			}

			deletecount++;
		}
	}
}

void LineContainer::LineCreate()
{
	srand(time(NULL));
	int emptyblock = rand() % 20;
	
	for (int x = 0; x < edgeMapX; x++)
	{
		if (x == emptyblock)
		{
			map[lastLineY][x] = 0;
		}
		else
		{
			map[lastLineY][x] = 1;
		}
	}
}

void LineContainer::LineMove()
{
	for (int y = lastLineY; y > 0; y--)
	{
		for (int x = 0; x < edgeMapX; x++)
		{
			if (y == lastLineY)
			{
				savefrontLine[first][x] = map[y][x];
				map[y][x] = 0;
			}
			else
			{
				savefrontLine[second][x] = map[y][x];
				map[y][x] = savefrontLine[first][x];
				savefrontLine[first][x] = savefrontLine[second][x];
			}
		}
	}
}