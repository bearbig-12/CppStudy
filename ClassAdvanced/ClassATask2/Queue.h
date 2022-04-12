#pragma once
#include "LinkedList.h"
class Queue :
    public LinkedList
{
public:
	Queue();
	~Queue() override;
	
public:
	void UserInput(LinkedList& list) override;
private:
	void PrintInfo(LinkedList& list) override;
	void Create(LinkedList& list, int value) override;
	bool Delete(LinkedList& list) override;
	void Print(const LinkedList& list) const override;
};

