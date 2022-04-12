#include "Queue.h"
#include <iostream>
Queue::Queue()
{
	mpHead = mpTail = nullptr;
	mCount = 0;
}

Queue::~Queue()
{
	Element* p = mpHead;
	while (p != nullptr)
	{
		Element* pNext = p->mpNext;
		delete p;
		p = pNext;
	}
	mpHead = mpTail = nullptr;
}

void Queue::PrintInfo(LinkedList& list)
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] Enqueue" << std::endl;
	std::cout << "[2] Dequeue" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void Queue::UserInput(LinkedList& list)
{
	int Types{ 0 };
	bool IsStop = false;
	while (1)
	{
		system("cls");
		Queue::PrintInfo(list);
		Queue::Print(list);

		std::cout << std::endl;

		std::cout << " Options > ";
		std::cin >> Types;
		switch (Types)
		{
		case ADD:
		{
			int EnqueueValue;
			std::cout << " Enqueue Value : ";
			std::cin >> EnqueueValue;
			Queue::Create(list, EnqueueValue);
			break;
		}
		case DELETE:
			Queue::Delete(list);
			break;
		case STOP:
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

void Queue::Create(LinkedList& list, int value)
{
	Element* newE = new Element;
	newE->mValue = value;


	if (mCount == 0)
	{
		mpHead = mpTail = newE;
	}
	else
	{
		mpTail->mpNext = newE;
		mpTail = newE;
	}
	mCount++;
}

bool Queue::Delete(LinkedList& list)
{
	if (mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return false;
	}
	Element* p = mpHead;
	std::cout << "Dequeue : " << p->mValue << std::endl;

	mpHead = p->mpNext;
	delete p;
	mCount--;
	if (mCount == 0)
	{
		mpHead = mpTail = nullptr;
	}
	return true;
}

void Queue::Print(const LinkedList& list) const
{
	std::cout << "<Queue>" << std::endl;
	Element* p = mpHead;
	while (p != nullptr)
	{
		std::cout << p->mValue << std::endl;
		p = p->mpNext;
	}
	std::cout << " - - - - - - - - - - - - - - " << std::endl;
}
