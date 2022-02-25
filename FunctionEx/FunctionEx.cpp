#include <iostream>


//주어진 start 와 end 사이의 아스키 코드와 그에 해당하는 문자를 출력하는 프로그램


char ReadInput();
void PrintTable(char start, char end);
int GetCode(char input);

int main()
{
	char start{};
	char end{};

	start = ReadInput();
	end = ReadInput();

	PrintTable(start, end);
}

char ReadInput()
{

	char input;
	std::cout << "문자 2개 입력";
	std::cin >> input;
	return input;
}

void PrintTable(char start, char end)
{
	for (char i = start; i <= end; ++i)
	{
		std::cout << GetCode(i) << " - " << i << " , ";
	}
}

int GetCode(char input)
{
	return int(input);
}