#pragma once
#include <random>
#include <ctime>

constexpr auto initPointer = nullptr;

constexpr int reset = 0;

constexpr int maxDelLine = 4;

constexpr int lastLineY = 38;
constexpr int firstLineY = 1;

constexpr int saveNum = 2;

constexpr int edgeMapY = 40;
constexpr int edgeMapX = 19;
constexpr int firstMapX = 1;

constexpr int first = 0;
constexpr int second = 1;

constexpr int maxRandom = 18;
constexpr int plusMinimum = 1;

constexpr int zero = 0;

enum Direction 
{ 
	UP,
	DOWN
};

class LineContainer
{
private:
	int (*map)[20];
	bool isLineChecked = true;
	int saveLineY[maxDelLine];
	int savefrontLine[saveNum][edgeMapX];
	int lineNum;
public:
	LineContainer();
	LineContainer(int getMap[40][20]);

	void LineCheck();
	void LineDelete();
	void LineCreate();
	void LineMove();
};

