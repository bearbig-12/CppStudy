#pragma once
class LinkedList 
{
protected:
	enum TYPE 
	{
		ADD = 1,
		DELETE = 2,
		STOP = 3,
	
	};

	class Element
	{
	public:
		int mValue;
		Element* mpNext;
	public:
		Element()
		{
			mValue = 0;
			mpNext = nullptr;
		}
	};

	Element* mpFirst; // for Queue
	Element* mpTail;
	int mCount;
public:
	LinkedList();
	virtual ~LinkedList();

	virtual void PrintInfo(LinkedList& list) = 0;
	virtual void UserInput(LinkedList& list) = 0;
	virtual void Push(LinkedList& list, int value) = 0;
	virtual bool Pop(LinkedList& list) = 0;
	virtual void Print(const LinkedList& list) const = 0;
};

