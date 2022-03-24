#pragma once
//Self referenced struture - 자기 참조 구조체
const int NAME_L{ 16 };
struct Monster
{
	char name[NAME_L];
	int HP;

	Monster* pNext;
};