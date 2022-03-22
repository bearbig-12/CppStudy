#pragma once


enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

const int SIZE = 10;

struct Stack
{
	int array[SIZE];
	int topIndex = -1;
};

void PrintStack(Stack& stack);
void Push(Stack& stack, int value);
void Pop(Stack& stack);

void PrintStackInfo()
{
	std::cout << "<Stack>" << std::endl;
	std::cout << "[1] Push" << std::endl;
	std::cout << "[2] Pop" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
} 

void StackUserInput(Stack& stack)
{
	int command{};
	bool isExit{ false };

	while (true)
	{
		PrintStack(stack);
		std::cout << std::endl;
		std::cout << "Please insert your option : ";
		std::cin >> command;

		switch (command)
		{
		case PUSH:
		{
			int value;
			std::cout << "		value >> ";
			std::cin >> value;
			Push(stack, value);
			break;
		}
		case POP:
			Pop(stack);
			break;
		case EXIT:
			isExit = true;
			break;
		default:
			std::cout << "It is not valiad option" << std::endl;
			break;
		}
		if (isExit == true)	// while문을 break해야 하기 때문에 flag를 만들어 줘야함
		{
			break;
		}
	}

}

void PrintStack(Stack& stack)
{
	std::cout << " <Stack> " << std::endl;
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is Empty" << std::endl;
		return;
	}
	int top = stack.topIndex;
	while (top != -1)
	{
		std::cout << stack.array[top--] << std::endl;
	}
	std::cout << "---------------";

}

void Push(Stack& stack, int value)
{
	if (stack.topIndex >= SIZE - 1)
	{
		std::cout << "Stack is already Full!!" << std::endl;
		return;
	}

	stack.array[++stack.topIndex] = value;
	std::cout << "Push : " << value << std::endl;
}

void Pop(Stack& stack)
{
	if (stack.topIndex < 0)
	{
		std::cout << "Stack is Empty!! You cannot pop the value out" << std::endl;
		return;
	}
	std::cout << "Pop : " << stack.array[stack.topIndex--] << std::endl;
}