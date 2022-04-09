#include <iostream>
#include "String.h"

int main()
{
	String s1{ "Hello" };
	String s2{ "Test" };
	String s3(10);
	String s4;
	String s5;

	std::cout << s1;
	std::cout << s2;

	s3 = s1 + s2;
	std::cout << s3;
	s4 = s3;
	std::cout << s4;

	s1 += s1;
	std::cout << s1;

	std::cout << s3[0] << s2[1] << std::endl;



}