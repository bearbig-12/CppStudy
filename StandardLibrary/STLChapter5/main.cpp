#include <iostream>
#include <stack>
#include <queue>
#include <set>
int main()
{
	// Stack - LIFO�� �����̳� �����. stack�� ���� LIFO�� Ư������ �����ϸ�, �ٸ��������� ����ϱ�� �Ұ�. 
	//		   �ֱٿ� �߰��� ���Ҹ� �׼����� �� �ֵ��� ����
	{
		//std::stack<int> mContainer;


		//mContainer.push(1);
		//mContainer.push(2);
		//mContainer.push(3);
		//mContainer.pop();

		//std::stack<int> tempContainer(mContainer);	// ���� �����ڷ� ����.
		//while (!tempContainer.empty())
		//{
		//	std::cout << tempContainer.top() << ",";
		//	tempContainer.pop();
		//}
		//std::cout << std::endl;
	}
	
	//Queue - FIFO�� �����̳� �����. Queue�� ���� FIFO�� Ư������ ������ ������, �ٸ� �뵵�� ���Ұ�
	//		  ���� ó���� �߰��� ���ҿ��� ���� ����.
	{
	/*	std::queue<int> mContainer;

		mContainer.push(1);
		mContainer.push(2);
		mContainer.push(3);

		std::cout << mContainer.front() << std::endl;*/


	}

	//Priority Queue
	{
		std::priority_queue<int> mContainer;

		mContainer.push(1);
		mContainer.push(2);
		mContainer.push(3);
		mContainer.push(2);
		mContainer.push(1);

		std::cout << mContainer.top() << std::endl;

		mContainer.pop();
	}

}