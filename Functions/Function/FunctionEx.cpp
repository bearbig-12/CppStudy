#include <iostream>

void DrawLine()
{
	int length;
	std::cout << "±æÀÌ : ";
	std::cin >> length;

	std::cout << std::endl;

	char Line[30]{};
	for (int i = 0; i < length; ++i)
	{
		Line[i] = '-';
	}

	for (int i = 0; i < length; ++i)
	{
		std::cout << Line[i];
	}
}

int PutNumber(int number)
{
	std::cout << "The number you wrote is : " << number << std::endl;
	return number;
}

int Squared(int number)
{
	std::cout << "Squared nuber is : " << number * number << std::endl;
	return number * number;
}


int main()
{
	//DrawLine();
	PutNumber(5);
	Squared(10);
	//Squared(PutNumber(5));
}