#include <iostream>
#include <string>


struct Students
{
	
	char* Name = new char[50];
	int Name_Length{};
	
};

void Resizing(int* Old_array, int* New_array)
{
	for (int i = 0; i < 3; ++i)
	{
		New_array[i] = Old_array[i];
	}

	delete[] Old_array;
	Old_array = New_array;	
	// 배열을 새로 만드는게 아니라 원래 있던 배열의 사이즈를 줄이는 것. 따라서 New_array의 주소를 Old_array에 대입.

	for (int i = 0; i < 3; ++i)
	{
		std::cout << Old_array[i] << " , ";
	}

	delete[] New_array;
	New_array = nullptr;
}

void LongestName()
{
	std::cout << "Hello this programm gonna find the longest name in your friends list." << std::endl;
	std::cout << "Please type your number of friends : ";
	unsigned int friends;

	if (!(std::cin >> friends) || friends == 0)
	{
		std::cout << "You can only use natural number for the programm " << std::endl;
		return;
	}
	std::string* Name_list = new std::string[friends];
	std::string LgName;
	for (int i = 0; i < friends; ++i)
	{
		std::cout << "Please type your frined's name : ";
		std::cin >> Name_list[i];
		if (i == 0)
		{
			LgName = Name_list[i];
		}
		else if (i != 0 && (Name_list[i].size() > Name_list[i-1].size()))
		{
			LgName = Name_list[i];
		}
	
	}
	std::cout << " The Longest Name is : " << LgName << std::endl;

}
int getLength(Students student)
{
	int length = 0;
	while (student.Name[length] != '\0')
	{
		++length;
	}
	return length;
}
void LongestName2()
{
	
	std::cout << "Hello this programm gonna find the longest name in your friends list." << std::endl;
	std::cout << "Please type your number of friends : ";
	unsigned int friends;
	std::cin >> friends;
	Students* Student_list = new Students[friends];
	int longest;
	char* longet_name{};
	if (friends == 0)
	{
		std::cout << "You can only use natural number for the programm " << std::endl;
		return;
	}
	
	for (int i = 0; i < friends; ++i)
	{
		std::cout << "Please type your frined's name : ";
		
		std::cin >> Student_list[i].Name;
		Student_list[i].Name_Length = getLength(Student_list[i]);
		if (i == 0)
		{

			longest = Student_list[i].Name_Length;
			longet_name = Student_list[i].Name;
		}
		else if(Student_list[i].Name_Length > Student_list[i-1].Name_Length)
		{
			longest = Student_list[i].Name_Length;
			longet_name = Student_list[i].Name;

		}

	}
	delete[] Student_list->Name;
	delete[] Student_list;
	
	std::cout << longet_name << std::endl;
}

int main()
{
	int* Base_array = new int[5]{ 4,8,5,3,1 };

	int* temp = new int[3]{};

	Resizing(Base_array, temp);
	
	LongestName2();
}

