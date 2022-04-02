#include "String.h"
#include <iostream>
String::String(const char* string) : mString{}
{
	int length{ 0 };

	while (string[length] != '\0')
	{
		length++;
	}

	mString = new char[length + 1];

	for (int i = 0; i < length; ++i)
	{
		mString[i] = string[i];
	}
	mString[length] = '\0';
}

String::~String()
{
	delete[] mString;
	mString = nullptr;
	
}

void String::Print()
{
	std::cout << mString << std::endl;
}
