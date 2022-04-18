#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	std::vector<int> v{ 3,2,4,5,1 };

	std::for_each(v.begin(), v.end(),
		[](const int& val)->int
		{
			std::cout << val << std::endl;
		}
	);
}