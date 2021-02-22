#include "TetrisContainer.h"

TetrisContainer::TetrisContainer()
{
	tetris = initPointer;
	int(*map)[40][20] = nullptr;
}

TetrisContainer::TetrisContainer(int getMap[40][20])
{
	map = getMap;
	lineCont = new LineContainer();
}

void TetrisContainer::InitTetris()
{
	
}

void TetrisContainer::ShowTetris()
{

}

void TetrisContainer::MoveTetris(int direction)
{

}
void TetrisContainer::MoveDeleteTetris()
{

}
void TetrisContainer::CheckTetris()
{

}
void TetrisContainer::DeleteTetris()
{

}