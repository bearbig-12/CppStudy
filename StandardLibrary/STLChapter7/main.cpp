#include <iostream>
#include <map>
#include <string>
class Student
{
public:
	std::string mName;
	int mScore;


	void Print() const
	{
		std::cout  << mName << " : " << mScore << std::endl;
	}
};

using Students = std::map<int, Student>;
void AddStudent(Students& v)
{
	std::cout << "��ȣ �̸� ���� : ";
	Student newStudent;
	int number;

	if (std::cin >> number >> newStudent.mName >> newStudent.mScore)
	{
		auto result = v.insert({ number, newStudent });
		if (result.second == false)
		{
			std::cout << "�ߺ��� �л� ��ȣ�Դϴ� " << std::endl;
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "���� �л� ��ȣ : ";
	int number;

	if (std::cin >> number)
	{
		if (v.erase(number) == 0)
		{
			std::cout << "���� ��ȣ �Դϴ�" << std::endl;
		}
		v.erase(number);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�" << std::endl;
	}
}

void Print(const Students& v)
{
	for (const auto& e : v)
	{
		std::cout << "(" << e.first << ")" << " ";		// ��ȣ
		e.second.Print();								// �л� ����

	}
}

void PrintScoreInfo(const Students& v)
{
	float total{};

	for (auto& e : v)
	{
		total += e.second.mScore;
	}
	std::cout << "Total  : " << total << ", Average : " << total / v.size() << std::endl;
}

void PrintOverAverage(const Students& v)
{
	float average{};
	for (auto& e : v)
	{
		average += e.second.mScore;
	}
	average /= v.size();

	for (const auto& e : v)
	{
		if (e.second.mScore >= average)
		{
			std::cout << "(" << e.first << ")";
			e.second.Print();
		}
	}
}

void PrintInfo()
{
	std::cout << " 1_�л� �߰�" << std::endl;
	std::cout << " 2_�л� ����" << std::endl;
	std::cout << " 3_��ü �л� ���" << std::endl;
	std::cout << " 4_Ŭ���� ��� �� ����" << std::endl;
	std::cout << " 5_Ŭ���� ��� �̻� �л� ���" << std::endl;
	std::cout << " 6_����" << std::endl;
}


int main()
{
	Students students{
		{1, {"Kim", 80}},
		{2, {"Lee", 20}},
		{3, {"Park", 50}},
		{4, {"Choi", 30}}
	};

	bool IsStop = false;
	int command{};
	while (command != 6)
	{
		PrintInfo();
		std::cout << ">	";
		std::cin >> command;
		switch (command)
		{
		case 1:
			AddStudent(students);
			break;

		case 2:
			RemoveStudent(students);
			break;

		case 3:
			Print(students);
			break;

		case 4:
			PrintScoreInfo(students);
			break;

		case 5:
			PrintOverAverage(students);
			break;

		case 6:
			IsStop = true;
			break;

		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�!!" << std::endl;
			break;

		}
		if (IsStop == true)
		{
			break;
		}

	}
}