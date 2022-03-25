#pragma once
#include <iostream>

void Move(int n, char from, char to);

int User_input()
{
	int input{};

	std::cout << "Please Insert the number of discs : ";
	std::cin >> input;

	return input;
}



void Hanoi(int n, char from, char temp, char to)
{

	//base case
	if (n == 1)
	{

		Move(n, from, to);	//A -> C

	}
	//recursive case
	else if (n > 0)
	{
		Hanoi(n - 1, from, to, temp);	//A->B

		Move(n, from, to);

		Hanoi(n - 1, temp, from, to);	//B->C

	}

}
void Move(int n, char from, char to)
{
	static int count{ 1 };	// 이 함수밖에서도 값을 유지 해야 하기 때문에 static
	std::cout << count << " : " << " Move disc " << n << " from " << from << " to " << to << std::endl;
	++count;

}