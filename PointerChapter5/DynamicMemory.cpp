#include <iostream>


//CompileTime Variables

//		Automatic Memory Allocation
//			지역변수, 매개변수
//			'{' 블록에서 태어나고 '}' 블록에서 사망

//		Static Memory Allocation
//			정적변수, 전역변수
//			한번 만들고 앱 종룔까지 살아남음

//		Runtime Variables
//			Dynamic Memory Allocation
//				우리가 원할때 만들고, 제거 가능


//	Dynamic Allocation Memory.
//		C - Style
			void* calloc(size_t num, size_t size);
//			 contiguous memory allocation
//			 원소 하나의 크기가 size, 원소 num개 = num * size
//			 할당된 메모리는 모두 0으로 초기화합니다.
//			 메모리가 부족하거나 에러가 발생하면 nullptr 반환

			void* malloc(size_t size);
//			 memory allocation
//			 바이트로 할당
//			 초기화 x
//			 메모리가 부족하거나 에러가 발생하면 nullptr 반환

			void free(void* ptr);
//			 할당된 메모리 해제

//		C++ Style
//			연산자(Operator)
// 
//			 new
//			  주어진 타입으로 할당 후 돌려준다. 
//		
//			 delete
//			  할당된 메모리 해제
//			
// 			  포인터 변수 = new 타입;
// 			  delete 포인터 변수;
// 
//			  포인터 변수 = new 타입[크기];
//			  delete[] 포인터 변수;


int main()
{
	{
		int* buffer1;
		int* buffer2;

		// 1. 할당
		buffer1 = (int*)calloc(100, sizeof(int));
		buffer2 = (int*)malloc(100 * sizeof(int));
		// 2. 확인
		if (buffer1 != nullptr && buffer2 != nullptr)
		{
			std::cout << buffer1[0] << std::endl;
			std::cout << buffer2[0] << std::endl;
			//3. 해제 (메모리를 할당할때 스택과 같이 쌓기 때문에 생성의 역순으로 해제)
			free(buffer2);
			free(buffer1);


		}
		else
		{
			//문제 처리
		}
	} //C - Style

	{
		// 1. 할당
		int* buffer3;
		//buffer3 = new int;
		buffer3 = new int[100];

		// 2. 확인
		if (buffer3 != nullptr)
		{
			std::cout << buffer3[0] << std::endl;

			// 3. 해제
			//delete buffer3;
			delete[] buffer3;
		}
		else
		{
			// 문제 처리
		}
	} //C++ Style

	
}