#pragma once
#include <iostream>
#include <string>

enum Monster_Type
{
	Wolf,
	Demon,
	Slime
};

struct Monster_Data
{
	Monster_Type type;
	std::string name;
	int hp;
};

void Print_Monster(struct Monster_Data data)
{
	switch (data.type)
	{
	case Wolf:
		std::cout << "Monster Type : " << "Wolf" << " , " << "Monster Name : " << data.name << " , " << "Monster HP : " << data.hp << std::endl;
		break;

	case Demon:
		std::cout << "Monster Type : " << "Demon" << " , " << "Monster Name : " << data.name << " , " << "Monster HP : " << data.hp << std::endl;
		break;

	case Slime:
		std::cout << "Monster Type : " << "Slime" << " , " << "Monster Name : " << data.name << " , " << "Monster HP : " << data.hp << std::endl;
		break;

	default:
		std::cout << " Cannot find that monster, please try again" << std::endl;
		break;
	}
}