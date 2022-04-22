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
	std::cout << "번호 이름 점수 : ";
	Student newStudent;
	int number;

	if (std::cin >> number >> newStudent.mName >> newStudent.mScore)
	{
		auto result = v.insert({ number, newStudent });
		if (result.second == false)
		{
			std::cout << "중복된 학생 번호입니다 " << std::endl;
		}
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "지울 학생 번호 : ";
	int number;

	if (std::cin >> number)
	{
		if (v.erase(number) == 0)
		{
			std::cout << "없는 번호 입니다" << std::endl;
		}
		v.erase(number);
	}
	else
	{
		std::cout << "잘못된 입력입니다" << std::endl;
	}
}

void Print(const Students& v)
{
	for (const auto& e : v)
	{
		std::cout << "(" << e.first << ")" << " ";		// 번호
		e.second.Print();								// 학생 정보

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
	std::cout << " 1_학생 추가" << std::endl;
	std::cout << " 2_학생 제거" << std::endl;
	std::cout << " 3_전체 학생 출력" << std::endl;
	std::cout << " 4_클래스 평균 및 총점" << std::endl;
	std::cout << " 5_클래스 평균 이상 학생 목록" << std::endl;
	std::cout << " 6_종료" << std::endl;
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
			std::cout << "잘못된 명령어 입니다!!" << std::endl;
			break;

		}
		if (IsStop == true)
		{
			break;
		}

	}
}