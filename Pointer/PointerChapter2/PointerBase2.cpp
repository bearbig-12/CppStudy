#include <iostream>




// 2�� �迭 : �迭�� ���ҷ� ������ �迭
//			  �����͸� ���ҷ� ������ �迭
//			  �����͸� ���ҷ� ������ �迭

int main()
{
	// �迭 - ������
	//int arrray1[3]{ 1,2,3, };
	//int* p = arrray1;
	//*p;			// [0]�� �ּ�
	//*(p + 1);	//[1]�� �ּ�

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

	//int** p = array;		== 2���迭�� ��� ���� ������(X)
	// int (*p)[3] == array;	== 2�� �迭�� ��� ���� ������(O)	�迭�� ��°�� �ϳ� ����
}