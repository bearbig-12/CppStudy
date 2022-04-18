#include <iostream>
#include <algorithm>
#include <vector>

int Compare(const void* left, const void* right)
{
	int arg1 = *(static_cast<const int*>(left)); // ��� �����ʹϱ� ��������ͷ� ��ȯ �� ������
	int arg2 = *(static_cast<const int*>(right));

	return arg1 - arg2;		// ��������

}


int main()
{
	std::vector<int> v{ 3,2,4,1,5 };
	std::qsort(&v[0], v.size(), sizeof(int),
		[](const void* left, const void* right)->int // ���ٽ�
		{
			int arg1 = *(static_cast<const int*>(left)); // ��� �����ʹϱ� ��������ͷ� ��ȯ �� ������
			int arg2 = *(static_cast<const int*>(right));

			//return arg2 - arg1;		// ����
			return arg1 - arg2;		// ��������
		}
	);
	// ���ٽ� : [](parameter1, parameter2)->returnType {	expression	}



}