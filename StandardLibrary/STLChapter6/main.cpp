#include <iostream>
#include <vector>
#include <string>
class Student
{
public:
	int mNumber;
	std::string mName;
	int mScore;


	void Print() const
	{
		std::cout << "(" << mNumber << ")" << mName << " : " << mScore << std::endl;
	}
};

using Students = std::vector<Student>;

void AddStudent(Students& v)
{
	std::cout << "��ȣ , �̸� , ���� : ";

	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		auto itr = std::find_if(v.begin(), v.end(),
			[&](Student& e) //[&] �ܺ��� ������ ���������� �����ü��ִ�.
			{
				return e.mNumber == newStudent.mNumber;
			}
		);
		if (itr != v.end())
		{
			std::cout << "��ȣ�� �ߺ� �Ǿ����ϴ�" << std::endl;

		}
	/*	for (const auto& e : v)
		{
			if (e.mNumber == newStudent.mNumber)
			{
				std::cout << "��ȣ�� �ߺ� �Ǿ����ϴ� " << std::endl;
				return;
			}
		}*/
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "��ȣ : ";
	int number;
	if (std::cin >> number)
	{
		auto itr = std::remove_if(v.begin(), v.end(), 
			[&](Student& e)
			{
				return e.mNumber == number;
			}
		);
		if (itr == v.end()) // itr�� ���Ҹ� ��ã���� ���� nullptr�� �ƴ϶� v.end�� �ִ�.
		{
			std::cout << "�ش� ��ȣ�� �л��� �������� �ʽ��ϴ�" << std::endl;
		}
		/*for (auto itr = v.begin(); itr != v.end(); ++itr)
		{
			if (itr->mNumber == number)
			{
				v.erase(itr);
				return;
			}
		}*/
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;

	}
}

void Print(const Students& v)
{
	for (const auto& e : v)
	{
		e.Print() ;
	}
}

void PrintScoreInfo(const Students& v)
{
	int total{};
	for (const auto& e : v)
	{
		total += e.mScore;
	}

	std::cout << "Total : " << total << " , " << "Average : " << static_cast<float>(total) / v.size() << std::endl;
}

void PrintOverAverage(const Students& v)
{
	float average{};
	for (const auto& e : v)
	{
		average += e.mScore;
	}
	average = average / v.size();

	for (const auto& e : v)
	{
		if (e.mScore >= average)
		{
			e.Print();
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
	std::vector<Student> students{
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 50},
		{4, "Choi", 30}
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