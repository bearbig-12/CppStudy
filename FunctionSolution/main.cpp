#include <iostream>

double Compare(double a, double b)
{
	if (a < b)
	{
		std::cout << b << std::endl;
		return b;
	}
	else if (a > b)
	{
		std::cout << a << std::endl;
		return a;
	}
	else
	{
		std::cout << " a = b " << std::endl;
		std::cout << a << std::endl;

		return a;
	}
}

int ReadValue()
{
	int x;
	std::cout << "Please insert the integer : " ;
	std::cin >> x;


	return x;
}
void WriteValue(int x)
{
	std::cout << "The integer number is : ";
	std::cout << x << std::endl;
}

int Quotient(int x, int y)
{
	int result;
	if (x == 0 || y == 0)
	{
		std::cout << " Please try again " << std::endl;
		return 0;
	}
	if (x > y)
	{
		result = x / y;
		std::cout << x <<  " devide " << y << " = " << result << std::endl;
		return result;
	}
	else if (x < y)
	{
		result = y / x;
		std::cout << y << " devide " << x << " = " << result << std::endl;
		return result;
	}
	
}

double Remainder(int x, int y)
{
	double result;
	if (x == 0 || y == 0)
	{
		std::cout << " Please try again " << std::endl;
		return 0;
	}
	if (x > y)
	{
		result = x % y;
		std::cout << "Remainder is : " << result << std::endl;
		return result;

	}
	else if (x < y)
	{
		result = y % x;
		std::cout << "Remainder is : " << result << std::endl;
		return result;
	}
}

void GuGu_Dan(int x)
{
	std::cout << x << "´Ü" << std::endl;
	for (int i = 1; i <= 9; ++i)
	{
		
		std::cout << x << " x " << i << " = " << x * i << std::endl;
	}
}



int main()
{
	//Compare(10.4, 10.4);

	//int value;
	//value = ReadValue();
	//WriteValue(value);

	//WriteValue(ReadValue());

	//Quotient(0, 3);
	//Remainder(10, 3);
	//GuGu_Dan(3);
	for (int i = 2; i <= 9; ++i)
	{
		GuGu_Dan(i);
	}
	
}