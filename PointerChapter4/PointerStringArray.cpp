#include<iostream>

// 1. 문자열 = 문자로 된 배열 = 포인터
// 2. 포인터 연산 ++ --
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

		//char c[6]{ "doggy" };	// 문자열은 마지막이 널문자가 있기 때문에 마지막 글자수 + 1
		//char* pc = c;
		//Print(pc);

		//char* pc = "doogy";		  // 에러남 doggy가 r-value라서 대입 불가
		//const char* pc = "doogy"; // 우측값 참조를 이용하여 값 대입

		//char myString[]{ "가나다나마바사" };
		//std::cout << myString + 5 << std::endl;
	}


	
	{
		//char input[1000];
		//std::cin >> input;

		//std::cout << input << " : " << GetLength(input) << std::endl;

	}

	{
		//std::cout << strlen(input) << std::endl;
		//std::cout << strlen("HelloWorld") << std::endl;	// 문자열 길이
	}
	
	{
		char MyString[5]{ "cest" };
		char YourString[5]{"bord"};

		//strcpy_s(YourString, MyString);	//문자열 복사
		//strcpy_s(YourString,5,"word");
			

		std::cout << strcmp(MyString, YourString) << std::endl;;		//문자열 비교 , 문자열 길이 비교하는 기능은 아님 // a < b  
																		//0보다 작음	string1이 string2보다 작음
																		//0	string1이 string2와 같음
																		//0보다 큼	string1이 string2보다 큼

		std::cout << MyString << std::endl;
		std::cout << YourString << std::endl;

	}


}