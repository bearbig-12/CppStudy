#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	enum BREED
	{
		BEAGLE, DOBERMAN, BERNARD, CHIHUAHUA, HUSKY, RETRIVAL
	};

private:
	BREED mBreed;
public:
	Dog();
	Dog(int age, int weight, BREED breed);
	~Dog();

	Dog::BREED GetBreed() const;
	void SetBreed(BREED breed);

	void Roll();
	void Sound();
};

