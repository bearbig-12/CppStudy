#include <iostream>
#include "Dog.h"

int main()
{
	Dog Happy;
	Happy.Sound();
	Happy.Roll();

	// Dog is a Animal
	// Dog�� Animal���� �Ļ��Ǿ��� ������ ����
	// �������� Animal ������ �̱� ������ Animal�� ����.
	Animal* animal = &Happy;

	Animal* p = new Dog();
	p->Sound();
	delete p;

}