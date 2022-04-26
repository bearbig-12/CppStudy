#include <iostream>
#include <thread>
#include <mutex>
#include <future>
// 쓰레드
//
//		하나의 기능을 위해서 다른 기능들을 멈출 필요는 없다. 그렇기에 하나의 프로세스에서도 동시에 처리가 필요하다
//		이러한 것을 Thread라고 부른다. 쓰레드는 동시가 아니라 스케쥴링이며 프로세스의 자원 공유하는 방식이다
//		하지만 2개의 스레드가 하나의 정보에 접근할 경우 교착상태(DeadLock) 발생할 수 있다.
//		이러한 경우는 상호배제를 이용하여 특정 쓰레드가 자원을 사용중일때는 다른 쓰레드가 접근하지 못하게 해야한다.
//

std::mutex mutex;
//WorkerA
void PrintInt()
{
	mutex.lock();
	for (int i = 0; i < 500; ++i)
	{
		
		std::cout << "Worker1 : " << i << std::endl;
		
	}
	mutex.unlock();
}

//WorkerB
void PrintAscii()
{
	for (int repeat = 0; repeat < 5; ++repeat)
	{
		for (int i = 33; i < 126; ++i)
		{
			std::cout << "Worker2 : " << (char)i << std::endl;
		}
	}
}

int main()
{
	/*std::thread worker1(PrintInt);
	std::thread worker2(PrintAscii);

	worker1.join();
	worker2.join();

	std::cout << "----모든 작업이 끝났다----" << std::endl;*/

	// 비동기 방식 함수 호출
	std::future<void> aync1 = std::async(PrintInt);
	std::future<void> aync2 = std::async(PrintAscii);
	std::cout << "----모든 작업이 끝났다----" << std::endl;

	aync1.get();
	std::cout << "Print int Done" << std::endl;

	aync2.get();
	std::cout << "Print ascii Done" << std::endl;

}