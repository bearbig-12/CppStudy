#include <iostream>
#include <vector>

int main()
{
	{
		//std::vector<int> v{ 1,2,3 };

		//for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
		//{
		//	std::cout << *itr << std::endl;
		//}

		//std::vector<int>::iterator itr;

		//itr = v.begin();

		//while (itr != v.end())
		//{
		//	std::cout << *itr << std::endl;
		//	itr++;
		//}
	}


	std::vector<int> v2{ 1,2,3,4,5 };

	//range based for
	//대부분의 경우
	for (int& ele : v2) // 값 변경을 위해서는 참조형으로 사용 해야함
	{					// 인덱스를 알 수 없음.
		if (ele == 3)
		{
			ele = 1;
		}
	}
	// index for Loop
	// 인덱스가 필요한 경우
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}


	//STL과 관련된 작업
	int k = 0;
	std::vector<int>::iterator itr;
	for (itr = v2.begin(); itr != v2.end(); ++itr, ++k)
	{
		std::cout << *itr << std::endl;
	}
}