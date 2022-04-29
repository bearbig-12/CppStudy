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

void LoadXML(const std::string& filename, std::vector<Sprite>& sprite)
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
			while (current != end)
			{
				std::cout << (*current)[1] << " ";
				current++;
			}
			std::cout << line << std::endl;
		}

	}
}

int main()
{
	std::vector<Sprite> sprites;

	LoadXML("Data/MyData.xml", sprites);
}