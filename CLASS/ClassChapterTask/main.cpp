#include <iostream>
#include "String.h"


int main()
{
	String empty;
	std::cout << empty;

	String sized(10);
	std::cout << sized;

	String s1("test");
	std::cout << s1[0] << s1[1] << s1[2] << s1[3] << s1[4] << s1[5] << std::endl;

	String s2(s1);
	String s3 = s1 + s2;
	std::cout << s3;

	s3 += s3;
	s3[0] = 'T';
	std::cout << s3;

	empty = s3;
	std::cout << empty;

	empty = empty;
	std::cout << empty;

}