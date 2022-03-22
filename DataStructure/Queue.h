#pragma once
#include <iostream>

enum QueCommand
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	Q_EXIT = 3
};

const int QSIZE = 10;

struct Queue
{
	int array[QSIZE];
	int head{ 0 };
	int tail{ 0 };
};

void PrintQueueInfo()
{
	std::cout << "<Queue>" << std::endl;
	std::cout << "[1] EnQueue" << std::endl;
	std::cout << "[2] DeQueue" << std::endl;
	std::cout << "[3] Exit" << std::endl;
	std::cout << "----------------" << std::endl;
}

void PrintQueue(Queue& queue)
{
	std::cout << "<QUEUE>" << std::endl;
	if (queue.head == queue.tail)
	{
		std::cout << "Queue IS EMPTY" << std::endl;
		return;
	}
	std::cout << std::endl;

	int head = queue.head;
	while (head != queue.tail)
	{
		head = (head + 1) % QSIZE;
		std::cout << queue.array[head] << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
}

void EnQueue(Queue& queue, int value)
{
	if ((queue.tail + 1) % QSIZE == queue.head)
	{
		std::cout << "Queue is already Full!!" << std::endl;
		return;
	}
	queue.tail = (queue.tail + 1) % QSIZE;
	queue.array[queue.tail] = value;
	std::cout << "EnQueue : " << value << std::endl;
}

void DeQueue(Queue& queue)
{
	if (queue.tail == queue.head)
	{
		std::cout << "Queue is Empty" << std::endl;
		return;
	}
	queue.head = (queue.head + 1) % QSIZE;
	std::cout << "DeQeue : " << queue.array[queue.head] << std::endl;
}

void QueueUserInput(Queue& queue)
{
	int command{};
	bool isExit{ false };

	while (true)
	{
		PrintQueue(queue);
		std::cout << std::endl;
		std::cout << "Please insert your option : ";
		std::cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "		value >> ";
			std::cin >> value;
			EnQueue(queue, value);
			break;
		}
		case DEQUEUE:
			DeQueue(queue);
			break;
		case Q_EXIT:
			isExit = true;
			break;
		default:
			std::cout << "It is not valiad option" << std::endl;
			break;
		}
		if (isExit == true)	// while문을 break해야 하기 때문에 flag를 만들어 줘야함
		{
			break;
		}
	}

}