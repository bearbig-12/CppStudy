#include <iostream>
#include "Character.h"
#include "Warrior.h"

//		Up-Cast				vs				Down-Cast
//		�ڽ�->�θ�							�θ�->�ڽ�
//		������ ��ȯ							üũ�ؾ� �� (RunTime)
//		�Ͻ��� ��ȯ							����� ��ȯ

//		float x = 10.1f;
//		int y = int(x); - compile-time

//		((Warrior*)pHero)->DoubleSwing(); - RunTime

//		static_cast<Ÿ��>(ǥ����);  - compile time
//		dynamic_cast<Ÿ��>(ǥ����); - run time 

//-----------------------------------------------------
//		reinterpret_cast<Ÿ��>(ǥ����);		- Ÿ���� ������ �ٸ� Ÿ�Ե� ��ȯ���� -> �������� x
//		const_cast<Ÿ��>(ǥ����);			- const type���� ���Ÿ�� ����. ����� �߰� �Ҽ��� ���� �Ҽ��� ����.


int main()
{
	float x = 10.5f;
	int y = static_cast<int> (x);

	Character* pHero = new Warrior;
	pHero->Attack();

	//((Warrior*)pHero)->DoubleSwing(); // Warrior�� ���� ��� �Լ��� ���� �ϱ����� TpyeCast
	Warrior* pWarrior = dynamic_cast<Warrior*>(pHero);
	if (pWarrior == nullptr)
	{
		std::cout << "Error" << std::endl;	// run time �� �������� �ƴ��� üũ����.
	}
	else
	{
		pWarrior->DoubleSwing();
	}
	pHero->Dead();
	delete pHero;

}