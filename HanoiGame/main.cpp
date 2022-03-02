#include <iostream>


struct Hanoi
{
	static int A_dics;	// Number of discs
	static int B_dics;
	static int C_dics;

	static int base_tower[3][3];


};



int Hanoi::A_dics = 3;
int Hanoi::B_dics = 0;
int Hanoi::C_dics = 0;
int Hanoi::base_tower[3][3]
{
	{ 1, 0, 0 },
	{ 2,0,0 },
	{ 3,0,0 },
};


void Print_Info();
void Print_Tower(Hanoi info);
bool Move_disc(char from, char to, Hanoi tower);
bool Check(Hanoi info);


int main()
{
	Hanoi tower;

	Print_Info();

	char from{};
	char to{};
	
	while (true)
	{
		Print_Tower(tower); // 타워출력

		std::cout << std::endl;		// 어디에서 어디로 옮길 것인가 입력 받기
		std::cout << "From : ";
		std::cin >> from;
		std::cout << "To : ";
		std::cin >> to;
		std::cout << std::endl;

		Move_disc(from, to, tower);

		if (Check(tower))
		{
			Print_Tower(tower);
			std::cout << "Well Done!!" << std::endl;
			break;
		}

	}


}

void Print_Info()
{
	std::cout << "------Welcome to Tower of Hanoi mini game!!!------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Rule 1 : Player can move only one disc at a time " << std::endl;
	std::cout << "Rule 2 : Larger disc cannot be placed on a samll disc " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

}

void Print_Tower(Hanoi info)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << info.base_tower[i][j] << "  ";
		}
	std::cout << std::endl;
	}
	std::cout << "A" << "  " << "B" << "  " << "C" << std::endl;
}

bool Move_disc(char from , char to, Hanoi tower)
{
	int A_from_index = 3 - tower.A_dics;
	int B_from_index = 3 - tower.B_dics;
	int C_from_index = 3 - tower.C_dics;

	int A_to_index = tower.B_dics + tower.C_dics;
	int B_to_index = tower.A_dics + tower.C_dics;
	int C_to_index = tower.B_dics + tower.A_dics;
	

	if (from == 'A' || from == 'a')
	{
		if (tower.A_dics == 0)
		{
			std::cout << "There is no discs you can move" << std::endl;
			return false;
			
		}
		else if (to == 'B' || to == 'b')
		{
			if ((tower.base_tower[A_from_index][0] > tower.base_tower[B_to_index][1]) && tower.B_dics != 0)
			{

				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.B_dics][1] = tower.base_tower[A_from_index][0];
			tower.base_tower[A_from_index][0] = 0;
			++tower.B_dics;
			--tower.A_dics;
			
		}
		else if (to == 'C' || to == 'c')
		{
			
			if ((tower.base_tower[A_from_index][0] > tower.base_tower[C_to_index][2]) && tower.C_dics != 0)
			{
				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.C_dics][2] = tower.base_tower[A_from_index][0];
			tower.base_tower[A_from_index][0] = 0;

			++tower.C_dics;
			--tower.A_dics;
		}
	}

	if (from == 'B' || from == 'b')
	{
		if (tower.B_dics == 0)
		{
			std::cout << "There is no discs you can move" << std::endl;
			return false;

		}
		else if (to == 'A' || to == 'a')
		{
			if ((tower.base_tower[B_from_index][1] > tower.base_tower[A_to_index][0]) && tower.A_dics != 0)
			{

				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.A_dics][0] = tower.base_tower[B_from_index][1];
			tower.base_tower[B_from_index][1] = 0;
			++tower.A_dics;
			--tower.B_dics;

		}
		else if (to == 'C' || to == 'c')
		{

			if ((tower.base_tower[B_from_index][1] > tower.base_tower[C_to_index][2]) && tower.C_dics != 0)
			{
				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.C_dics][2] = tower.base_tower[B_from_index][1];
			tower.base_tower[B_from_index][1] = 0;

			++tower.C_dics;
			--tower.B_dics;
		}
	}
	if (from == 'C' || from == 'c')
	{
		if (tower.C_dics == 0)
		{
			std::cout << "There is no discs you can move" << std::endl;
			return false;

		}
		else if (to == 'A' || to == 'a')
		{
			if (tower.base_tower[C_from_index][2] > tower.base_tower[A_to_index][0] && tower.A_dics != 0)
			{

				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.A_dics][0] = tower.base_tower[C_from_index][2];
			tower.base_tower[C_from_index][2] = 0;
			++tower.A_dics;
			--tower.C_dics;

		}
		else if (to == 'B' || to == 'b')
		{

			if (tower.base_tower[C_from_index][2] > tower.base_tower[B_to_index][1] && tower.C_dics != 0)
			{
				std::cout << "You cannot place bigger disc on the small disc" << std::endl;
				return false;
			}
			tower.base_tower[2 - tower.C_dics][1] = tower.base_tower[C_from_index][2];
			tower.base_tower[C_from_index][2] = 0;

			++tower.B_dics;
			--tower.C_dics;
		}
	}

}

bool Check(Hanoi info)
{
	if (info.C_dics == 3)
	{
		return true;
	}
	return false;
}
