#pragma once
#include "LinkedList.h"
class DynamicStack :
    public LinkedList
{
public:
    DynamicStack();
    ~DynamicStack() override;

	void PrintInfo(LinkedList& list) override;
	void UserInput(LinkedList& list) override;
	void Push(LinkedList& list, int value) override;
	bool Pop(LinkedList& list) override;
	void Print(const LinkedList& list) const override;

};

