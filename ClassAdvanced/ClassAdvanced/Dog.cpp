#include "Dog.h"
#include <iostream>
Dog::Dog() : mBreed{RETRIVAL} // Dog::Dog() :  Animal(), mBreed{RETRIVAL} 이렇게 숨겨져 있다.
{
    std::cout << "[Dog] constructor " << std::endl;

}
Dog::Dog(int age, int weight, BREED breed) : Animal(age, weight), mBreed {breed}    
// 자식 생성자를 만드는것 뒤에는 부모 생성자를 암시적으로 부르는 것이 숨겨져 있다.
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
    std::cout << "멍멍 ~!" << std::endl;
}
