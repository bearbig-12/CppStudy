#pragma once
#include <iostream>

// 1�� �Ľ�Į �ﰢ��
void PascalTriangle()
{
	int Triangle[5][9]{0};
	Triangle[0][4] = 1;
	for (int row = 1; row < 5; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{

			if (col - 1 < 0)		// row�� 0���� ���� �Ͽ��� ������ ��� x.
			{	
				Triangle[row][col] = Triangle[row - 1][col + 1];
			}
			else if (col + 1 > 8)	// col - 1 Ȥ�� col + 1�� �迭�� ������ ���� ���� ��� �׳� ����ó��.
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