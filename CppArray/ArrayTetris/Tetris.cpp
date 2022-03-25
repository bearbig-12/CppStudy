#include <iostream>



int main()
{
	//4번 테트리스
	//int Main_block[3][3]{
	//	{0, 1, 0},
	//	{0, 1, 1},
	//	{0, 1, 0}
	//};

	//std::cout << "[Welcome to Tetris Demo]" << std::endl;
	//std::cout << "1 : Turn Left " << '\t';
	//std::cout << "2 : Trun Right" << '\t';
	//std::cout << "0 : Exit ";
	//std::cout << std::endl;
	//std::cout << std::endl;

	//while (1)
	//{

	//	for (int row = 0; row < 3; ++row)
	//	{
	//		for (int col = 0; col < 3; ++col)
	//		{
	//			std::cout << Main_block[row][col] << " ";
	//		}
	//		std::cout << std::endl;
	//	}

	//	int options;
	//	std::cout << "Please insert the number : " << std::endl;
	//	std::cin >> options;
	//	
	//	int temp_block[3][3]{};

	//	if (options == 0)
	//	{
	//		break;
	//	}
	//	/*if (!(std::cin >> options))
	//	{
	//		std::cout << "It is not valid type. Please try again" << std::endl;
	//		break;
	//	}*/
	//	if (!(options == 0) && !(options == 1) && !(options == 2))
	//	{
	//		std::cout << "It is not valid type. Please try again" << std::endl;
	//		break;
	//	}

	//	for (int row = 0; row < 3; ++row)
	//	{
	//		for (int col = 0; col < 3; ++col)
	//		{
	//			if (options == 1)
	//			{
	//				temp_block[2 - col][row] = Main_block[row][col];
	//			}
	//			else if (options == 2)
	//			{
	//				temp_block[col][2 - row] = Main_block[row][col];
	//			}

	//		}
	//		
	//	}

	//	for (int row = 0; row < 3; ++row)
	//	{
	//		for (int col = 0; col < 3; ++col)
	//		{
	//			Main_block[row][col] = temp_block[row][col];
	//		}
	//		
	//	}



	//}


	int block[3][3]{    //행(row) 렬(column) 만약(x,y) 식의 좌표로 나타낼시 행(row) = y 렬(column) = x
		{0, 1, 0},
		{0, 1, 1},
		{0, 1, 0}
	};

	int newX = 0;
	int newY = 0;

	int Rot_block[3][3]{ 0 };

	std::cout << " << 테트리스 블럭 회전 >> " << std::endl;
	std::cout << " 1 : 왼쪽 회전, 2 : 오른쪽 회전, 3 : 종료" << std::endl;
	while (true)
	{
		// 블럭 출력
		for (int row = 0; row < 3; ++row)
		{
			for (int col = 0; col < 3; ++col)
			{
				std::cout << block[row][col] << " ";
			}
			std::cout << std::endl;
		}
		//입력
		int rotate{};
		std::cout << " 회전 방향? ";
		std::cin >> rotate;

		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				if (rotate == 1)
				{
					//좌회전
					newX = y;
					newY = 2 - x;
				}
				else if (rotate == 2)
				{
					//우회전
					newX = 2 - y;
					newY = x;
				}
				Rot_block[newY][newX] = block[y][x];
			}

		}

		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				block[y][x] = Rot_block[y][x];
			}
		}

		if (rotate == 3)
		{
			break;
		}
		
	}

}