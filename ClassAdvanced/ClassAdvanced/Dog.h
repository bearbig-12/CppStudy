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
	void Sound() override;	// ����� ���� �Լ��� ������� override�� ���δ�.
							// �ٸ� ���(base) Ŭ�������� virual �Լ��� �� ��������� �Ѵ�.

	Animal* Clone(const Dog& dog)	// ������� ���� ���� ������ ��ȯ Ÿ���� Animal* �� ������ ������ ����.
	{
		return new Dog(*this);
	}
};

