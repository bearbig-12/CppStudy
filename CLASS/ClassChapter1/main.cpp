#include <iostream>

//	C++ 클래스

//		1. 객체(Object) : 클래스로 만들어진 하나의 인스턴스(instance)

//		2. 클래스(Class)
//			
//			상태(state)
//				멤버변수(member variable) - C++
//				필드(Field)				  - C#, JAVA

//			행동(Behaviour)
//				멤버함수(Member Function) - C++
//				메써드(Method)			  - C#, JAVA


//		3. 캡슐화(Encapsulation)
// 
//				불필요한 정보를 숨겨서 쉽게 사용
//				Information Hiding
//					- 불필요한 정보를 숨겨서 쉽게 사용
//					- 보안 : 괜히 건드려서 좋을 것 없는 정보 숨기기


//		4. 상속(Inheritance), 파생(Derivation)

//			상속 - 부모(parent) 클래스 , 자식(Child) 클래스
//			파생 - 기반(base) 클래스 , 파생(Derived) 클래스


//		5. 다형성(Polymorphism)

//			나초는 고양이입니다.
//			나초는 동물입니다.

//----------------------------------------------------------------------

//		생성자(constructor) , 소멸자(Destructor)
//			객체가 만들어질때 자동적으로 생성자가 사용, 소멸될때 사용자가 사용

//		Static Member
//			정적 멤버: 인스턴스와 상관없이 하나만 존재하는 멤버

//		Abstract Class
//			개념만으로 존재하는 클래스
//			Interface
//				UI - User Interface
//				HDMI
//				Audio Interface
//				USB

class Point2D
{
	
	int mX;
	int mY;
public:
	void Print();
	//Getter & Setter
	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
};

void Point2D::Print()
{
	std::cout << mX << " , " <<  mY << std::endl;
}
void Point2D::Set(int x, int y)
{
	mX = x;
	mY = y;
}
void Point2D::SetX(int x)
{
	mX = x;
}
void Point2D::SetY(int y)
{
	mY = y
}
int Point2D::GetX()
{
	return mX;
}
int Point2D::GetY()
{
	return mY;
}
int main()
{
}


