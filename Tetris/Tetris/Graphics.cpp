#include "Graphics.h"

Graphics::Graphics()
{

}void Graphics::InitMap(int getScore)
{
	score = &getScore;

	for (int height = 0; height < MaxY; height++)
	{
		for (int length = 0; length < MaxX; length++)
		{
			if (height == UpLine || height == DownLine)
			{
				tetrisMap[height][length] = 1;
			}
			else if (length == LeftLine || length == RightLine)
			{
				tetrisMap[height][length] = 1;
			}
			else
			{
				tetrisMap[height][length] = 0;
			}
		}
	}
}

void Graphics::UpdateMap()
{
	for (int height = 0; height < MaxY; height++)
	{
		for (int length = 0; length < MaxX; length++)
		{
			if (tetrisMap[height][length] == 0)
			{
				WriteBuffer(length, height, "бр");
			}
			else
			{
				WriteBuffer(length, height, "бс");
			}
		}
		std::cout << std::endl;
	}
}

void Graphics::DeleteMap()
{
	for (int y = 0; y < MaxY; y++)
	{
		for (int x = 0; x < MaxX; x++)
		{
			tetrisMap[y][x] = 0;
		}
	}
}

void Graphics::StartUI()
{


}

void Graphics::GameOverUI()
{

}

void Graphics::CreateBuffer()
{
	COORD size = { 20, 50 };
	CONSOLE_CURSOR_INFO cci;
	SMALL_RECT rect;
	rect.Bottom = 0;
	rect.Left = 0;
	rect.Right = 19;
	rect.Top = 49;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);

}

void Graphics::WriteBuffer(int x, int y, const char str[])
{
	DWORD dw;
	COORD CursorPosition = { x , y };
	SetConsoleCursorPosition(hBuffer[screenIndex], CursorPosition);
	WriteFile(hBuffer[screenIndex], str, strlen(str), &dw, NULL);
}

void Graphics::FlippingBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[screenIndex]);
	if (screenIndex == 0)
	{
		screenIndex = 1;
	}
	else if (screenIndex == 1)
	{
		screenIndex = 0;
	}
}

void Graphics::ClearBuffer()
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[screenIndex], ' ', 10000, Coor, &dw);
}

void Graphics::DeleteBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
