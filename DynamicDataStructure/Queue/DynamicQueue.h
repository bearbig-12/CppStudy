#pragma once
enum TYPE
{
	mENQUEUE = 1,
	mDEQUEUE = 2,
	mSTOP = 3
};

struct Element
{
	int value{ 0 };
	Element* pNext{ nullptr };
};

struct Queue
{
	int Count{ 0 };
	Element* pTail{ nullptr };
	Element* pHead{ nullptr };
};

void UserInput(Queue& queue);
void Enqueue(Queue& queue, int value);
bool Dequeue(Queue& queue);
void Print(Queue& queue);