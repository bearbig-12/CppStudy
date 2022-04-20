#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>
#include <deque>
int main()
{
	
	//	Array
	{

		//std::array<int, 4> mcontainer{ 0, 1, 2, 3 };

		//for (auto itr = mcontainer.begin(); itr != mcontainer.end(); ++itr)
		//{
		//	std::cout << *itr << std::endl;
		//}


	}
	
	// Vector
	{

			
		//std::vector<int> mContainer{ 0,1,2,3,4,5 };


		//mContainer.push_back(6);
		//mContainer.pop_back();
		//mContainer.erase(mContainer.begin() + 1);
		//mContainer.resize(10, 100);

		//for (int e : mContainer)
		//{
		//	std::cout << e << std::endl;
		//}
	}

	//Forward_list
	{
		//std::forward_list<int> mContainer{ 10,11,20,21, 5, 32, 9 };
		//auto itr = std::find(mContainer.begin(), mContainer.end(), 11);
		//mContainer.insert_after(itr, 12);
		//mContainer.erase_after(itr);
		///*mContainer.sort([](const auto& arg1, const auto& arg2)
		//	{
		//		return arg1 < arg2;
		//	}
		//);*/
		//mContainer.sort(std::less<int>());

		//for (const auto& e : mContainer)
		//{
		//	std::cout << e << std::endl;
		//}
	}

	// List - double Linked List
	{
		//std::list<int> mContainer{ 3,2,1 };

		//std::list<int> mContainer2{ 4,5,6 };

		//mContainer.sort(std::less<int>());
		//mContainer.sort(std::less<int>());

		//mContainer.merge(mContainer2); // merge를 하기 위해서는 모두 컨테이너가 정렬 되어 있어야한다.

		//for (const auto& e : mContainer)
		//{
		//	std::cout << "{" << e << "}";
		//}
		//std::cout << std::endl;
	}

	// Deque
	{
		std::deque<int> mConainter{ 1,2,3,4 };

		mConainter.push_front(0);
		mConainter.push_back(5);

		mConainter.pop_front();
		mConainter.pop_back();

		for (const auto& e : mConainter)
		{
			std::cout << "{" << e << "}";
		}
		std::cout << std::endl;
	}

}	
	