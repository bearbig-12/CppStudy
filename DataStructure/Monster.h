#pragma once
//Self referenced struture - �ڱ� ���� ����ü
const int NAME_L{ 16 };
struct Monster
{
	char name[NAME_L]{};
	int HP{0};

	Monster* pNext{ nullptr };
};

struct Monster2
{
	char name[NAME_L]{};
	int HP{0};

	Monster2* pNext{ nullptr };
	Monster2* pPrev{ nullptr };
};