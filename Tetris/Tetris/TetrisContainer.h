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

enum block
{
	nonexist,
	exist
};

class TetrisContainer
{
private:
	int (*map)[MaxMapX];
	int height;
	int width;
	int calculateTetris;
	const int(*saveTetris)[4];
	int saveX[4];
	int saveY[4];
	bool deleteTetris = true;

	Tetris* tetris;
	LineContainer* lineCont;
	
public:
	TetrisContainer();
	TetrisContainer(int getMap[MaxMapY][MaxMapX]);
	void InitTetris();
	void ShowTetris();
	void MoveTetris(int xORy, int direction);
	void MoveDeleteTetris();
	void CheckTetris();
	void CheckisChecked();
	void DeleteTetris();
	
};

