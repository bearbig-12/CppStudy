#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "SingleLinkedList.h"
int main()
{
	//Stack mstack;
	//Queue mqueue;

	//PrintStackInfo();
	//StackUserInput(mstack);

	//PrintQueueInfo();
	//QueueUserInput(mqueue);

	MonsterList myList;
	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 20);
	CreateMonster(myList, "Demon", 30);

	std::cout << GetCountMonsterList(myList) << std::endl;
	//PrintMonsterList(myList);
	//PrintRecursive(myList.pHead);
	std::cout <<((FindMonster(myList,"Slime") == nullptr) ? "Not found" : "Found") << std::endl;
}