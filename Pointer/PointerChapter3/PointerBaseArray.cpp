#include <iostream>


// 배열 매개변수
//void MyFunction(int param[])
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		std::cout << param[i] << std::endl;
//	}
//}

void MyFunction(int* param)
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << *param++ << std::endl;
	}
}

int Sum(int* array, int row_size, int col_size)
{
	int sum = 0;
	for (int i = 0; i < row_size; ++i)
	{
		for (int j = 0; j < col_size; ++j)
		{
			sum += *array++;
		}
	}
	std::cout << sum << std::endl;
	return sum;
}

int Sum2(int (*input)[3], int row_size, int col_size)
{
	int sum = 0;
	for (int i = 0; i < row_size; ++i)
	{
		for (int j = 0; j < col_size; ++j)
		{
			sum += *((*input) + j);
			
		}
		input++;
	}
	std::cout << sum << std::endl;
	return sum;
}

int main()
{
	int array[2][3]
	{
		{1,2,3},
		{4,5,6}
	};
	int array2[3]{ 7,8,9 };
	int array3{ 10 };
	//MyFunction(array);
	Sum(&array[0][0], 2, 3);
	Sum(array2, 1, 3);
	Sum(&array3, 1, 1);

	//Sum2(array,2,3);
}