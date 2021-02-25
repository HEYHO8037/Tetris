#pragma once
#include <random>
#include <iostream>

constexpr int initX = 8, initY = 1;
constexpr int maxY = 4, maxX = 4;
constexpr int maxMember = 7;
constexpr int blockNum = 4;
typedef int TetrisType[4][4];

enum PlusMinus
{
	PLUS,
	MINUS
};

class Tetris
{
private:
	int tetrisMember[maxMember][blockNum][blockNum] =
	{
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,1,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
	};
	int tetrisSelectMember[blockNum][blockNum] = { 0 };
	int randNum;
	int posX;
	int posY;
	bool isChecked;
public:
	Tetris();
	void ChangePosX(int plusminus);
	void ChangePosY(int plusminus);
	void ChangeisChecked();

	const int getposX();
    const int getposY();
	const bool getIsChecked();
	const TetrisType* getTetrisMember();
};

