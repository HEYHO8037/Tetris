#pragma once


constexpr auto initPointer = nullptr;
enum Direction { UP, DOWN };

class LineContainer
{
private:
	int (*map)[20];
public:
	LineContainer();
	LineContainer(int getMap[40][20]);
	void LineCheck();
	void LineDelete();
	void LineCreate();
	void LineMove(int upDown);
};

