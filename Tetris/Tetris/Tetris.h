#pragma once
#include <random>
#include <iostream>

constexpr int initX, initY = 0;
constexpr int maxY, maxX = 4;
constexpr int maxMember = 7;

class Tetris
{
protected:
	int tetrisMember[7][4][4] = 
	{
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0},
			{0,0,0,0}
		},
	};
	int tetrisSelectMember[4][4] = { 0 };
	int randNum;
	int posX;
	int posY;
	bool isChecked;
public:
	Tetris();
};

