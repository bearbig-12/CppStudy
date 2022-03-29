#include <iostream>

//	C++ Ŭ����

//		1. ��ü(Object) : Ŭ������ ������� �ϳ��� �ν��Ͻ�(instance)

//		2. Ŭ����(Class)
//			
//			����(state)
//				�������(member variable) - C++
//				�ʵ�(Field)				  - C#, JAVA

//			�ൿ(Behaviour)
//				����Լ�(Member Function) - C++
//				�޽��(Method)			  - C#, JAVA


//		3. ĸ��ȭ(Encapsulation)
// 
//				���ʿ��� ������ ���ܼ� ���� ���
//				Information Hiding
//					- ���ʿ��� ������ ���ܼ� ���� ���
//					- ���� : ���� �ǵ���� ���� �� ���� ���� �����


//		4. ���(Inheritance), �Ļ�(Derivation)

//			��� - �θ�(parent) Ŭ���� , �ڽ�(Child) Ŭ����
//			�Ļ� - ���(base) Ŭ���� , �Ļ�(Derived) Ŭ����


//		5. ������(Polymorphism)

//			���ʴ� ������Դϴ�.
//			���ʴ� �����Դϴ�.

//----------------------------------------------------------------------

//		������(constructor) , �Ҹ���(Destructor)
//			��ü�� ��������� �ڵ������� �����ڰ� ���, �Ҹ�ɶ� ����ڰ� ���

//		Static Member
//			���� ���: �ν��Ͻ��� ������� �ϳ��� �����ϴ� ���

//		Abstract Class
//			���丸���� �����ϴ� Ŭ����
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


