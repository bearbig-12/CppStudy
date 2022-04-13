#include "Character.h"
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

