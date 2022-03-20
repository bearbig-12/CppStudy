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
	//���� ���� ������ ���� ���� & ����
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

	//������ ����
	while (left_start <= half)
	{
		temp[tempIndex++] = input[left_start++];
	}
	while (right_start <= end)
	{
		temp[tempIndex++] = input[right_start++];

	}

	tempIndex = 0;
	//����Ѱ� �����Ҵ����� ����ؼ� temp��� �迭�� ���� ����� �ذ��̴�. ���� temp���� �׻� 0��° �ε������� �츮�� 
	//input�� �ְ��� �ϴ� ���� ��� �ִ� �׷��Ƿ� �����Ҵ����� temp�� ������ input�� �ε����� ���� �����Ͽ��� �Ѵ�.
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