#include <iostream>



class Image
{
public:
	~Image()
	{
		std::cout << "[-Image]" << std::endl;

	}
};

class Bug
{
	std::shared_ptr<Image> mspImage;

public:
	Bug(std::shared_ptr<Image> image)
	{
		mspImage = image;
		std::cout << "[+Bug]" << std::endl;
	}
	~Bug()
	{
		std::cout << "[-Bug]" << std::endl;
	}
};

int main()
{
	std::shared_ptr<Image> spImage{ std::make_shared<Image>() };

	{
		auto spBug1 = std::make_unique<Bug>(spImage);
		std::cout << spImage.use_count() << std::endl;
		{
			auto spBug2 = std::make_unique<Bug>(spImage);
			std::cout << spImage.use_count() << std::endl;
			{
				auto spBug3 = std::make_unique<Bug>(spImage);
				std::cout << spImage.use_count() << std::endl;
			}
			std::cout << spImage.use_count() << std::endl;

		}
		std::cout << spImage.use_count() << std::endl;

	}
	std::cout << spImage.use_count() << std::endl;

}