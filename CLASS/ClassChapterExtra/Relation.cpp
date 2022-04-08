

//  A is part of B	(���� ���� ���� - ��� ���� ���)
//		A�� B�� �Ϻ� �������
//		A�� �ѹ��� �ϳ��� ��ü���� ����
//		A�� B�� ���� ���� (�ɸ��Ͱ� �������� �������ͽ��� ��������.)
//		A�� B�� ���縦 ���� ��

class Status
{
	int hp;
	int mp;
};
class Character
{
	Status mStatus;
};

//	A has a B  (���� ���� ���� - ������)
//		B�� A�� �������
//		B�� �ѹ��� ���� ������Ʈ�� �Ҽ�
//		B�� A�� ���� �������� ���� (������ ����� �÷��̾�� �������� ����)
//		B�� A�� ���縦 ���� ��

class Player
{
};

class Auction
{
	Player* mPlayers;
};


//	A use a B
//		B�� A�� ������ ����
//		B�� �ѹ��� ���� ������Ʈ�� �Ҽ�
//		B�� A�� ���� �������� ����
//		B�� A�� ���縦 �𸦼��� �ְ� �� ���� �ִ�.

class Potion
{
	int mCount;
	int mRecovery;
};

class Player
{
	Potion* pPotion;
};

//	A is a B
//		Ư��ȭ ��ü -> �Ϲ����� ����
//		�Ϲ�ȭ, Ư��ȭ
//		���(Inheritance), �Ļ�(derivation)

//		��������(����) - Base class , ��������(��) - Derived class

class Dog
{
private:
	int mAge;
public:
	int mWeight;
public:
	void Bark();
};

class Cat
{
private:
	int mAge;
public:
	int mWeight;
public:
	void Meow();
};

// �Ϲ�ȭ 
// mAge, mWeight

//	A is a B
//		���� ������ �����̴�.
//		���̽�ũ���� ������ �����̴�.
//		���� ���̽�ũ���� �ٸ���.

//		��������(����) - Base class , ��������(��) - Derived class

//				�Ļ�(Derivation)				���(Inheritance)			????
//	�Ϲ�ȭ			base class						Parent class			super class
//	Ư��ȭ			Derived class					Child class				sub class

class �Ļ�Ŭ���� : [virtual] [����������] ���Ŭ����, ���Ŭ����2

	//	Access Modifierts
//		private   : Ŭ���� ���ο����� ����
//		public	  : ��� ����
//		protected : ��ӿ����� ����, �������� �����

class Animal
{
private:
	int mAge;		// Ŭ���� ����
public:
	int mWeight;	// Ŭ���� ����, �ܺ�, �Ļ�
protected:
	int mValue;		// Ŭ���� ����, �Ļ�

};

class Dog : Animal // Dog = child, Animal = parent
{
	// Animal ���� �Ļ� �Ǿ��� ������ mAge�� mWeight�� ������ �ִ�
public:
	void Bark();
};

class Cat : Animal
{
	// �ɽ��� ��������
public:
	void Meow();
};




// Type Casting (Ÿ�� ��ȯ)

// ���� ��ȯ Up Cast
//
//		�ڽ� -> �θ�
//		����, �Ͻ���
//		Animal* p = new Dog;

//	���� ��ȯ Down Cast
//		
//		�θ� -> �ڽ�
//		Ȯ��, ��Ÿ�� üũ
//		((Warrior*)pHero)->DoubleSwing();

static_cast<new_type> (expression)		// expression �����ڸ� ������ ����
		// ������ Ÿ�� - �ش� ������ Ÿ��
		// �Ͻ�����ȯ ����
		// int x = 10;
		// float y = static_cast<float>(x);

	dynamic_cast <new_type> (expression)
	// ��Ÿ�� üũ



	const_cast<new_type> (expression)

	void Print(char* text)
{

}

int main()
{
	const char myString[] = "this is test";
	Print(const_cast<char*>(myString));
}





�߻� Ŭ����(Abstract class)
//		���� ���� �Լ��� �ϳ��� ���� Ŭ����
//
//		pure virutal function
//			������θ� �����ϰ� ����(��ü)�� ����.
//			�Ļ��� Ŭ�������� ������ override �ؾ߸� ��
//	
//			virtual void function() = 0;
// 
//		�ν��Ͻ��� ���� �� ����
//		��� Ŭ�����θ� ��� ����
//		�Ļ� Ŭ���������� ��� ���������Լ��� �������̵� �ؾ���

�������̽�(Interface)




// �Լ� ������

//		���� ��� �Լ� = ���� �Լ�

//		���� ret-type (*) (param - list)
//		���� using ptr = int (*) (int, float);
//		ȣ�� ptr p;
//				 p(3, 1.0f);


//		������ ��� �Լ�

//		���� ret-type (class-name::*)(para-list)
//		���� using ptr = (Myclass::*)(int);
// 
//		ȣ�� ptr p;
//				 (instance.*p)(3);


//	Template

//		���ǻ���
//			Ư��ȭ�� ��ŭ �ڵ尡 �߰�
//			���ø��� ����� ���Ǵ� ���� ���Ͽ� ����!!!

//		Generic Programming

//		�Ϲ�ȭ(Generalization)
//		Ư��ȭ(Specialization)

