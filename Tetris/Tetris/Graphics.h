#pragma once
#include <Windows.h>
#include <iostream>

constexpr int mapMaxY = 40;
constexpr int mapMaxX = 20;

constexpr int MaxBuffer = 2;
constexpr int nonExist = 0;

enum GuidLine
{
	UpLine, LeftLine = 0,
	DownLine = 39,
	RightLine = 19
};


class Graphics
{
private:
	HANDLE hBuffer[MaxBuffer] = { 0 };
	int screenIndex = 0;
	int* score = nullptr;

public:
	int tetrisMap[mapMaxY][mapMaxX];

	Graphics();
	void InitMap(int getScore);
	void UpdateMap();
	void DeleteMap();

	void StartUI();
	void GameOverUI();

	void CreateBuffer();
	void WriteBuffer(int x, int y, const char *str);
	void FlippingBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};

