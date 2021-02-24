#pragma once
#include <Windows.h>
#include <iostream>

constexpr int MaxY = 40;
constexpr int MaxX = 20;
constexpr int MaxBuffer = 2;

enum GuidLine
{
	UpLine, LeftLine = 0,
	DownLine = 39,
	RightLine = 19
};


class Graphics
{
private:
	static HANDLE hBuffer[MaxBuffer];
	int screenIndex;
	int* score;

public:
	int tetrisMap[MaxY][MaxX];

	Graphics();
	void InitMap(int getScore);
	void UpdateMap();
	void DeleteMap();

	void StartUI();
	void GameOverUI();

	void CreateBuffer();
	void WriteBuffer();
	void FlippingBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};

