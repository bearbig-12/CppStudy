#pragma once
#include <iostream>

class Cat
{
private:
	int mAge;
	const int LEG_COUNT = 4;
public:
	void Meow();
	int GetAge() const;	// ��� ��� �Լ�
};

