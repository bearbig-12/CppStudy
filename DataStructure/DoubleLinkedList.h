#pragma once
#include "Monster.h"


struct MonsterList2
{
	Monster* pHead{};
	Monster* pTail{};
};

Monster2* CreateMonster(MonsterList2& list, const char* name, const int hp);
int GetCountMonsterList(const MonsterList2& list);
void PrintMonsterList(const MonsterList2& list);
void PrintRecursive(Monster2* monster);
Monster2* FindMonster(const MonsterList2& list, const char* name);
bool Delete(MonsterList2& list, const char* name);


void DeleteAll(MonsterList2& list);