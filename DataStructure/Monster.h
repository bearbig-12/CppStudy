#pragma once
//Self referenced struture - �ڱ� ���� ����ü
const int NAME_L{ 16 };
struct Monster
{
	char name[NAME_L];
	int HP;

	Monster* pNext;
};

struct Monster2
{
	char name[NAME_L];
	int HP{0};

	Monster* pNext;
	Monster* pPrev;
};