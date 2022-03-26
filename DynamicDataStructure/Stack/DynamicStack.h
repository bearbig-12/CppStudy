#pragma once
enum TYPE
{
	mPUSH = 1,
	mPOP = 2,
	mSTOP = 3
};

struct Element
{
	int value{0};
	Element* pPrev{nullptr};
};

struct Stack
{
	int Count{0};
	Element* pTail{ nullptr };
};

void UserInput(Stack& stack);
void Push(Stack& stack, int value);
bool Pop(Stack& stack);
void Print(Stack& stack);