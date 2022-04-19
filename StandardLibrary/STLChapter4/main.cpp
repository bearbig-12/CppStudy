#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
int main()
{
	{

		//std::array<int, 4> mcontainer{ 0, 1, 2, 3 };

		//for (auto itr = mcontainer.begin(); itr != mcontainer.end(); ++itr)
		//{
		//	std::cout << *itr << std::endl;
		//}


	}
			
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

	{
		std::forward_list<int> mContainer{ 10,11,20,21, 5, 32, 9 };
		auto itr = std::find(mContainer.begin(), mContainer.end(), 11);
		mContainer.insert_after(itr, 12);
		mContainer.erase_after(itr);
		/*mContainer.sort([](const auto& arg1, const auto& arg2)
			{
				return arg1 < arg2;
			}
		);*/
		mContainer.sort(std::less<int>());

		for (const auto& e : mContainer)
		{
			std::cout << e << std::endl;
		}
	}

}	
	