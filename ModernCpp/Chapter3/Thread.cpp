#include <iostream>
#include <thread>
#include <mutex>

// ������
//
//		�ϳ��� ����� ���ؼ� �ٸ� ��ɵ��� ���� �ʿ�� ����. �׷��⿡ �ϳ��� ���μ��������� ���ÿ� ó���� �ʿ��ϴ�
//		�̷��� ���� Thread��� �θ���. ������� ���ð� �ƴ϶� �����층�̸� ���μ����� �ڿ� �����ϴ� ����̴�
//		������ 2���� �����尡 �ϳ��� ������ ������ ��� ��������(DeadLock) �߻��� �� �ִ�.
//		�̷��� ���� ��ȣ������ �̿��Ͽ� Ư�� �����尡 �ڿ��� ������϶��� �ٸ� �����尡 �������� ���ϰ� �ؾ��Ѵ�.
//

std::mutex mutex;
//WorkerA
void PrintInt()
{
	for (int i = 0; i < 500; ++i)
	{
		mutex.lock();
		std::cout << "Worker1 : " << i << std::endl;
		mutex.unlock();
	}
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
	std::thread worker1(PrintInt);
	std::thread worker2(PrintAscii);

	worker1.join();
	worker2.join();

	std::cout << "----��� �۾��� ������----" << std::endl;

}