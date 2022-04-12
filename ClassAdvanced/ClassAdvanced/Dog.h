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
	void Sound() override;	// 덮어쓰고 싶은 함수가 있을경우 override를 붙인다.
							// 다만 기반(base) 클래스에서 virual 함수를 꼭 정의해줘야 한다.

	Animal* Clone(const Dog& dog)	// 편법으로 만든 복사 생성자 반환 타입이 Animal* 인 이유는 다형성 때문.
	{
		return new Dog(*this);
	}
};

