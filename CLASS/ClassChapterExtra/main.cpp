#include <iostream>
#include <string>

// 게임 개발자

class Developer
{
public:
	std::string name;
	int mAge;
};

class Programmer : public Developer
{

public:
	void Coding();
	void Debugging();

};

class ChiefProgrammer : public Programmer		// 프로그래머의 특징, 개발자의 특성 둘다 보유해야함.
{
public:
	void Architecture();
	void Scheduling();
};

class Designer : public Developer
{
public:
	void Documentation();
	void Presentation();
};

class ChiefDesigner : public Designer
{
public:
	void Meeting();
	void Scheduling();
};