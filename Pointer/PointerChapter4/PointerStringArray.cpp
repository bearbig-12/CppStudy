#include<iostream>

// 1. ���ڿ� = ���ڷ� �� �迭 = ������
// 2. ������ ���� ++ --
// 3. Zero(Null) Terminated '\0'
void Print(char* p)
{
	while(*p != '\0')
	{
		std::cout << *p++ << std::endl;
	}
}
int GetLength(char* p)
{
	int length{};

	while (*p != '\0')
	{
		length++;
		p++;
	}

	return length;
}


int main()
{
	{

		//char c[6]{ "doggy" };	// ���ڿ��� �������� �ι��ڰ� �ֱ� ������ ������ ���ڼ� + 1
		//char* pc = c;
		//Print(pc);

		//char* pc = "doogy";		  // ������ doggy�� r-value�� ���� �Ұ�
		//const char* pc = "doogy"; // ������ ������ �̿��Ͽ� �� ����

		//char myString[]{ "�����ٳ����ٻ�" };
		//std::cout << myString + 5 << std::endl;
	}


	
	{
		//char input[1000];
		//std::cin >> input;

		//std::cout << input << " : " << GetLength(input) << std::endl;

	}

	{
		//std::cout << strlen(input) << std::endl;
		//std::cout << strlen("HelloWorld") << std::endl;	// ���ڿ� ����
	}
	
	{
		char MyString[5]{ "cest" };
		char YourString[5]{"bord"};

		//strcpy_s(YourString, MyString);	//���ڿ� ����
		//strcpy_s(YourString,5,"word");
			

		std::cout << strcmp(MyString, YourString) << std::endl;;		//���ڿ� �� , ���ڿ� ���� ���ϴ� ����� �ƴ� // a < b  
																		//0���� ����	string1�� string2���� ����
																		//0	string1�� string2�� ����
																		//0���� ŭ	string1�� string2���� ŭ

		std::cout << MyString << std::endl;
		std::cout << YourString << std::endl;

	}


}