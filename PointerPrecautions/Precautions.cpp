#include <iostream>

// 주의사항

// 1. Merory Leak
//		동적으로 할당하고 해제하지 않은 메모리 -> 작업 속도가 계속 느려짐


// 2. new 도 실패할 수 있음
//		int* p = new int;
// 
//		if(p != nullptr)
//		if(p != 0)
//		if(p)
//		{
//		}

// 3. Dangling Pointer
//		이미 해제된 메모리
//
//		int* p = new int;
// 
//		delete p;
//		p = nullptr;
// 
//		*p = 1;  -> 에러


int main()
{
	int* p = new int;

	if (p)
	{
		// 사용

		delete p;
		p = nullptr;
	}
	else
	{
		//게임이 실행 불가.
	}
}
