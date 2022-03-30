#pragma once
#include <string>
#include <iostream>

class Student
{
private:
	std::string mName;
	int mSid;
	int mGrade;
public:
	Student()
	{
		mName = "";
		mSid = 0;
		mGrade = 0;
	}
	Student(std::string name, int sid, int grade) : mName{ name }, mSid{ sid }, mGrade{ grade }
	{

	}
	~Student() {}
	void Print();
	void SetInfo(std::string name, int sid, int grade);
	int GetGrade();
};


class StageClass
{
private:
	int mStage;
	int mClass;
	static int NumOfStudents;
	Student mStudents[10];
public:
	StageClass(int stage, int mclass) : mStage{stage}, mClass{mclass}
	{
		
	}
	~StageClass() 
	{
		
	};

	void Init();
	void PrintAll();
	double SumGrade();
};



