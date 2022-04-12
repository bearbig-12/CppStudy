#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	mpTail = nullptr;
	mCount = 0;
}

Stack::~Stack()
{
	Element* element = mpTail;
	Element* pNext{};

	while (element != nullptr)
	{
		pNext = element->mpNext;
		delete element;

		element = pNext;
	}
	mpTail = nullptr;
}

void Stack::PrintInfo(LinkedList& list)
{
	std::cout << "<Stack>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void Stack::UserInput(LinkedList& list)
{
	int Types{ 0 };
	bool IsStop = false;

	while (1)
	{
		system("cls");

		Stack::PrintInfo(list);
		Stack::Print(list);

		std::cout << std::endl;

		std::cout << " Options > ";
		std::cin >> Types;
		switch (Types)
		{
		case ADD:
		{
			int PushValue;
			std::cout << " Push Value : ";
			std::cin >> PushValue;
			Stack::Create(list, PushValue);
			break;

		}
		case DELETE:
			Stack::Delete(list);
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

void Stack::Create(LinkedList& list, int value)
{
	Element* newE = new Element;
	newE->mValue = value;
	mCount++;
	if (mCount == 0)
	{
		newE->mpNext = nullptr;
		mpTail = newE;
	}
	else
	{
		newE->mpNext = mpTail;
		mpTail = newE;
	}
	std::cout << "Push : " << value << std::endl;
}

bool Stack::Delete(LinkedList& list)
{
	Element* p = mpTail;
	if (mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return false;
	}
	mpTail = p->mpNext;
	p->mpNext = nullptr;
	std::cout << "Pop : " << p->mValue << std::endl;
	delete p;
	mCount--;
	return true;
}

void Stack::Print(const LinkedList& list) const
{
	std::cout << " <Stack> " << std::endl;

	Element* p = mpTail;

	if (mCount == 0)
	{
		std::cout << "Empty" << std::endl;
		return;
	}
	while (p != nullptr)
	{
		std::cout << p->mValue << std::endl;
		p = p->mpNext;
	}
	std::cout << " - - - - - - - - - - " << std::endl;
}
