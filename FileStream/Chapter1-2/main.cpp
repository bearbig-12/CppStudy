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
	// 1. ��Ʈ�� ��ü
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit);

	try
	{
		// 2. ���� ����
		ifs.open(filename);
		// 3. ���� �۾�
		std::string buffer;
		// ��� �а� ������
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
		// 4. ���� �ݱ�
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "������ �߸��Ǿ����ϴ�" << std::endl;
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
		std::cout << " ���� ���� ���� ������ �߻��߽��ϴ�." << std::endl;
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

		std::getline(is, buffer);	// ���̴ϱ� ��ǥ ���� �д°� �ƴ� ������ ������ �ȴ�.
		monster.mMP = std::stoi(buffer);

	}
	catch (std::exception e)
	{
		std::cout << "������ ������ �߸��Ǿ����ϴ� !" << std::endl;
		std::cout << e.what() << std::endl;
	}

	return is;
}
