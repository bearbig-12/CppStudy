#pragma once
void Swap(int& value1, int& value2);

void Merge(int input[], int start, int half, int end);


void MergeSort(int input[], int start, int end)
{
	//base case
	if (start >= end)
	{
		return;
	}

	//recursive
	//const int new_end = end - 1;
	int half = (start + end) / 2;
	MergeSort(input, start, half);
	MergeSort(input, half+1, end);

	Merge(input, start, half, end);
}

void Merge(int input[], int start, int half, int end)
{
	//왼쪽 블럭과 오른쪽 블럭을 정렬 & 병합
	int left_start = start;
	int right_start = half + 1;

	//temp
	int* temp = new int[end+1] {};
	int tempIndex = 0;

	while (left_start <= half && right_start <= end)
	{
		if (input[left_start] < input[right_start])
		{
			temp[tempIndex++] = input[left_start++];
		}
		else
		{
			temp[tempIndex++] = input[right_start++];

		}
	}

	//남은거 병합
	while (left_start <= half)
	{
		temp[tempIndex++] = input[left_start++];
	}
	while (right_start <= end)
	{
		temp[tempIndex++] = input[right_start++];

	}

	tempIndex = 0;
	//사용한건 동적할당으로 계속해서 temp라는 배열을 새로 만들어 준것이다. 따라서 temp에는 항상 0번째 인덱스부터 우리가 
	//input에 넣고자 하는 값이 들어 있다 그러므로 동적할당으로 temp를 만들경우 input의 인덱스를 따로 생각하여야 한다.
	for (int i = start; i <= end; ++i)
	{
		input[i] = temp[tempIndex++];
	}
	for (int i = start; i <= end; ++i)
	{
		std::cout << input[i] << std::endl;
	}
	delete[] temp;
}