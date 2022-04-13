#include "Warrior.h"
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

void Warrior::DoubleSwing() const
{
	std::cout << '\t' << "Warrior Double Swing!!!" << std::endl;
}

void Warrior::Dead() const
{
	std::cout << "Warrior is Dead" << std::endl;

}
