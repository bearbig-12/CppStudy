#include "Dog.h"
#include <iostream>
Dog::Dog() : mBreed{RETRIVAL} // Dog::Dog() :  Animal(), mBreed{RETRIVAL} �̷��� ������ �ִ�.
{
    std::cout << "[Dog] constructor " << std::endl;

}
Dog::Dog(int age, int weight, BREED breed) : Animal(age, weight), mBreed {breed}    
// �ڽ� �����ڸ� ����°� �ڿ��� �θ� �����ڸ� �Ͻ������� �θ��� ���� ������ �ִ�.
{
    std::cout << "[Dog] constructor(age, weight, breed) " << std::endl;
}
Dog::~Dog()
{
    std::cout << "[Dog] destructor " << std::endl;

}



Dog::BREED Dog::GetBreed() const
{
    return mBreed;
}

void Dog::SetBreed(BREED breed)
{
    mBreed = breed;
}

void Dog::Roll()
{
    std::cout << " Rolling " << std::endl;
}

void Dog::Sound()
{
    std::cout << "�۸� ~!" << std::endl;
}
