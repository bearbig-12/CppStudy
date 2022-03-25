#include <iostream>


int main()
{
	{
		//2d array & pointer
		int array[2][3];
		int(*p)[3] = array;

		//pointer to pointer
		int number{ 5 };
		int* p2{ &number };

		//p2 : 주소
		//*p2 : 5

		int** p3{ &p2 };
		//p3
		//*p3
		//**p3;
		{
			int(*pArray)[3] = new int[2][3];

		}
	}
	

	//2차원 배열 동적할당
	int** pArray = new int* [2];

	for (int i = 0; i < 2; ++i)
	{
		pArray[i] = new int[3];
	}

	for (int i = 0; i < 2; ++i)
	{
		delete[] pArray[i];
		pArray[i] = nullptr;
	}

	delete[] pArray;
	pArray = nullptr;
}