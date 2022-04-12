#include "DynamicQueue.h"
#include <iostream>
DynamicQueue::DynamicQueue()
{
	mpFirst = mpTail = nullptr;
	mCount = 0;
}

DynamicQueue::~DynamicQueue()
{
	Element* p = mpFirst;
	while (p != nullptr)
	{
		Element* pNext = p->mpNext;
		delete p;
		p = pNext;
	}
	mpFirst = mpTail = nullptr;

}

void DynamicQueue::PrintInfo(LinkedList& list)
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] Enqueue" << std::endl;
	std::cout << "[2] Dequeue" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void DynamicQueue::UserInput(LinkedList& list)
{
	int Types{ 0 };
	bool IsStop = false;
	while (1)
	{
		system("cls");
		DynamicQueue::PrintInfo(list);
		DynamicQueue::Print(list);

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
			DynamicQueue::Push(list, EnqueueValue);
			break;
		}
		case DELETE:
			DynamicQueue::Pop(list);
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

void DynamicQueue::Push(LinkedList& list, int value)
{
	Element* newE = new Element;
	newE->mValue = value;
	

	if (mCount == 0)
	{
		mpFirst = mpTail = newE;
	}
	else
	{
		mpTail->mpNext = newE;
		mpTail = newE;
	}
	mCount++;
}

bool DynamicQueue::Pop(LinkedList& list)
{
	if (mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return false;
	}
	Element* p = mpFirst;
	std::cout << "Dequeue : " << p->mValue << std::endl;

	mpFirst = p->mpNext;
	delete p;
	mCount--;
	if (mCount == 0)
	{
		mpFirst = mpTail = nullptr;
	}
	return true;
}

void DynamicQueue::Print(const LinkedList& list) const
{
	std::cout << "<Queue>" << std::endl;
	Element* p = mpFirst;
	while (p != nullptr)
	{
		std::cout << p->mValue << std::endl;
		p = p->mpNext;
	}
	std::cout << " - - - - - - - - - - - - - - " << std::endl;
}
