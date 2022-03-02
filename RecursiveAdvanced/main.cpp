#include <iostream>
#include "HanoiVer1.h"

int main()
{
	int input;
	input = User_input();
	Hanoi(input, 'A', 'B', 'C');
}