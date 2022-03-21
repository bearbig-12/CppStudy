#pragma once
#include <iostream>

void Swap(int& value1, int& value2);

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;

	int pivot = input[(left + right) / 2];
	
	//do while - 조건을 뒤에 걸기 때문에 무조건 한번은 실행
	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);

	//recursive
	if (left < j)	// j == left일 경우 자를수가 없는 경우이므로, 이경우 base case와 recursive케이스를 같이 설정한 응용버젼.
	{
		QuickSort(input, left, j);
	}
	if (i < right)
	{
		QuickSort(input, i, right);

	}
}