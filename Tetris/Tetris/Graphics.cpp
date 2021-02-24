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
				std::cout << "бр";
			}
			else
			{
				std::cout << "бс";
			}
		}
		std::cout << std::endl;
	}
}