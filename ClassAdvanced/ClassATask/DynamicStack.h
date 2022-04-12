#pragma once
#include "LinkedList.h"
class DynamicStack :
    public LinkedList
{
public:
    DynamicStack();
    ~DynamicStack() override;
public:
	void UserInput(LinkedList& list) override;
private:
	void PrintInfo(LinkedList& list) override;
	void Push(LinkedList& list, int value) override;
	bool Pop(LinkedList& list) override;
	void Print(const LinkedList& list) const override;

};

