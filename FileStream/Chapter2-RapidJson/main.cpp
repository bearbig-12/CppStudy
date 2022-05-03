#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <vector>
#include "monster.h"

using namespace rapidjson;

bool LoadFromJson(const char* filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;

	
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::stringstream ss;

	try
	{
		ifs.open(filename);
		ss << ifs.rdbuf();

		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "파일을 읽는 도중에 문제가 발생했습니다" << e.what() << " : " << e.code() << std::endl;
		ifs.close();
		return false;
	}

	Document d;
	d.Parse(ss.str().c_str());

	for (const auto& e : d["monsters"].GetArray())
	{
		//std::cout << e["name"].GetString() << std::endl;

		Monster monster;
		monster.SetName(e["name"].GetString());

		Status status;
		auto statobj = e["status"].GetObject();
		status.mLevel = statobj["level"].GetInt();
		status.mHP = statobj["hp"].GetInt();
		status.mMP = statobj["mp"].GetInt();

		monster.SetStatus(status);

		for (const auto& item : e["items"].GetArray())
		{
			Item tempItem;
			tempItem.mName = item["name"].GetString();
			tempItem.mGold = item["gold"].GetInt();

			monster.AddItem(tempItem);
		}
		monsters.push_back(monster);
	}
	return true;
}

int main()
{
	std::vector<Monster> monsters;

	LoadFromJson("Data/monsters.json", monsters);
}