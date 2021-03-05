#pragma once
#include "Tetris.h"
#include "LineContainer.h"

constexpr int MaxSaveNum = 4;
constexpr int One = 1;
constexpr int noInside = -1;

constexpr int mapX = 20;
constexpr int mapY = 40;

enum dir
{ 
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
	int (*map)[mapX];
	int height;
	int width;
	int calculateTetris;
	const int(*saveTetris)[MaxSaveNum];
	int saveX[MaxSaveNum];
	int saveY[MaxSaveNum];
	bool deleteTetris = true;
	bool isTetrisStop;
	bool crashTetris = false;

	int saveRotateTetris[tetrisMaxY][tetrisMaxX];

	Tetris* tetris;
	LineContainer* lineCont;
	
public:
	TetrisContainer();
	TetrisContainer(int getMap[mapY][mapX]);
	void InitTetris();
	void ShowTetris();
	void MoveTetris(int xORy, int direction);
	void RotateTetris();
	void MoveDeleteTetris();
	void CheckTetris();
	void LineProcess();
	void DeleteTetris();
	
};

