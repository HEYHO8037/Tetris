#include "LineContainer.h"

LineContainer::LineContainer()
{
	map = initPointer;
}

LineContainer::LineContainer(int getMap[40][20])
{
	map = getMap;
}