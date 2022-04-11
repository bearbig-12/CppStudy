#include <iostream>
#include "Dog.h"

int main()
{
	Dog Happy;
	Happy.Sound();
	Happy.Roll();

	// Dog is a Animal
	// Dog는 Animal에서 파생되었기 때문에 가능
	// 역참조시 Animal 포인터 이기 때문에 Animal로 간다.
	Animal* animal = &Happy;

	Animal* p = new Dog();
	p->Sound();
	delete p;

}