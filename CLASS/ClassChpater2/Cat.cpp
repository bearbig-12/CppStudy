#include "Cat.h"

void Cat::Meow()
{
	std::cout << "meow" << std::endl;
}

int Cat::GetAge() const 
{
	
	return this->mAge;
}
