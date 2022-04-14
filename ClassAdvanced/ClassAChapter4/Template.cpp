#include <iostream>

//	Template
//	
//		타입을 일반화(generalization) 시켜 선언
//		프로그래머가 원하는 타입으로 특수화(specialization)시켜서 사용
//		컴파일러가 자동으로 해줌 ( 컴파일 타임에 생성 )

//	일반화
//
//		template<일반화타입 이름 1, 일반화타입 이름 2>
//		
//		template <typename T1, typename T2>
//		template <class T1, class T2>

//		template<typename T>
//		void Dosomething(T x)
//		{
//
//		}

//	특수화
//		
//		사용하고자하는 타입을 <타입> 안에 추가
//		Dosomething<int>(1);

using namespace std;

// 타입이 클래스인 경우는 teplate<class T1, class T2>

//template <typename T>
//T Function(T arg1, T arg2)
//{
//	T result = arg1 + arg2;
//}
//
//int main()
//{
//	int x{ 1 }, y{ 2 };
//	Function<int>(x, y);
//	Function<float>(1.0f, 2.0f);
//}

template <typename T>
void Sort(T input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				T temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}

int main()
{
	int array[]{ 5,3,2,4,1 };

	Sort<int>(array, 5);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}