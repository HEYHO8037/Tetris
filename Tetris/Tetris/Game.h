#pragma once
#include "TetrisContainer.h"
#include "Graphics.h"
#include <time.h>
#include <conio.h>

constexpr int arrowPress = 224;
constexpr int arrowDown = 80;
constexpr int arrowLeft = 75;
constexpr int arrowRight = 77;
constexpr int spaceBar = 32;

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

