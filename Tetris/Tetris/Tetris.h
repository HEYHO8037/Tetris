#pragma once
#include <random>
#include <iostream>

constexpr int initTetrisX = 8, initTetrisY = 1;
constexpr int tetrisMaxY = 4, tetrisMaxX = 4;

constexpr int maxMember = 7;

constexpr int blockNum = 4;

constexpr int initZero = 0;

constexpr int MaxSetTetrisX = 3;
constexpr int OverSetTetris = 4;

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
	bool isChecked = false;
	int setTetrisY = initZero;
	int setTetrisX = initZero;
public:
	Tetris();
	void ChangePosX(int plusminus);
	void ChangePosY(int plusminus);
	void ChangeisChecked();

	const int getposX();
    int getposY();
	const bool getIsChecked();
	const TetrisType* getTetrisMember();
	const void setTetrisMember(int settingMember);
};

