#include <iostream>
#include "Cat.h"

int main()
{
	Cat Nacho;
	Nacho.Meow();

	Cat* Navi{ new Cat };
	Navi->Meow();
	delete Navi;
}