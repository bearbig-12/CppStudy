#include <iostream>

int Factorial(int n)
{
	//base case
	if (n == 1)
	{
		return 1;
	}
	return n * Factorial(n - 1);
}

int Fibonacci(int n)
{
	//base case
	if (n == 1 || n == 2)
	{
		return 1;
	}
	//recursive case
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Sum_array(int arr[], int size)
{

	//base case
	if (size - 1 == 0)
	{
		return  arr[0];
	}
	
	return arr[size - 1] += Sum_array(arr, size - 1);
}

int main()
{
	int array[]{ 1,2,3,4,5 };


	//std::cout << Sum_array(array, 5) << std::endl;;
	std::cout << Factorial(3) << std::endl;
	
}