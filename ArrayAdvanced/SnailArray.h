#pragma once
#include <iostream>

// 달팽이 배열
void Snail_Array()
{
	int snail_arr[5][5]{ 0 };
	int value = 1;
	int sign = 1;	// 방향을 정하기 위한 부호
	int size = 5;

	int x = 0;
	int y = -1;		// 가장 먼저 {0,0}에서 시작 하여야 하기 때문에 -1을 줌
	while (size > 0)
	{
		for (int i = 0; i < size; ++i)	// row 고정 column 변화
		{
			y = y + sign;
			snail_arr[x][y] = value++;
		}
		--size;
		for (int i = 0; i < size; ++i)	// 반대
		{
			x = x + sign;
			snail_arr[x][y] = value++;
		}
		sign = sign * (-1);
	}




	for (int row = 0; row < 5; ++row)		//출력
	{
		for (int col = 0; col < 5; ++col)
		{
			
			if (row == 0)
			{
				if (col == 4)
				{
					std::cout << snail_arr[row][col];

				}
				else
				{
					std::cout << " " << snail_arr[row][col] << "  ";

				}
				
			}
			else
			{
				std::cout << snail_arr[row][col] << "  ";

			}
		}
		std::cout << std::endl;
	}
}