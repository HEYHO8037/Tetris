#pragma once
#include "Tetris.h"
#include "LineContainer.h"

constexpr auto initPointer = nullptr;
enum Direction { UP, DOWN, LEFT, RIGHT };

class TetrisContainer
{
private:
	int (*map)[20];
	Tetris* tetris;
	LineContainer* lineCont;
	
public:
	TetrisContainer();
	TetrisContainer(int getMap[40][20]);
	void InitTetris();
	void ShowTetris();
	void MoveTetris(int direction);
	void MoveDeleteTetris();
	void CheckTetris();
	void DeleteTetris();
};

