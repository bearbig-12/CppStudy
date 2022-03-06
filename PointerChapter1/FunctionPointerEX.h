#pragma once
#include <iostream>
const int NumArray{ 5 };

using Comparison = bool (*)(int, int);	// �Լ� ������.

// Comparison Function
bool Asscending(int x, int y)	// ��������
{
	return x > y;
}
bool Descending(int x, int y)	// ��������
{
	return x < y;
}

void Sort(int scores[NumArray], Comparison f)
{
	for (int i = 0; i < NumArray; ++i)
	{
		for (int j = i + 1; j < NumArray; ++j)
		{
			// if(scores[i] < scores[j])
			if (f(scores[i], scores[j]))
			{
				int temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;
			}
		}
	}
}