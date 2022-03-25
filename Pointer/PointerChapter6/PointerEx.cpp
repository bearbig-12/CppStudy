#include <iostream>

int main()
{
	int* pnew{};
	{
		

		pnew = new int;
		*pnew = 10;

		delete pnew;

	}

//----------------------------------

	{
		pnew = new int[10];
		*pnew = 10;
		std::cout << *pnew << std::endl;
		pnew[0] = 20;
		std::cout << *pnew << std::endl;

		delete[] pnew;
	}


//----------------------------------
	struct student
	{
		int number;
		int age;
	};

	{
		student* student1 = new student;

		student1->age = 20;
		student1->number = 1;

		delete student1;
	}



//----------------------------------
	{
		student* student_arr = new student[10];

		student_arr[0].age = 30;
		student_arr[0].number = 2;

		delete[] student_arr;
	}
//---------------------------------------------------
	{
		int inputSize{};
		std::cout << "배열의 크기 : ";
		std::cin >> inputSize;

		if (inputSize <= 0)
		{
			std::cout << "Impossible" << std::endl;
			return 0;
		}

		int* pArray = new int[inputSize] {};

		if (pArray)
		{
			for (int i = 0; i < inputSize; ++i)
			{
				//pArray[i] = 0;
				std::cout << pArray[i] << std::endl;
			}

		}
		delete[] pArray;
		pArray = nullptr;
	}
 }

