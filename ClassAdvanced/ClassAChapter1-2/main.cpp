#include <iostream>
#include "Character.h"
#include "Warrior.h"

//		Up-Cast				vs				Down-Cast
//		자식->부모							부모->자식
//		안전한 변환							체크해야 함 (RunTime)
//		암시적 변환							명시적 변환

//		float x = 10.1f;
//		int y = int(x); - compile-time

//		((Warrior*)pHero)->DoubleSwing(); - RunTime

//		static_cast<타입>(표현식);  - compile time
//		dynamic_cast<타입>(표현식); - run time 

//-----------------------------------------------------
//		reinterpret_cast<타입>(표현식);		- 타입이 완전히 다른 타입도 변환가능 -> 안전보장 x
//		const_cast<타입>(표현식);			- const type으로 상수타입 으로. 상수를 추가 할수도 제거 할수도 있음.


int main()
{
	float x = 10.5f;
	int y = static_cast<int> (x);

	Character* pHero = new Warrior;
	pHero->Attack();

	//((Warrior*)pHero)->DoubleSwing(); // Warrior의 고유 멤버 함수에 접근 하기위한 TpyeCast
	Warrior* pWarrior = dynamic_cast<Warrior*>(pHero);
	if (pWarrior == nullptr)
	{
		std::cout << "Error" << std::endl;	// run time 에 정상인지 아닌지 체크가능.
	}
	else
	{
		pWarrior->DoubleSwing();
	}
	pHero->Dead();
	delete pHero;

}