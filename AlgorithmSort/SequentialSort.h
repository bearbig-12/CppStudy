#pragma once
#include <iostream>

void Swap(int& value1, int& value2);

//O(n^2) , O(n)
void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

