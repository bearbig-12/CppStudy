#include <iostream>



int main()
{
	//4번 테트리스
	int Main_block[3][3]{
		{0, 1, 0},
		{0, 1, 1},
		{0, 1, 0}
	};

	std::cout << "[Welcome to Tetris Demo]" << std::endl;
	std::cout << "1 : Turn Left " << '\t';
	std::cout << "2 : Trun Right" << '\t';
	std::cout << "0 : Exit ";
	std::cout << std::endl;
	std::cout << std::endl;

	while (1)
	{

		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				std::cout << Main_block[row][col] << " ";
			}
			std::cout << std::endl;
		}

		int options;
		std::cout << "Please insert the number : " << std::endl;
		std::cin >> options;
		
		int temp_block[3][3]{};

		if (options == 0)
		{
			break;
		}
		/*if (!(std::cin >> options))
		{
			std::cout << "It is not valid type. Please try again" << std::endl;
			break;
		}*/
		if (!(options == 0) && !(options == 1) && !(options == 2))
		{
			std::cout << "It is not valid type. Please try again" << std::endl;
			break;
		}

		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				if (options == 1)
				{
					temp_block[2 - col][row] = Main_block[row][col];
				}
				else if (options == 2)
				{
					temp_block[col][2 - row] = Main_block[row][col];
				}

			}
			
		}

		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				Main_block[row][col] = temp_block[row][col];
			}
			
		}



	}

}