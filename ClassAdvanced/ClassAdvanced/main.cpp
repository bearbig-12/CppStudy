#include <iostream>
#include "Dog.h"


class A
{
public:
	void Func1()
	{
		std::cout << "ClassA's Func1 " << std::endl;
	}
	virtual void Func2()
	{
		std::cout << "ClassA's Func2 " << std::endl;

	}
};

class B : public A
{
public:
	void Func1()
	{
		std::cout << "ClassB's Func1 " << std::endl;

	}
	void Func2()
	{
		std::cout << "ClassB's Func2 " << std::endl;

	}
};

class C : public B
{
public:
	void Func1()
	{
		std::cout << "ClassC's Func1 " << std::endl;
	}
	void Func2()
	{
		std::cout << "ClassC's Func2 " << std::endl;
	}
};

int main()
{
	//Dog Happy;
	//Happy.Sound();
	//Happy.Roll();

	// Dog is a Animal
	// Dog는 Animal에서 파생되었기 때문에 가능
	// 역참조시 Animal 포인터 이기 때문에 Animal로 간다.
	//Animal* animal = &Happy;

	//Animal* p = new Dog();
	//p->Sound();
	//delete p;

	{
		A* a = new A;
		B* b = new B;

		a->Func1();	// 일반 멤버함수
		a->Func2();	// 가상 멤버함수
		b->Func1();	// 멤버함수 오버라이딩
		b->Func2();	// 가상함수 오버라이딩
	


	std::cout << "------------------------" << std::endl;

		A* p = b;
		p->Func1(); // A의 멤버함수
		p->Func2();	// A의 가상 멤버 함수 -> p의 실제 타입(B) -> B의 오버라이딩 함수.
	}

	A* s = new C;
	s->Func1();	
	s->Func2(); // A의 가상 멤버 함수 -> p의 실제 타입(C) -> C의 오버라이딩 함수.
				// 만약 C에 Func2가 재정의 되어 있지 않는다면 다른타입(B)에 재정의 된 함수가 있는지 찾으러 간다.
				// Stack에 쌓인대로 C-B-A순으로 가기 때문에 B에도 재정의가 없는 경우 A로 간다.
				// 가상함수는 실제타입을 찾아야 하기 때문에 LateBinding
}