#include <iostream>
#include <algorithm>
#include <vector>

int Compare(const void* left, const void* right)
{
	int arg1 = *(static_cast<const int*>(left)); // 상수 포인터니까 상수포인터로 변환 후 역참조
	int arg2 = *(static_cast<const int*>(right));

	return arg1 - arg2;		// 오름차순

}


int main()
{
	std::vector<int> v{ 3,2,4,1,5 };
	std::qsort(&v[0], v.size(), sizeof(int),
		[](const void* left, const void* right)->int // 람다식
		{
			int arg1 = *(static_cast<const int*>(left)); // 상수 포인터니까 상수포인터로 변환 후 역참조
			int arg2 = *(static_cast<const int*>(right));

			//return arg2 - arg1;		// 내림
			return arg1 - arg2;		// 오름차순
		}
	);
	// 람다식 : [](parameter1, parameter2)->returnType {	expression	}



}