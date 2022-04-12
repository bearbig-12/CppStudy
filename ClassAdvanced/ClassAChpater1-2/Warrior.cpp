#include "Warrior.h"
#include <iostream>

Warrior::Warrior()
{
	std::cout << "[+] Warrior Created" << std::endl;
}

Warrior::~Warrior()
{
	std::cout << "[-] Warrior Destructed" << std::endl;

}

void Warrior::Attack() const
{
	std::cout << '\t' << "Warrior Swing!" << std::endl;

}