#include <iostream>
#include <vector>
#include <fstream>
#include <exception>
#include <sstream>
class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;

public:
	Monster()
	{
		mName = "";
		mLevel = 0;
		mHP = 0;
		mMP = 0;
	}
	Monster(std::string name, int level, int hp, int mp) : mName{ name }, mLevel{ level }, mHP{ hp }, mMP{ mp }
	{

	}

	void SetName(std::string name) { mName = name; }
	void SetLevel(int level) { mLevel = level; }
	void SetHP(int hp) { mHP = hp; }
	void SetMP(int mp) { mMP = mp; }

	friend std::ostream& operator<<(std::ostream& ostream, Monster& monster);
	friend std::istream& operator>> (std::istream& is, Monster& monster);

};



bool CreateFromFile(const std::string& filename, std::vector<Monster>& v)
{
	// 1. 스트림 객체
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		// 2. 파일 열기
		ifs.open(filename);
		// 3. 파일 작업
		std::string buffer;
		// 헤더 읽고 버리기
		std::getline(ifs, buffer);

		while (!ifs.eof())
		{
			Monster m;

			
		/*	std::getline(ifs, buffer, ',');
			m.SetName(buffer);

			std::getline(ifs, buffer, ',');
			m.SetLevel(std::stoi(buffer));

			std::getline(ifs, buffer, ',');
			m.SetHP(std::stoi(buffer));

			std::getline(ifs, buffer);
			m.SetMP(std::stoi(buffer));*/
			ifs >> m;

			v.push_back(m);
			//std::cout << buffer << std::endl;
		}
		// 4. 파일 닫기
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "파일이 잘못되었습니다" << std::endl;
		ifs.close();
		return false;
	}
	return true;
}

bool SaveFile(const std::string& filename, std::vector<Monster> monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit);

	try
	{
		ofs.open(filename);

		ofs << "--Monster data--" << std::endl;
		for (auto& e : monsters)
		{
			ofs << e;
		}
		ofs.close();
	}
	catch (std::exception e)
	{
		std::cout << " 파일 저장 도중 오류가 발생했습니다." << std::endl;
		std::cout << e.what() << std::endl;
		ofs.close();
		return false;
	}


	return true;
}

int main()
{
	std::vector<Monster> monsters;
	
	

	CreateFromFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt", monsters);
	monsters.push_back({ "ORC",20,20,20 });

	SaveFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt", monsters);

	for (auto& e : monsters)
	{
		std::cout << e;
	}
}

std::ostream& operator<<(std::ostream& ostream, Monster& monster)
{
	ostream << monster.mName << "," <<
			monster.mLevel << "," <<
			monster.mHP << "," <<
			monster.mMP << std::endl;
	

	return ostream;
}

std::istream& operator >> (std::istream& is, Monster& monster)
{
	std::string buffer;
	try
	{
		std::getline(is, buffer, ',');
		monster.mName = buffer;

		std::getline(is, buffer, ',');
		monster.mLevel = std::stoi(buffer);

		std::getline(is, buffer, ',');
		monster.mHP = std::stoi(buffer);

		std::getline(is, buffer);	// 끝이니까 쉼표 까지 읽는게 아닌 한줄을 읽으면 된다.
		monster.mMP = std::stoi(buffer);

	}
	catch (std::exception e)
	{
		std::cout << "데이터 형식이 잘못되었습니다 !" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return is;
}
