#include <iostream>


//�־��� start �� end ������ �ƽ�Ű �ڵ�� �׿� �ش��ϴ� ���ڸ� ����ϴ� ���α׷�


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
	std::cout << "���� 2�� �Է�";
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