#include "Queue.h"
#include <iostream>

void Queue::QueueInfo()
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] Enqueue" << std::endl;
	std::cout << "[2] Dequeue" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void Queue::UserInput(Queue& queue)
{
	int Types{ 0 };
	bool IsStop = false;
	while (1)
	{
		system("cls");
		Queue::QueueInfo();
		Queue::Print(queue);
		std::cout << std::endl;
		std::cout << "Option : ";
		std::cin >> Types;
		switch (Types)
		{
		case queue.ENQUEUE:
		{
			int EnqueueValue;
			std::cout << " Enqueue Value : ";
			std::cin >> EnqueueValue;
			Queue::Enqueue(queue, EnqueueValue);
			break;
		}
		case queue.DEQUEUE:
			Queue::Dequeue(queue);
			break;
		case queue.STOP:
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

void Queue::Enqueue(Queue& queue, int value)
{
	Element* NewE = new Element;
	NewE->mValue = value;
	if (queue.mCount == 0)
	{
		queue.mHead = queue.mTail = NewE;
	}
	else
	{
		queue.mTail->pNext = NewE;
		queue.mTail = NewE;
	}
	queue.mCount++;
}

bool Queue::Dequeue(Queue& queue)
{
	if (queue.mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return false;
	}
	Element* p{ queue.mHead };
	std::cout << "Dequeue : " << std::endl;

	queue.mHead = p->pNext;
	delete p;
	queue.mCount--;

	if (queue.mCount == 0)
	{
		queue.mHead = queue.mTail = nullptr;
	}
	return true;
}

void Queue::Print(const Queue& queue)
{
	std::cout << " <Queue> " << std::endl;

	Element* p{ queue.mHead };
	if (queue.mCount == 0)
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
