#include <iostream>
#include "DynamicStack.h"
void PrintStackInfo()
{
	std::cout << "<Stack>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

int main()
{

	std::cout << "Hello World[Stack]" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	PrintStackInfo();
	Stack stack;

	UserInput(stack);

}