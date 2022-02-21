#pragma once
#include <iostream>

//시작 : 첫 행의 가운데에 1을 기입
//규칙 : 오른쪽 위로 이동(행 감소, 열 증가)
//예외 : 행이 0보다 작으면 마지막 행으로 이동
//열이 너비보다 크면 첫번째 행으로 이동
//이동한 곳에 값이 들어 있으면, 이전 값 바로 아래

void Magic_Square()
{
	int M_square[5][5]{ 0 };

	int size = 5;
	int row = 0;
	int col = size / 2;	// 첫 행의 가운데
	int times = 0; // 반복횟수
	int value = 0;

	

	while (times < size * size)
	{
		if (row < 0)	// 열이 너비보다 크면 첫번째 행으로 이동
		{
			row = size - 1;
		}
		if (col + 1 > size) //  행이 0보다 작으면 마지막 행으로 이동
		{
			col = 0;
		}

		M_square[row][col] = ++value;	// 첫 행의 가운데에 1을 기입 그후 값 올림
		++times;

		if (times % 5 == 0) // //이동한 곳에 값이 들어 있으면, 이전 값 바로 아래. 5번 반복시 다음 반복 자리에 값이 들어 있으므로 5번 반복 후 이전 값 바로 아래.
		{
			++row;
		}
		else
		{
			--row;
			++col;
		}
		
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (M_square[i][j] < 10)
			{
				std::cout << " [ " << M_square[i][j] << "] ";
			}
			else
			{
				std::cout << " [" << M_square[i][j] << "] ";

			}
		}
		std::cout << std::endl;
	}

}