#pragma once
class Stack
{
private:
	enum TYPES
	{
		PUSH = 1,
		POP,
		STOP
	};

	class Element
	{
	public:
		Element* pNext;
		int mValue;
		Element()
		{
			pNext = nullptr;
			mValue = 0;
		}
	};

	Element* mTail;
	int mCount;

public:
	Stack()
	{
		mCount = 0;
		mTail = nullptr;
	}
	~Stack()
	{
		Element* element = mTail;
		Element* Next{};
		while (element != nullptr)
		{
			Next = element->pNext;
			delete element;

			element = Next;
		}
		mTail = nullptr;
	}

	void StackInfo();
	void UserInput(Stack& stack);
	void Push(Stack& stack, int value);
	bool Pop(Stack& stack);
	void Print(const Stack& stack);
};

