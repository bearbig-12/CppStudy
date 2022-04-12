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
	// Dog�� Animal���� �Ļ��Ǿ��� ������ ����
	// �������� Animal ������ �̱� ������ Animal�� ����.
	//Animal* animal = &Happy;

	//Animal* p = new Dog();
	//p->Sound();
	//delete p;

	{
		A* a = new A;
		B* b = new B;

		a->Func1();	// �Ϲ� ����Լ�
		a->Func2();	// ���� ����Լ�
		b->Func1();	// ����Լ� �������̵�
		b->Func2();	// �����Լ� �������̵�
	


	std::cout << "------------------------" << std::endl;

		A* p = b;
		p->Func1(); // A�� ����Լ�
		p->Func2();	// A�� ���� ��� �Լ� -> p�� ���� Ÿ��(B) -> B�� �������̵� �Լ�.
	}

	A* s = new C;
	s->Func1();	
	s->Func2(); // A�� ���� ��� �Լ� -> p�� ���� Ÿ��(C) -> C�� �������̵� �Լ�.
				// ���� C�� Func2�� ������ �Ǿ� ���� �ʴ´ٸ� �ٸ�Ÿ��(B)�� ������ �� �Լ��� �ִ��� ã���� ����.
				// Stack�� ���δ�� C-B-A������ ���� ������ B���� �����ǰ� ���� ��� A�� ����.
				// �����Լ��� ����Ÿ���� ã�ƾ� �ϱ� ������ LateBinding
}