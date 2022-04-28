#include <iostream>
#include <vector>
#include "Monster.h"


// 파일 입출력 with binary


std::ifstream& operator >> (std::ifstream& ifs, Monster& monster)
{
	return monster.ReadBinary(ifs);
}

std::ofstream& operator << (std::ofstream& ofs, Monster& monster)
{
	return monster.WriteBinary(ofs);
}

struct Header
{
	int version{ 1 };
	int monsterCount{};

};

bool SaveToFile(const std::string& filename, std::vector<Monster>& monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	try
	{
		ofs.open(filename, std::ofstream::binary);

		Header h{ 1, monsters.size() };

		ofs.write(reinterpret_cast<char*>(&h), sizeof(Header));


		for ( auto& e : monsters)
		{
			ofs << e;
		}

	}
	catch (std::ofstream::failure e)
	{
		std::cout << "저장 도중 예외가 발생 : " << e.what() << " : " << e.code() << std::endl;
		ofs.close();
		return false;
	}
	return true;

}
bool LoadFromFile(const std::string& filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::badbit);

	try
	{
		ifs.open(filename, std::ifstream::binary);
		Header h;
		ifs.read(reinterpret_cast<char*>(&h), sizeof(Header));
		for (int i = 0; i < h.monsterCount; ++i)
		{
			Monster m;
			ifs >> m;
			monsters.push_back(m);
		}
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "읽기 도중에 예외가 발생" << e.what() << std::endl;
		ifs.close();
		return false;
	}
	return true;
}

int main()
{
	std::vector<Monster> monsters
	{
		{"Jelly", 1,1,1},
		{"Wolf", 5,5,5},
		{"Demon", 5,5,5}
		
	};

	SaveToFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt", monsters);

	monsters.clear();

	LoadFromFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt", monsters);

	//test
	/*std::ofstream ofs;
	ofs.open("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt", std::ofstream::binary);
	for (auto& e : monsters)
	{
		ofs << e;
	}
	ofs.close();*/
}