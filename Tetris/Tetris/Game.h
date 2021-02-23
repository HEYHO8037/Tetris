#pragma once
#include "TetrisContainer.h"
#include "Graphics.h"

class Game
{
private:
	bool isGameStart;
	TetrisContainer* tetrisCont;
	Graphics* graphics;
	int keyNum;

public:
	void Init();
	void Update();
	void Release();
};

