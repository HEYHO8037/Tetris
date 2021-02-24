#pragma once
#include "Tetris.h"
#include "LineContainer.h"

constexpr int MaxMapY = 40;
constexpr int MaxMapX = 20;
enum dir
{ 
	dirUp,
	dirDown,
	dirLeft,
	dirRight
};

class TetrisContainer
{
private:
	int (*map)[MaxMapX];
	int (*tetrisMember)[4];
	Tetris* tetris;
	LineContainer* lineCont;
	
public:
	TetrisContainer();
	TetrisContainer(int getMap[MaxMapY][MaxMapX]);
	void InitTetris();
	void ShowTetris();
	void MoveTetris(int direction);
	void MoveDeleteTetris();
	void CheckTetris();
	void DeleteTetris();
};

