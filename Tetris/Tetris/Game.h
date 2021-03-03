#pragma once
#include "TetrisContainer.h"
#include "Graphics.h"
#include <time.h>

class Game
{
private:
	bool isGameStart;
	int score;
	TetrisContainer* tetrisCont;
	Graphics* graphics;
	int keyNum;

public:
	void Init();
	void Update();
	void Release();
};

