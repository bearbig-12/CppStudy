#include <iostream>

//	Template
//	
//		Ÿ���� �Ϲ�ȭ(generalization) ���� ����
//		���α׷��Ӱ� ���ϴ� Ÿ������ Ư��ȭ(specialization)���Ѽ� ���
//		�����Ϸ��� �ڵ����� ���� ( ������ Ÿ�ӿ� ���� )

//	�Ϲ�ȭ
//
//		template<�Ϲ�ȭŸ�� �̸� 1, �Ϲ�ȭŸ�� �̸� 2>
//		
//		template <typename T1, typename T2>
//		template <class T1, class T2>

//		template<typename T>
//		void Dosomething(T x)
//		{
//
//		}

//	Ư��ȭ
//		
//		����ϰ����ϴ� Ÿ���� <Ÿ��> �ȿ� �߰�
//		Dosomething<int>(1);

using namespace std;

// Ÿ���� Ŭ������ ���� teplate<class T1, class T2>

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