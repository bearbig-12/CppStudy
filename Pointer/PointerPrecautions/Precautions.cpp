#include <iostream>

// ���ǻ���

// 1. Merory Leak
//		�������� �Ҵ��ϰ� �������� ���� �޸� -> �۾� �ӵ��� ��� ������


// 2. new �� ������ �� ����
//		int* p = new int;
// 
//		if(p != nullptr)
//		if(p != 0)
//		if(p)
//		{
//		}

// 3. Dangling Pointer
//		�̹� ������ �޸�
//
//		int* p = new int;
// 
//		delete p;
//		p = nullptr;
// 
//		*p = 1;  -> ����


int main()
{
	int* p = new int;

	if (p)
	{
		// ���

		delete p;
		p = nullptr;
	}
	else
	{
		//������ ���� �Ұ�.
	}
}
