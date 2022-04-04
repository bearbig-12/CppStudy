#pragma once
class Queue
{
	enum TYPES
	{
		ENQUEUE = 1,
		DEQUEUE,
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
	Element* mHead;
	Element* mTail;
	int mCount;
public:
	Queue()
	{
		mHead = mTail = nullptr;
		int mCount = 0;
	}
	~Queue()
	{
		Element* p = mHead;
		while (p != nullptr)
		{
			Element* pNext = p->pNext;
			delete p;
			p = pNext;
		}
		mTail = mHead = nullptr;
	}

	void QueueInfo();
	void UserInput(Queue& queue);
	void Enqueue(Queue& queue, int value);
	bool Dequeue(Queue& queue);
	void Print(const Queue& queue);
};

