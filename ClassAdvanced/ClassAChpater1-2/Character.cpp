#include "Character.h"
#include <iostream>
Character::Character() : mHp{ 0 }
{
	std::cout << "[+] Character Created" << std::endl;
}

Character::~Character()
{
	std::cout << "[-] Character Destructed" << std::endl;
}

void Character::Attack() const
{
	std::cout << '\t' << "Virtual Attack" << std::endl;
}