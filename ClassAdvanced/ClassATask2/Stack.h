#pragma once
#include "LinkedList.h"
class Stack :
    public LinkedList
{
public:
	Stack();
	~Stack() override;
public:
	void UserInput(LinkedList& list) override;

private:
	void PrintInfo(LinkedList& list) override;
	void Create(LinkedList& list, int value) override;
	bool Delete(LinkedList& list) override;
	void Print(const LinkedList& list) const override;
};

