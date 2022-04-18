#include <iostream>
#include <algorithm>
#include <vector>

int Compare(const void* left, const void* right)
{
	int arg1 = *(static_cast<const int*>(left)); // ��� �����ʹϱ� ��������ͷ� ��ȯ �� ������
	int arg2 = *(static_cast<const int*>(right));

	//if (arg1 > arg2)
	//{
	//	return 1;
	//}
	//else if (arg1 < arg2)
	//{
	//	return -1;
	//}
	//return 0;
	//return arg2 - arg1;		// ����
	return arg1 - arg2;		// ��������

}


int main()
{
	std::vector<int> v{ 3,2,4,1,5 };

	// C-Style
	//std::qsort(&v[0], v.size(), sizeof(int), Compare);


	// C++Style
	//std::sort(v.begin(), v.end());
	//
	//for (const int& ele : v)
	//{
	//	std::cout << "{" << ele << "}" << " , ";
	//}
}