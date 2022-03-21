#include <iostream>
#include "SequentialSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include"InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

void PrintArray(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
}

int main()
{
	const int SIZE{ 5 };
	int array[SIZE]{ 8,7,2,3,1 };

	//SORT
	//SequentialSort(array, SIZE);
	//SelectionSort(array, SIZE);
	//BubbleSort(array, SIZE);
	//InsertionSort(array, SIZE);
	//MergeSort(array,0, SIZE-1);
	QuickSort(array, 0, SIZE - 1);
	PrintArray(array, SIZE);
}