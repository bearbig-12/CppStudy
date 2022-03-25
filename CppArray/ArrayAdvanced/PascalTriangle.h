#pragma once
#include <iostream>

// 1번 파스칼 삼각형
void PascalTriangle()
{
	int Triangle[5][9]{0};
	Triangle[0][4] = 1;
	for (int row = 1; row < 5; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{

			if (col - 1 < 0)		// row의 0번은 제외 하였기 때문에 고려 x.
			{	
				Triangle[row][col] = Triangle[row - 1][col + 1];
			}
			else if (col + 1 > 8)	// col - 1 혹은 col + 1이 배열의 범위를 벗어 났을 경우 그냥 예외처리.
			{
				Triangle[row][col] = Triangle[row - 1][col - 1];
			}
			else
			{
				Triangle[row][col] = Triangle[row - 1][col - 1] + Triangle[row - 1][col + 1];
			}
		}
	}

	for (int row = 0; row < 5; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			if (Triangle[row][col] == 0)
			{
				std::cout << "   ";
			}
			else
			{
				std::cout << "[" << Triangle[row][col] << "]";
			}
			
		}
		std::cout << std::endl;
	}
}