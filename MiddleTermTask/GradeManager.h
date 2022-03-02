#pragma once


#include <iostream>
#include <string>

//2. �����θ� �����ϴ� ���α׷��� ����� ���ô�.
//��, ���� �ݿ� �л��� ������ ���� 5���� �ֽ��ϴ�.
//1 KIM 100
//2 LEE 90
//3 PARK 70
//4 CHOI 95
//5 KANG 80
//------------------------------------------------ -
//
//1. ���
//2. �˻�
//3. ����
//4. �ְ���
//5. ������
//6. ����

enum Options
{
	AVERAGE = 1,
	FIND,
	SORT,
	HIGH,
	LOW,
	STOP
};

struct Student_Data
{
	int number;
	std::string name;
	int grade;
};

void GradeManager(Student_Data arr[])
{
	std::cout << "Option List : ";
	std::cout << "1. Average, 2. Find, 3. Sort, 4. Highest Grade, 5. Lowest Grade, 6.Stop" << std::endl;

	while (true)
	{
		
		int sum = 0;
		int input;
		std::cout << "Option : ";
		std::cin >> input;

		int max = arr[0].grade;
		int min = arr[0].grade;

		switch (input)
		{
		case AVERAGE:
			
			for (int i = 0; i < 5; ++i)
			{
				sum += arr[i].grade;
			}
			std::cout << "Average : " << sum/5 << std::endl;
			break;
		case FIND:
			int s_number;
			std::cout << "Please insert the stundet number : ";
			std::cin >> s_number;
			for (int i = 0; i < 5; ++i)
			{
				if (s_number == arr[i].number)
				{
					std::cout << arr[i].number << " " << arr[i].name << " " << arr[i].grade << std::endl;
				}
				
			}
			break;
		case SORT:
			for (int i = 0; i < 4; ++i)
			{
				
				for (int j = i + 1; j < 5; ++j)
				{
					if (arr[j].grade < arr[i].grade)
					{
						Student_Data temp{};

						temp = arr[j];
						arr[j] = arr[i];
						arr[i] = temp;
						
					}
				}
			}

			for (int i = 0; i < 5; ++i)
			{
				std::cout << arr[i].number << " " << arr[i].name << " " << arr[i].grade << std::endl;
			}

			break;
		case HIGH:
			for (int i = 0; i < 5; ++i)
			{
				if (max < arr[i].grade)
				{
					max = arr[i].grade;
				}
			}

			std::cout << " Highest Grade : " << max << std::endl;
			
			break;
		case LOW:
			for (int i = 0; i < 5; ++i)
			{
				if (min > arr[i].grade)
				{
					min = arr[i].grade;
				}
			}
			std::cout << "������ : " << min << std::endl;
			break;
		case STOP:
			return;
		default:
			std::cout << "Not valid Option" << std::endl;
			break;
		}
	}
}
