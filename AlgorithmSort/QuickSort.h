#pragma once
#include <iostream>

void Swap(int& value1, int& value2);

void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;

	int pivot = input[(left + right) / 2];
	
	//do while - ������ �ڿ� �ɱ� ������ ������ �ѹ��� ����
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
	if (left < j)	// j == left�� ��� �ڸ����� ���� ����̹Ƿ�, �̰�� base case�� recursive���̽��� ���� ������ �������.
	{
		QuickSort(input, left, j);
	}
	if (i < right)
	{
		QuickSort(input, i, right);

	}
}