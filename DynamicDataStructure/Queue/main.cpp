#include <iostream>
#include "DynamicQueue.h"
void PrintStackInfo()
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] Enqueue" << std::endl;
	std::cout << "[2] Dequeue" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

int main()
{
	std::cout << "Hello World[Queue]" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	PrintStackInfo();
	Queue queue;

	UserInput(queue);
}