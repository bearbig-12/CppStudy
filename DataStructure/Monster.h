#pragma once
//Self referenced struture - �ڱ� ���� ����ü
const int NAME_L{ 16 };
struct Monster
{
	char name[NAME_L];
	int HP;

	Monster* pNext;
};