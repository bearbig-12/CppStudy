#include <iostream>
#include <string>

// ���� ������

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

class ChiefProgrammer : public Programmer		// ���α׷����� Ư¡, �������� Ư�� �Ѵ� �����ؾ���.
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