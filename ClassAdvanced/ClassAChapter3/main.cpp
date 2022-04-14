#include <iostream>

// using namespace 는 헤더파일에서는 앵간하면 쓰지말기

namespace Game
{
	namespace Character
	{
		namespace Warrior
		{
			void Print()
			{

			}
		}
	}
	class game
	{
	public:

	};

	void Print()
	{
		std::cout << "Print whitch is in Game nacespace" << std::endl;
	}
}

void Print()
{
	std::cout << "Print whitch is Global Function" << std::endl;

}

int main()
{
	
	//Game::Print();
	//Game::Game g1;
	//Game::Character::Warrior::Print();

	using namespace Game;
	Game::Print();
	game g1;
	Character::Warrior::Print();

	::Print();	// 이름이 똑같기 때문에 전역함수는 ::로 표시해줘야 함
}