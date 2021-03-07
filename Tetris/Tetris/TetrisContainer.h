#pragma once
#include "Tetris.h"
#include "LineContainer.h"

constexpr int MaxSaveNum = 4;
constexpr int One = 1;
constexpr int noInside = -1;
constexpr int MaxBlockNum = 3;

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

enum Rotate
{
	rotate,
	reRotate
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

	int saveCrashX[MaxSaveNum];
	int saveCrashY[MaxSaveNum];

	bool deleteTetris = true;
	bool isTetrisStop;

	bool crashTetrisX = false;
	bool crashTetrisY = false;
	bool crashTetrisRotate = false;

	int saveRotateTetris[tetrisMaxY][tetrisMaxX];

	Tetris* tetris;
	LineContainer* lineCont;
	
public:
	TetrisContainer();
	TetrisContainer(int getMap[mapY][mapX]);

	void InitTetris();
	void ShowTetris();

	void MoveTetris(int xORy, int direction);
	void MoveDeleteTetris();

	void RotateTetris(int direction);
	void CheckAndRotateTetris();

	void CheckTetrisLR(int direction);
	void CheckTetrisDown();
	void CheckRotateTetris();

	void LineProcess();

	void DeleteTetris();
	void DeleteLineContainer();

	
};

