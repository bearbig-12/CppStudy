#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>

class Sprite
{
public:
	std::string n;
	int			x;
	int			y;
	int			w;
	int			h;


};

void LoadXML(const std::string& filename, std::vector<Sprite>& sprites)
{
	std::ifstream file(filename, std::ifstream::binary);

	std::string line;
	std::regex pattern("\"([^\"]*)\"");
	while (!file.eof())
	{
		std::getline(file, line);

		auto reuslt = line.find("<sprite");
		if (reuslt != std::string::npos)
		{
			std::sregex_iterator current(line.begin(), line.end(),pattern);
			std::sregex_iterator end;

			int index{};
			Sprite sprite;
			while (current != end)
			{
				std::string token = (*current)[1];

				switch (index)
				{
				case 0:
					sprite.n = token;
					break;
				case 1:
					sprite.x = std::stoi(token);
					break;
				case 2:
					sprite.y = std::stoi(token);
					break;
				case 3:
					sprite.w = std::stoi(token);
					break;
				case 4:
					sprite.h = std::stoi(token);
					break;
		
				}

				current++;
				index++;
			}
			sprites.push_back(sprite);
		}

	}
}

int main()
{
	std::vector<Sprite> sprites;

	LoadXML("Data/MyData.xml", sprites);
}