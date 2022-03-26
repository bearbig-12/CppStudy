#include <iostream>
#include "DynamicStack.h"



void Push(Stack& stack, int value)
{
	Element* pNew = new Element{};
	pNew->value = value;
	stack.Count++;

	if (stack.pTail == nullptr)
	{
		stack.pTail = pNew;
	}
	else
	{
		pNew->pPrev = stack.pTail;
		stack.pTail = pNew;
	}
	
	std::cout << "Push : " << value << std::endl;
}

bool Pop(Stack& stack)
{
	Element* p{ stack.pTail };
	if (stack.pTail == nullptr || stack.Count == 0)
	{
		std::cout << "Stack is Empty" << std::endl;
		return false;
	}
	stack.pTail = p->pPrev;
	p->pPrev = nullptr;
	std::cout << "Pop : " << p->value << std::endl;
	delete p;
	stack.Count--;
	return true;
}

void Print(Stack& stack)
{
	std::cout << " <Stack> " << std::endl;

	Element* p = stack.pTail;
	if (stack.Count == 0)
	{
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
	while (p != nullptr)
	{
		std::cout << p->value << std::endl;
		p = p->pPrev;
	}
	std::cout << "---------------";
}

void UserInput(Stack& stack)
{
	int command{ 0 };
	bool isExit{ false };

	while (true)
	{
		Print(stack);
		std::cout << std::endl;
		std::cout << "Please insert your option : ";
		std::cin >> command;

		switch (command)
		{
		case mPUSH:
		{
			int mValue{ 0 };
			std::cout << "		value >> ";
			std::cin >> mValue;
			Push(stack, mValue);
			break;

		}
		case mPOP:
			Pop(stack);
			break;
		case mSTOP:
			isExit = true;
			break;
		default:
			std::cout << "It is not valiad option" << std::endl;
			break;
		}
		if (isExit == true)
		{
			break;
		}
	}
}