#include <iostream>
#include <set>
#include <map>
#include <string>

int main()
{
	//SET - BST와 비슷함 값
	{
	/*	std::set<int> mContainer{ 8,3,1,6, 10, 27, 4, 5 };

		for (const auto& e : mContainer)
		{
			std::cout << e << " , ";
		}
		std::cout << std::endl;*/
	}
	

	using MyPair = std::pair<std::string, std::string>;
	//Map - Key와 Value 구분
	{
		std::map<std::string,std::string> mDictionary;

		std::pair<std::string, std::string> element;
		element.first = "array";
		element.second = "Simple Static Array";

		mDictionary.insert(element);

		//constructor
		mDictionary.insert(std::pair<std::string, std::string>("vector", "Dynamic Array"));

		//using alias
		mDictionary.insert(MyPair("stack", "LIFO"));

		//uniform initialization
		mDictionary.insert({ "queue", "FIFO" });


		for (const auto& e : mDictionary)
		{
			std::cout << e.first << " : " << e.second << std::endl;
		}
		std::cout << mDictionary.at("array") << std::endl;
		std::cout << mDictionary["array"] << std::endl;
	}

}