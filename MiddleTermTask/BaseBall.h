#pragma once
#include <iostream>
#include <random>

int GetRandom()
{
	int Answer_Number{0};
	int temp;
	int array[3]{0};
	std::random_device rd; // 시드값을 얻기 위한 random_device

	std::mt19937 gen(rd()); // random_device 를 통해 난수 생성 엔진 초기화

	std::uniform_int_distribution<int> dis(100, 999);  
	Answer_Number = dis(gen);	// 3자리 정수 
	temp = Answer_Number;
	//각자리 숫자가 중복되는지 확인
	for (int i = 2; i >= 0; --i)	
	{
		array[i] = temp % 10;
		temp /= 10;
	}
	if (array[0] == array[1] || array[1] == array[2] || array[0] == array[2])	// 각자리에 중복 되는 숫자가 있을시 난수 다시 만들기.
	{
		return GetRandom();
	}


	
	return Answer_Number;
	
}

void Input(int answer)
{
	int Answer_Number[3]{};

	for (int i = 2; i >= 0; --i)
	{
		Answer_Number[i] = answer % 10;
		answer /= 10;
	}

	while(1)
	{
		int input;
		int player_answer[3]{ 0 };

		int strike = 0;
		int ball = 0;
		

		std::cout << "Please Insert 3 numbers" << std::endl;
		
		std::cout << "Player number : ";
		std::cin >> input;

		for (int i = 2; i >= 0; --i)
		{
			player_answer[i] = input % 10;
			input /= 10;
		}

		std::cout << std::endl;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i == j && player_answer[i] == Answer_Number[j])
				{
					//스트라이크
					++strike;
				}
				else if (i != j && player_answer[i] == Answer_Number[j])
				{
					//볼
					++ball;
				}
				else if( i == 2 && j == 2)
				{
					//아웃
					std::cout << " Out " << std::endl;
				}
			}
		}
		
		if (strike == 3)
		{
			std::cout << " 3 Strike!!! You Win!!! " << std::endl;
			break;
		}
		else
		{
			std::cout << "Strike : " << strike << " , " << "Ball : " << ball << std::endl;
		}
		
		
	}
}