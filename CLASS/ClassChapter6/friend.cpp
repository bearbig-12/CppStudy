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
	std::cout << "Į�� �ֵѷ� " << sword.mAttack << " ��ŭ ���ظ� �־���!" << std::endl;
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