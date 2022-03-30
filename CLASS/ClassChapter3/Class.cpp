#include "Class.h"
void Student::Print()
{
	
	std::cout << "Student Name : " << this->mName << " , " << "Student Sid : " << this->mSid << " , " 
		<< "Student grade : " << this->mGrade << std::endl;
}

void Student::SetInfo(std::string name, int sid, int grade)
{
	this->mName = name;
	this->mSid = sid;
	this->mGrade = grade;
}

int Student::GetGrade()
{

	return this->mGrade;
}

int StageClass::NumOfStudents = 10; // 정적 멤버변수

void StageClass::PrintAll()
{
	std::cout << this->mStage << "학년" << " - " << this->mClass << "반" << std::endl;
	for (int i = 0; i < NumOfStudents; ++i)
	{
		this->mStudents[i].Print();
	}
}

double StageClass::SumGrade()
{
	double Sum = 0;
	for (int i = 0; i < NumOfStudents; ++i)
	{
		Sum += this->mStudents[i].GetGrade();
	}
	std::cout << "Sum : " << Sum << std::endl;
	return Sum;
}

void StageClass::Init()
{
	

	std::string name;
	int sid;
	int grade;
	for (int i = 0; i < 10; ++i)
	{
		sid = i + 1;
		std::cout << "Name : ";
		std::cin >> name;
		std::cout << "Grade : ";
		std::cin >> grade;
		std::cout << "--------------------------" << std::endl;

		this->mStudents[i].SetInfo(name, sid, grade);

	}
}
