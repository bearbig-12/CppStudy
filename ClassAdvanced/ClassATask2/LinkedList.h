#pragma once
class LinkedList
{
protected:

	enum LIST_OPTIONS
	{
		ADD = 1,
		DELETE = 2,
		STOP,
		FIND
		
	};
	class Element
	{
	public:
		int mValue;
		Element* mpNext;
		Element* mpPrev; // for double and Queue
		Element()
		{
			mValue = 0;
			mpNext = mpPrev = nullptr;
		}
	};
	Element* mpHead;
	Element* mpTail;
	int mCount;
public:
	LinkedList()
	{
		mpHead = mpTail = nullptr;
		mCount = 0;
	}
	virtual ~LinkedList()
	{
		Element* p{ mpHead };

		while (p != nullptr)
		{
			Element* pNext = p->mpNext;
			delete p;
			p = pNext;
		}
		mpHead = mpTail = nullptr;
		mCount = 0;
	}
public:
	virtual void UserInput(LinkedList& list);
	
protected:
	virtual void Create(LinkedList& list, int value);
	virtual bool Delete(LinkedList& list);
	virtual void Print(const LinkedList& list) const;
	virtual void PrintInfo(LinkedList& list);
private:
	Element* Find(LinkedList& list, int value);
	bool Find_Delete(LinkedList& list, int value);

};

