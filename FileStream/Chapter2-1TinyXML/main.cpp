#include <iostream>
#include "monster.h"
#include "tinyxml2.h"

using namespace tinyxml2;

bool LoadFromXML(std::string filename, std::vector<Monster>& monsters)
{
	XMLDocument doc;

	if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
	{
		std::cout << "Cannot find the file!" << filename << std::endl;
		return false;
	}
	auto pRootNode = doc.FirstChildElement("monsters");

	for (auto pMonsterNode = pRootNode->FirstChildElement();
		pMonsterNode;
		pMonsterNode = pMonsterNode->NextSiblingElement())
	{
		//std::cout << pMonsterNode->Attribute("name") << std::endl; // 확인용 출력
		Monster monster;
		
		monster.SetName(pMonsterNode->Attribute("name"));

		Status status;
		auto pStatusNode = pMonsterNode->FirstChildElement("status");
		status.mLevel = pStatusNode->IntAttribute("level");
		status.mHP = pStatusNode->IntAttribute("hp");
		status.mMP = pStatusNode->IntAttribute("mp");
		monster.SetStatus(status);

		// auto = XMLElement*

		auto pItemsNode = pMonsterNode->FirstChildElement("items");
		for (auto pItemNode = pItemsNode->FirstChildElement();
			pItemNode != nullptr;
			pItemNode = pItemNode->NextSiblingElement())
		{
			Item item;
			item.mName = pItemNode->Attribute("name");
			item.mGold = pItemNode->IntAttribute("gold");

			monster.AddItem(item);
		}
		monsters.push_back(monster);
	}

	return true;
}

int main()
{
	std::vector<Monster> monsters;

	LoadFromXML("Data/MyData.xml", monsters);
}