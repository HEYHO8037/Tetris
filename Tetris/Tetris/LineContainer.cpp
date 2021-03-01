#include "LineContainer.h"

LineContainer::LineContainer()
{
	map = initPointer;
}

LineContainer::LineContainer(int getMap[40][20])
{
	map = getMap;
}

void LineContainer::LineCheck()
{
	int lineNum = 0;

	for (int y = 0; y < MaxY; y++)
	{
		for (int x = 0; x < MaxX; x++)
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
	
}

void LineContainer::LineCreate()
{

}

void LineContainer::LineMove(int upDown)
{

}