#include <cstring>
#include <iostream>

#include "DoubleLinkedList.h"

Monster2* CreateMonster(MonsterList2& list, const char* name, const int hp)
{
	Monster2* pNew = new Monster2{};

	strcpy_s(pNew->name, NAME_L, name);
	pNew->HP = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
		list.pTail = pNew;
	}
	else
	{
		pNew->pPrev = list.pTail;
		list.pTail->pNext = pNew;
		list.pTail = pNew;
	}

	return pNew;
}

int GetCountMonsterList(const MonsterList2& list)
{
	Monster2* pCounter = list.pHead;
	int count{0};
	while (pCounter != nullptr)
	{
		++count;
		pCounter = pCounter->pNext;
	}
	return count;
}

void PrintMonsterList(const MonsterList2& list)
{
	Monster2* p { list.pHead };
	if (p == nullptr)
	{
		std::cout << "It is Empty" << std::endl;
	}
	while (p != nullptr)
	{
		std::cout << p->name << " : " << p->HP << std::endl;
		p = p->pNext;
	}
}

void PrintRecursive(Monster2* monster)
{
	if (monster == nullptr)
	{
		return;
	}

	std::cout << "Name : " << monster->name << " , " << "HP : " << monster->HP << std::endl;
	PrintRecursive(monster->pNext);
}

Monster2* FindMonster(const MonsterList2& list, const char* name)
{
	Monster2* p = list.pHead;
	while (p != nullptr)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p;
		}
		p = p->pNext;
	}
	return nullptr;
}

bool Delete(MonsterList2& list, const char* name)
{
	Monster2* pCurrent = list.pHead;
	while (pCurrent != nullptr)
	{
		if (strcmp(pCurrent->name, name) == 0)
		{
			break;
		}
		pCurrent = pCurrent->pNext;
	}
	if (pCurrent == nullptr)
	{
		return false;
	}
	if (list.pHead == list.pTail)
	{
		//盔家 1俺
		list.pHead = list.pTail = nullptr;
	}
	else if (pCurrent == list.pHead)
	{
		//力老 菊
		pCurrent->pNext->pPrev = nullptr;
		list.pHead = pCurrent->pNext;
	}
	else if (pCurrent == list.pTail)
	{
		//力老 第
		list.pTail = list.pTail->pPrev;
		pCurrent->pPrev->pNext = nullptr;
	}
	else
	{
		pCurrent->pPrev->pNext = pCurrent->pNext;
		pCurrent->pNext->pPrev = pCurrent->pPrev;
	}
	delete pCurrent;
	return false;
}

void DeleteAll(MonsterList2& list)
{
	Monster2* p{ list.pHead };
	Monster2* Next;
	while (p != nullptr)
	{
		Next = p->pNext;
		delete p;

		p = Next;
	}
	list.pHead = list.pTail = nullptr;
}
