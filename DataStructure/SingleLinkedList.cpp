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
