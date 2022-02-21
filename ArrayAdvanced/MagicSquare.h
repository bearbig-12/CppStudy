#pragma once
#include <iostream>

//���� : ù ���� ����� 1�� ����
//��Ģ : ������ ���� �̵�(�� ����, �� ����)
//���� : ���� 0���� ������ ������ ������ �̵�
//���� �ʺ񺸴� ũ�� ù��° ������ �̵�
//�̵��� ���� ���� ��� ������, ���� �� �ٷ� �Ʒ�

void Magic_Square()
{
	int M_square[5][5]{ 0 };

	int size = 5;
	int row = 0;
	int col = size / 2;	// ù ���� ���
	int times = 0; // �ݺ�Ƚ��
	int value = 0;

	

	while (times < size * size)
	{
		if (row < 0)	// ���� �ʺ񺸴� ũ�� ù��° ������ �̵�
		{
			row = size - 1;
		}
		if (col + 1 > size) //  ���� 0���� ������ ������ ������ �̵�
		{
			col = 0;
		}

		M_square[row][col] = ++value;	// ù ���� ����� 1�� ���� ���� �� �ø�
		++times;

		if (times % 5 == 0) // //�̵��� ���� ���� ��� ������, ���� �� �ٷ� �Ʒ�. 5�� �ݺ��� ���� �ݺ� �ڸ��� ���� ��� �����Ƿ� 5�� �ݺ� �� ���� �� �ٷ� �Ʒ�.
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