#include <iostream>




// 2차 배열 : 배열을 원소로 가지는 배열
//			  포인터를 원소로 가지는 배열
//			  포인터를 원소로 가지는 배열

int main()
{
	// 배열 - 포인터
	//int arrray1[3]{ 1,2,3, };
	//int* p = arrray1;
	//*p;			// [0]의 주소
	//*(p + 1);	//[1]의 주소

	int array[2][3]
	{
		{1, 2, 3},
		{4, 5, 6}
	};
	//int(*p)[3] = array;
	int* p = &array[0][0];
	

	for (int i = 0; i < 2; ++i)
	{
		std::cout << " { ";
		for (int j = 0; j < 3; ++j)
		{
			//std::cout << *((*(p + i)) + j) << ", ";
			//std::cout << *((*p) + j) << ", ";
			std::cout << *p++ << ", ";

		}
		std::cout << " } ";
		std::cout << std::endl;
		//p++;
	}


	//std::cout << p << std::endl;
	//std::cout << *p << std::endl;
	//std::cout << p + 1 << std::endl;
	//std::cout << *(p + 1) << std::endl;
	//std::cout << *(p + 1) + 2 << std::endl;
	//std::cout << *(*p + 1) << std::endl;




	//for (int i = 0; i < 2; ++i)
	//{
	//	for (int j = 0; j < 3; ++j)
	//	{
	//		std::cout << &array[i][j] << ", ";
	//	}
	//	std::cout << std::endl;
	//}

	int array2[2][3][4];

	int(*p2)[3][4] = array2;

	//int** p = array;		== 2차배열을 찍기 위한 포인터(X)
	// int (*p)[3] == array;	== 2차 배열을 찍기 위한 포인터(O)	배열을 통째로 하나 찍음
}