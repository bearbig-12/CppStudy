#include <iostream>

// using namespace �� ������Ͽ����� �ް��ϸ� ��������

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

	::Print();	// �̸��� �Ȱ��� ������ �����Լ��� ::�� ǥ������� ��
}