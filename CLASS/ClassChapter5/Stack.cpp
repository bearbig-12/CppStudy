#include "Stack.h"
#include <iostream>

void Stack::StackInfo()
{
	std::cout << "<Stack>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void Stack::UserInput(Stack& stack)
{
	int Types{ 0 };
	bool IsStop = false;
	while (1)
	{
		system("cls");
		Stack::StackInfo();
		Stack::Print(stack);
		std::cout << std::endl;
		std::cout << "Option : ";
		std::cin >> Types;
		switch (Types)
		{
		case stack.PUSH:
		{
			int PushValue;
			std::cout << " Push Value : ";
			std::cin >> PushValue;
			Stack::Push(stack, PushValue);
			break;
		}
		case stack.POP:
			Stack::Pop(stack);
			break;
		case stack.STOP:
			IsStop = true;
			break;
		default:
			std::cout << "It is not valiad option" << std::endl;
			break;
		}
		if (IsStop == true)
		{
			break;
		}
	}
}

void Stack::Push(Stack& stack, int value)
{
	Element* NewE = new Element;
	NewE->mValue = value;
	stack.mCount++;
	if (stack.mTail == nullptr)
	{
		stack.mTail = NewE;
	}
	else
	{
		NewE->pNext = stack.mTail;
		stack.mTail = NewE;
	}
	std::cout << "Push : " << value << std::endl;

}

bool Stack::Pop(Stack& stack)
{
	Element* p{ stack.mTail };
	if (stack.mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return false;
	}
	stack.mTail = p->pNext;
	p->pNext = nullptr;
	std::cout << "Pop : " << p->mValue << std::endl;
	delete p;
	stack.mCount--;
	return true;
}

void Stack::Print(const Stack& stack)
{
	std::cout << " <Stack> " << std::endl;

	Element* p = stack.mTail;
	if (stack.mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return;
 	}
	while (p != nullptr)
	{
		std::cout << p->mValue << std::endl;
		p = p->pNext;
	}
	std::cout << " - - - - - - - - - - " << std::endl;
}
