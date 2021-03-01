#pragma once

constexpr auto initPointer = nullptr;
constexpr int MaxY = 40;
constexpr int MaxX = 20;

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
	int saveLineY[4];
public:
	LineContainer();
	LineContainer(int getMap[40][20]);
	void LineCheck();
	void LineDelete();
	void LineCreate();
	void LineMove(int upDown);
};

