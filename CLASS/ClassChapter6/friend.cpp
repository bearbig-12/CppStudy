#include <iostream>


class Sword;

class Warrior
{
public:
	void AttackWith(Sword& sword);

};

class Sword
{
	//friend class Warrior;
	friend void Warrior::AttackWith(Sword& sword);
	friend void ForgeEnhance(Sword& sword);

private:
	int mAttack;
public:
	Sword(int attack) : mAttack(attack) {}

};

void Warrior::AttackWith(Sword& sword)
{
	std::cout << "칼을 휘둘러 " << sword.mAttack << " 만큼 피해를 주었다!" << std::endl;
}

void ForgeEnhance(Sword& sword)
{
	sword.mAttack *= 2;
}

int main()
{
	Sword shorSword{ 10 };
	Warrior w;

	w.AttackWith(shorSword);
}