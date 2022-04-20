#include <iostream>
#include <stack>
#include <queue>
#include <set>
int main()
{
	// Stack - LIFO의 컨테이너 어답터. stack은 오직 LIFO의 특성만을 충족하며, 다른범용으로 사용하기는 불가. 
	//		   최근에 추가된 원소만 액세스할 수 있도록 제한
	{
		//std::stack<int> mContainer;


		//mContainer.push(1);
		//mContainer.push(2);
		//mContainer.push(3);
		//mContainer.pop();

		//std::stack<int> tempContainer(mContainer);	// 복사 생성자로 복사.
		//while (!tempContainer.empty())
		//{
		//	std::cout << tempContainer.top() << ",";
		//	tempContainer.pop();
		//}
		//std::cout << std::endl;
	}
	
	//Queue - FIFO의 컨테이너 어답터. Queue는 오직 FIFO의 특성만을 가지고 있으며, 다른 용도로 사용불가
	//		  가장 처음에 추가된 원소에만 접근 가능.
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