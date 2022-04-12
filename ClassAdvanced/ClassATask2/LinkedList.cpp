#include "LinkedList.h"
#include <iostream>

void LinkedList::UserInput(LinkedList& list)
{
	int types;
	bool IsStop = false;
	while (1)
	{
		system("cls");
		LinkedList::PrintInfo(list);
		LinkedList::Print(list);
		std::cout << std::endl;

		std::cout << " Options > ";
		std::cin >> types;
		
		switch (types)
		{
		case ADD:
		{
			int Add_Value;
			std::cout << '\t' << "Value >";
			std::cin >> Add_Value;
			LinkedList::Create(list, Add_Value);
			break;
		}
		case DELETE:
		{
			int D_value;
			std::cout << '\t' << "Value >";
			std::cin >> D_value;
			LinkedList::Find_Delete(list, D_value);
			break;
		}
			
		case FIND:
		{
			int F_Value;
			std::cout << '\t' << "D_Value >";
			std::cin >> F_Value;
			LinkedList::Find_Delete(list, F_Value);
			break;
		}
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

void LinkedList::Create(LinkedList& list, int value)
{
	Element* newE = new Element;
	newE->mValue = value;
	
	if (mCount == 0)
	{
		newE->mpNext = nullptr;
		mpHead = mpTail = newE;
	}
	else
	{
		mpTail->mpNext = newE;
		mpTail = newE;
	}
	mCount++;
	std::cout << "Add : " << value << std::endl;
}

bool LinkedList::Delete(LinkedList& list)
{
	return false;
}

LinkedList::Element* LinkedList::Find(LinkedList& list, int value)
{
	Element* p = mpHead;
	while(p != nullptr)
	{
		if (p->mValue == value)
		{
			std::cout << "Found : " << value << std::endl;
			return p;
		}
		p = p->mpNext;
	}
	return nullptr;
}

bool LinkedList::Find_Delete(LinkedList& list, int value)
{
	Element* p = mpHead;
	Element* previous{};
	while (p != nullptr)
	{
		if (p->mValue == value)
		{
			std::cout << "Found : " << value << std::endl;
			break;
		}
		previous = p;
		p = p->mpNext;
	}
	
	if (p == nullptr)
	{
		return false;
	}
	if (p == mpHead)
	{
		mpHead = p->mpNext;
	}
	else if (p == mpTail)
	{
		mpTail = previous;
		previous->mpNext = nullptr;
	}
	else
	{
		previous->mpNext = p->mpNext;
	}
	if (mCount == 1)
	{
		mpHead = mpTail = nullptr;
	}
	delete p;
	mCount--;
	return true;
}

void LinkedList::Print(const LinkedList& list) const
{
	Element* p = mpHead;
	while (p != nullptr)
	{
		std::cout << p->mValue << "	->	";
		p = p->mpNext;
	}
}

void LinkedList::PrintInfo(LinkedList& list)
{
	std::cout << "<LinkedList>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "[4] Find" << std::endl;
	std::cout << "----------------" << std::endl;
}


