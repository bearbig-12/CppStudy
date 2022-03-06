#include <iostream>
#include "FunctionPointerEX.h"
// 주소 연산자 &  :  우측 변수의 주소를 반환한다.	ex) &v <- 0ㅌ00000110
// 포인터 연산자 * : 우측 변수가 주소를 가르키는 포인터 변수라는 것을 명시한다. ex) int* p;

//	int* p; 정수형 포인터 p의 선언
//	p = &b; 포인터의 값에 b의 주소 배정 -  "p는 b를 참조(reference)
//	*p = 3;	p가 가르키고 있는 곳의 값에 값을 배정 - p의 역참조(dereference)

//	포인터의 연산은 타입의 크기(int면 4byte)만큼 이동하게 된다.

//	아무것도 가르키지 않는 포인터는 널 포인터라고 부른다 ex) int* p {nullptr};

//	void pointer는 타입이 없다. 타입이 없기 때문에 역참조도 불가능 하지만 누구나 가르킬 수 있다.

//		-구조체의 포인터-

//			struct Status
//			{
//				int HP,
//				int MP
//			};
//		
//			Status myStuats{100,10};
//			Status *pStatus = &myStatus;

//			구조체의 멤버에 접근 하기위해서
//			(*pStatus).HP;
//			Or
//			pStatus->HP;

//		-Const 와 포인터-
//			
//			const int* p; - 상수형 정수를 가르키는 포인터. 상수형 정수를 가르키기 때문에 역참조를 할 수 없다.
//			int* const p; - int*가 상수라는 의미, 상수 포인터. 역참조는 가능하지만 가르키는 대상을 변경할 수 없다.
//			const int* const p;	- 상수형 정수를 가르키는 상수 포인터. 역참조 불가, 가르키는 대상변경 불가.

//		-참조형 (Call by Reference)-
//
//			선언과 동시에 반드시 초기화 해야함.
//			초기화 이후에는 다른 변수 참조 불가능.
//			int a = 5;
//			int& ref = a;
//			ref = 3;			ref는 a를 가르키고 있기 때문에 a의 값이 3으로 변경
//
//			const int& ref = 10 + 20;
//				-> int* p = 10; - 주소가 없는 리터럴이라서 불가능함 (R value)
//				-> 하지만 위와 같은 경우는 값(표현식)을 참조하는 형태 즉 우측값 참조( R - value Reference)라고 부르는 기법이기에 가능.
// 
// 
//		-함수 포인터-
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
//		함수와 변수는 비슷하게 메모리에 올라가서 주소를 찍을 수 있다. 다만 함수는 변수와 달리 분리되어 관리 된다.
//
// 
//		배열은 배열의 첫번째 원소를 가르키고 있는 포인터이다
//		int array[10];
//		
//		std::cout << array << std::endl;
//		std::cout << array[0] << std::endl;	 위와 아래의 주소는 같다.


int NormalFunction(int x)
{
	return x;
}

//int f(int*)	// 이 식은 int 포인터를 매개변수로 받는 함수 라는 의미가 된다.
//int* f(int)	// f라는 함수가 int*를 반환하게 되는 함수가 된다.
//int (*f)(int)	// 함수 포인터.

//int Sigma(int f(int),int m, int n) // 이와같이 함수를 매개변수로 넘겨 줄수있다.
int Sigma(int (*f)(int),int m, int n)	// 이와같이 함수 포인터를 매개변수로 넘겨 줄수있다.
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
	//int (*p)(int); // 함수 포인터 변수
	FunctionPointer p;	// typedef을 사용해서 별명을 붙여서 사용

	p = NormalFunction;

	(*p)(15);	// 함수 포인터 p를 역참조 할경우 함수(NormalFunction)를 부를 수 있다.
	p(15);		// C++ 에서는 (*p)(15)를 쓰지 않고 앞의 식과 같이 암시적 형변환을 해준다.

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
//	//std::cout << pStatus->HP << std::endl; // 구조체 포인터에서 사용하는 화살표연산자.
//
//
//}