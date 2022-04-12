#include "Animal.h"
#include <iostream>
Animal::Animal() : mAge{1}, mWeight{1}
{
	std::cout << "[Animal] constructor " << std::endl;
}

Animal::Animal(int age, int weight) : mAge{age}, mWeight{weight}
{
	std::cout << "[Animal] constructor (age, weight) " << std::endl;

}

Animal::~Animal()
{
	std::cout << "[Animal] destructor " << std::endl;

}

int Animal::GetAge() const
{
	return mAge;
}

void Animal::SetAge(int age)
{
	mAge = age;
	return ;
}

int Animal::GetWeight() const
{
	return mWeight;
}

void Animal::SetWeight(int weight)
{
	mWeight = weight;
}

void Animal::Sound()
{
	std::cout << "Some Sound " << std::endl;
}

Animal* Animal::Clone()
{
	return new Animal(*this);
}
