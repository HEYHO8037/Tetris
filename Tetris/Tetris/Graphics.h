#pragma once
#include <Windows.h>

class Graphics
{
private:
	int tetrisMap[40][20];
	static HANDLE hBuffer[2];
	int screenIndex;
	int* score;

public:
	Graphics();

	
};

