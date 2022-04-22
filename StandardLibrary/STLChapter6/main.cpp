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
	std::cout << "번호 , 이름 , 점수 : ";

	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		auto itr = std::find_if(v.begin(), v.end(),
			[&](Student& e) //[&] 외부의 변수를 참조형으로 가져올수있다.
			{
				return e.mNumber == newStudent.mNumber;
			}
		);
		if (itr != v.end())
		{
			std::cout << "번호가 중복 되었습니다" << std::endl;

		}
	/*	for (const auto& e : v)
		{
			if (e.mNumber == newStudent.mNumber)
			{
				std::cout << "번호가 중복 되었습니다 " << std::endl;
				return;
			}
		}*/
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void RemoveStudent(Students& v)
{
	std::cout << "번호 : ";
	int number;
	if (std::cin >> number)
	{
		auto itr = std::remove_if(v.begin(), v.end(), 
			[&](Student& e)
			{
				return e.mNumber == number;
			}
		);
		if (itr == v.end()) // itr가 원소를 못찾았을 경우는 nullptr이 아니라 v.end에 있다.
		{
			std::cout << "해당 번호의 학생이 존재하지 않습니다" << std::endl;
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
		std::cout << "잘못된 입력입니다." << std::endl;

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
	std::cout << " 1_학생 추가" << std::endl;
	std::cout << " 2_학생 제거" << std::endl;
	std::cout << " 3_전체 학생 출력" << std::endl;
	std::cout << " 4_클래스 평균 및 총점" << std::endl;
	std::cout << " 5_클래스 평균 이상 학생 목록" << std::endl;
	std::cout << " 6_종료" << std::endl;
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
			std::cout << "잘못된 명령어 입니다!!" << std::endl;
			break;

		}
		if (IsStop == true)
		{
			break;
		}

	}
}