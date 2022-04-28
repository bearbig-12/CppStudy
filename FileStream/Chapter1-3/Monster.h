#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;
public:
	Monster() : mName{}, mLevel{}, mHP{}, mMP{}
	{

	}
	Monster(std::string name, int level, int hp, int mp) : mName{name}, mLevel{level}, mHP{hp}, mMP{mp}
	{

	}


	std::ifstream& ReadBinary(std::ifstream& ifs);
	std::ofstream& WriteBinary(std::ofstream& ofs); 
};

