#include "DynamicQueue.h"
#include <iostream>



void Enqueue(Queue& queue, int value)
{
	Element* pNew = new Element;
	pNew->value = value;
	queue.Count++;

	if (queue.pTail == nullptr)
	{
		queue.pHead = queue.pTail = pNew;
	}
	else
	{
		queue.pTail->pNext = pNew;
		queue.pTail = pNew;
	}
	std::cout << "Enqueue : " << value << std::endl;

}

bool Dequeue(Queue& queue)
{
	Element* p{ queue.pHead };
	if (queue.Count == 0)
	{
		std::cout << "Queue is Empty" << std::endl;
		return false;
	}
	
	std::cout << "Dequeue : " << p->value << std::endl;
	queue.pHead = p->pNext;
	p->pNext = nullptr;
	delete p;
	queue.Count--;

	return true;
}

void Print(Queue& queue)
{
	std::cout << " <Queue> " << std::endl;

	Element* p = queue.pHead;
	if (queue.Count == 0)
	{
		std::cout << "Queue is Empty" << std::endl;
		return;
	}
	while (p != nullptr)
	{
		std::cout << p->value << std::endl;
		p = p->pNext;
	}
	std::cout << "---------------";
}

void UserInput(Queue& queue)
{
	int command{ 0 };
	bool isExit{ false };

	while (true)
	{
		Print(queue);
		std::cout << std::endl;
		std::cout << "Please insert your option : ";
		std::cin >> command;

		switch (command)
		{
		case mENQUEUE:
		{
			int mValue{ 0 };
			std::cout << "		value >> ";
			std::cin >> mValue;
			Enqueue(queue, mValue);
			break;

		}
		case mDEQUEUE:
			Dequeue(queue);
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