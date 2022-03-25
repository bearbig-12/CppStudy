#pragma once
#include <iostream>

// ������ �迭
void Snail_Array()
{
	int snail_arr[5][5]{ 0 };
	int value = 1;
	int sign = 1;	// ������ ���ϱ� ���� ��ȣ
	int size = 5;

	int x = 0;
	int y = -1;		// ���� ���� {0,0}���� ���� �Ͽ��� �ϱ� ������ -1�� ��
	while (size > 0)
	{
		for (int i = 0; i < size; ++i)	// row ���� column ��ȭ
		{
			y = y + sign;
			snail_arr[x][y] = value++;
		}
		--size;
		for (int i = 0; i < size; ++i)	// �ݴ�
		{
			x = x + sign;
			snail_arr[x][y] = value++;
		}
		sign = sign * (-1);
	}




	for (int row = 0; row < 5; ++row)		//���
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