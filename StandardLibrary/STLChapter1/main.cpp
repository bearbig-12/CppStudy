#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	int value;
	int average{ 0 };
	int total{ 0 };
	std::cout << "Please type your grade : ";
	//while (std::cin >> value)	// valueÀÇ Å¸ÀÔÀÌ int°¡ ¾Æ´Ò°æ¿ì false·Î ¹Ýº¹¸ØÃã.
	//{
	//
	//	v.push_back(value);
	//}

	for (int mvalue; std::cin >> mvalue;)
	{
		v.push_back(mvalue);

	}
	for (int e : v)
	{
		total += e;
	}

	/*for (auto e : v)
	{
		total = total + e;
	}*/
	average = total / v.size();
	std::cout << "Total : " << total << " , " << " Average : " << average << std::endl;


}