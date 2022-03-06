#include <iostream>
#include "FunctionPointerEX.h"
// �ּ� ������ &  :  ���� ������ �ּҸ� ��ȯ�Ѵ�.	ex) &v <- 0��00000110
// ������ ������ * : ���� ������ �ּҸ� ����Ű�� ������ ������� ���� ����Ѵ�. ex) int* p;

//	int* p; ������ ������ p�� ����
//	p = &b; �������� ���� b�� �ּ� ���� -  "p�� b�� ����(reference)
//	*p = 3;	p�� ����Ű�� �ִ� ���� ���� ���� ���� - p�� ������(dereference)

//	�������� ������ Ÿ���� ũ��(int�� 4byte)��ŭ �̵��ϰ� �ȴ�.

//	�ƹ��͵� ����Ű�� �ʴ� �����ʹ� �� �����Ͷ�� �θ��� ex) int* p {nullptr};

//	void pointer�� Ÿ���� ����. Ÿ���� ���� ������ �������� �Ұ��� ������ ������ ����ų �� �ִ�.

//		-����ü�� ������-

//			struct Status
//			{
//				int HP,
//				int MP
//			};
//		
//			Status myStuats{100,10};
//			Status *pStatus = &myStatus;

//			����ü�� ����� ���� �ϱ����ؼ�
//			(*pStatus).HP;
//			Or
//			pStatus->HP;

//		-Const �� ������-
//			
//			const int* p; - ����� ������ ����Ű�� ������. ����� ������ ����Ű�� ������ �������� �� �� ����.
//			int* const p; - int*�� ������ �ǹ�, ��� ������. �������� ���������� ����Ű�� ����� ������ �� ����.
//			const int* const p;	- ����� ������ ����Ű�� ��� ������. ������ �Ұ�, ����Ű�� ��󺯰� �Ұ�.

//		-������ (Call by Reference)-
//
//			����� ���ÿ� �ݵ�� �ʱ�ȭ �ؾ���.
//			�ʱ�ȭ ���Ŀ��� �ٸ� ���� ���� �Ұ���.
//			int a = 5;
//			int& ref = a;
//			ref = 3;			ref�� a�� ����Ű�� �ֱ� ������ a�� ���� 3���� ����
//
//			const int& ref = 10 + 20;
//				-> int* p = 10; - �ּҰ� ���� ���ͷ��̶� �Ұ����� (R value)
//				-> ������ ���� ���� ���� ��(ǥ����)�� �����ϴ� ���� �� ������ ����( R - value Reference)��� �θ��� ����̱⿡ ����.
// 
// 
//		-�Լ� ������-
// 
//		int Sum(int x, int y)
//		{
//			return x + y;
//		}
// 
//		int main()
//		{
//			int x{ 1 }, y{ 2 }
//			
//			std::cout << &x << ", " << &y << std::endl;
//			std::cout << Sum << ", " << main << std::endl;
//			std::cout << &Sum << ", " << &main << std::endl;
//		}
//		�Լ��� ������ ����ϰ� �޸𸮿� �ö󰡼� �ּҸ� ���� �� �ִ�. �ٸ� �Լ��� ������ �޸� �и��Ǿ� ���� �ȴ�.
//
// 
//		�迭�� �迭�� ù��° ���Ҹ� ����Ű�� �ִ� �������̴�
//		int array[10];
//		
//		std::cout << array << std::endl;
//		std::cout << array[0] << std::endl;	 ���� �Ʒ��� �ּҴ� ����.


int NormalFunction(int x)
{
	return x;
}

//int f(int*)	// �� ���� int �����͸� �Ű������� �޴� �Լ� ��� �ǹ̰� �ȴ�.
//int* f(int)	// f��� �Լ��� int*�� ��ȯ�ϰ� �Ǵ� �Լ��� �ȴ�.
//int (*f)(int)	// �Լ� ������.

//int Sigma(int f(int),int m, int n) // �̿Ͱ��� �Լ��� �Ű������� �Ѱ� �ټ��ִ�.
int Sigma(int (*f)(int),int m, int n)	// �̿Ͱ��� �Լ� �����͸� �Ű������� �Ѱ� �ټ��ִ�.
{
	int sum = 0;
	for (int k = m; k <= n; ++k)
	{
		//sum += f(k);
		sum += f(k);		
	}
	return sum;
}

void Swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}
// c style
typedef int (*FunctionPointer)(int);
// c++ style
using FunctionPointer = int (*)(int);



int main()
{
	//int (*p)(int); // �Լ� ������ ����
	FunctionPointer p;	// typedef�� ����ؼ� ������ �ٿ��� ���

	p = NormalFunction;

	(*p)(15);	// �Լ� ������ p�� ������ �Ұ�� �Լ�(NormalFunction)�� �θ� �� �ִ�.
	p(15);		// C++ ������ (*p)(15)�� ���� �ʰ� ���� �İ� ���� �Ͻ��� ����ȯ�� ���ش�.

	std::cout << "NormalFunction : " << &NormalFunction << std::endl;
	std::cout << Sigma(NormalFunction, 1, 10) << std::endl;

	
	int scores[NumArray]{ 20,10,15,40,30 };
	Sort(scores, Asscending);

	std::cout << "Sort" << std::endl;
	for (int i = 0; i < NumArray; ++i)
	{
		std::cout << scores[i] << std::endl;
	}
}

//int main()
//{
//	//int x{1};
//	//int* p;
//	//p = &x;
//
//	//int** pp;
//	//pp = &p;
//	//
//	//std::cout << &x << std::endl;
//	//std::cout << p << std::endl;
//	//std::cout << *p << std::endl;
//	//std::cout << pp << std::endl;
//	//std::cout << *pp << std::endl;
//	//std::cout << **pp << std::endl;
//
//	//struct Status
//	//{
//	//	int HP;
//	//	int MP;
//	//};
//
//	//Status myStatus{ 100,10 };
//	//
//	//Status* pStatus;
//	//pStatus = &myStatus;
//
//	//std::cout << myStatus.HP << std::endl;
//
//	//std::cout << (*pStatus).HP << std::endl;
//	//std::cout << pStatus->HP << std::endl; // ����ü �����Ϳ��� ����ϴ� ȭ��ǥ������.
//
//
//}