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
	//��κ��� ���
	for (int& ele : v2) // �� ������ ���ؼ��� ���������� ��� �ؾ���
	{					// �ε����� �� �� ����.
		if (ele == 3)
		{
			ele = 1;
		}
	}
	// index for Loop
	// �ε����� �ʿ��� ���
	for (int i = 0; i < v2.size(); i++)
	{
		std::cout << v2[i] << std::endl;
	}


	//STL�� ���õ� �۾�
	int k = 0;
	std::vector<int>::iterator itr;
	for (itr = v2.begin(); itr != v2.end(); ++itr, ++k)
	{
		std::cout << *itr << std::endl;
	}
}