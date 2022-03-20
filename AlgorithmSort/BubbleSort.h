#pragma once
#include <iostream>

void Swap(int& value1, int& value2);

//O(n^2) , O(n)
void BubbleSort(int input[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - (i+1); ++j)
		{
			if (input[j] > input[j + 1])
			{
				Swap(input[j + 1], input[j]);
			}
		}
	}
}
