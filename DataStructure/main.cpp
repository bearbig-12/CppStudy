#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
int main()
{
	//Stack & Queue
	{
		//Stack mstack;
		//Queue mqueue;

		//PrintStackInfo();
		//StackUserInput(mstack);

		//PrintQueueInfo();
		//QueueUserInput(mqueue);
	}


	// SingleLinkedList
	{
		//MonsterList myList;
		//CreateMonster(myList, "Wolf", 10);
		//CreateMonster(myList, "Slime", 20);
		//CreateMonster(myList, "Demon", 30);

		//std::cout << GetCountMonsterList(myList) << std::endl;
		////PrintMonsterList(myList);
		////PrintRecursive(myList.pHead);
		//std::cout << ((FindMonster(myList, "Slime") == nullptr) ? "Not found" : "Found") << std::endl;
		//Delete(myList, "Slime");
		//Delete(myList, "Demon");
		//Delete(myList, "Wolf");

		//PrintMonsterList(myList);
	}

	//DoubleLinkedList
	{
		MonsterList2 myList2;
		CreateMonster(myList2, "Wolf", 10);
		CreateMonster(myList2, "Slime", 20);
		CreateMonster(myList2, "Demon", 30);
		std::cout << GetCountMonsterList(myList2) << std::endl;
		PrintMonsterList(myList2);
		PrintRecursive(myList2.pHead);
		std::cout << ((FindMonster(myList2, "Slime") == nullptr) ? "Not found" : "Found") << std::endl;

		Delete(myList2, "Slime");
		Delete(myList2, "Demon");
		Delete(myList2, "Wolf");

		PrintMonsterList(myList2);
	}
}