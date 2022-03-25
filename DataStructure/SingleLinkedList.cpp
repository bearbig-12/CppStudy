#include <iostream>
#include <cstring>

#include "SingleLinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
	Monster* pNew = new Monster{};

	strcpy_s(pNew->name, NAME_L, name);
	pNew->HP = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
		list.pTail = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
	}
	list.pTail = pNew;


	return pNew;
}

int GetCountMonsterList(const MonsterList& list)
{
	
	int count{ 0 };
	Monster* Counter{ list.pHead };
	while (Counter != nullptr)
	{
		++count;
		Counter = Counter->pNext;
	}
	return count;
}

void PrintMonsterList(const MonsterList& list)
{
	int count{ 1 };
	Monster* Printer{ list.pHead };
	while (Printer != nullptr)
	{
		std::cout << "No." << count << " , " << "Name : " << Printer->name << " , " << "HP : " << Printer->HP << std::endl;
		Printer = Printer->pNext;
		++count;
	}
}

void PrintRecursive(Monster* monster)
{
	if (monster == nullptr)
	{
		return;
	}

	//recursive
	std::cout << "Name : " << monster->name << " , " << "HP : " << monster->HP << std::endl;

	PrintRecursive(monster->pNext);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	for (Monster* p = list.pHead; p != nullptr; p = p->pNext)
	{
		if (strcmp(p->name, name)==0)
		{
			return p;
		}
	}
	return nullptr;
}

void DeleteAll(MonsterList& list)
{
	Monster* p = list.pHead;
	Monster* pNext{};
	while (p != nullptr)
	{
		pNext = p->pNext;
		delete p;

		p = pNext;
	}
	list.pHead = nullptr;
	list.pTail = nullptr;
}

bool Delete(MonsterList& list, const char* name)
{
	Monster* pCurrent = list.pHead;
	Monster* previous = nullptr;	// 전 element를 담을 변수

	while (pCurrent != nullptr)
	{
		if (strcmp(pCurrent->name,name) == 0)
		{
			break;
		}

		previous = pCurrent;
		pCurrent = pCurrent->pNext;

	}
	
	if (pCurrent == nullptr)	// 마지막까지 가서 못찾음
	{
		return false;
	}
	if (list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	else if (list.pHead == pCurrent) // previous == nullptr
	{
		//head
		list.pHead = pCurrent->pNext;
	}
	else if (list.pTail == pCurrent)	//element->pNext == nullptr
	{
		//tail
		list.pTail = previous;
		previous->pNext = nullptr;
		
	}
	else
	{
		//middle
		previous->pNext = pCurrent->pNext;

	}
	delete pCurrent;
	
	return false;
}