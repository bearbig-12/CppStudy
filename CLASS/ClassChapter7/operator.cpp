#include <iostream>
#include <cmath>
class Point2D
{
private:
	int mX;
	int mY;
public:
	Point2D();
	Point2D(int x, int y) : mX{ x }, mY{ y } {}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;

	}

	friend Point2D operator +(const Point2D& a, const Point2D& b) //����ü�� ���� �Ҷ��� ������ const�� ����ؾ��Ѵ� - ������ ����	
	{
		Point2D newPt{ 0,0 };
		newPt.mX = a.mX + b.mX;
		newPt.mY = a.mY + b.mY;

		return newPt;
	}

	//Point2D operator +(const Point2D& point)	// ����Լ�
	//{
	//	Point2D result{ mX + point.mX, mY + point.mY };
	//	return result;
	//}

	const Point2D& operator ++() // ++x ���� ������(����) �Ű������� ������ ����, ����ü�� ����� �����Ƿ� const Point2D&
	{
		++mX;
		++mY;

		return (*this);
	}

	const Point2D& operator ++(int x) // ++x ���� ������ �Ű������� �ƹ��ų� �־ �����Ϸ��� �˾Ƹ���
	{
		Point2D temp(mX, mY);

		++mX;
		++mY;
		//++(*this);
		

		return temp;
	}

	operator const float()	// ����ȯ ������ , ��ȯ�� ������ float���� �ϱ⿡ ���� Ÿ���� �Ⱦ� - ����ȯ �����ڴ� ��ȯ Ÿ�Ծ���.
	{
		return float(sqrt(mX * mX + mY * mY));
	}

	friend std::ostream& operator << (std::ostream& os, const Point2D& pt);

};

class MyArray
{
private:
	int* mArray;
public:
	MyArray() : mArray{} {}
	MyArray(int count)
	{
		mArray = new int[count];
	}
	~MyArray()
	{
		delete[] mArray;
	}

	int& operator [](int index)
	{
		return mArray[index];
	}
	// mArray[0] = 1; ���� �����ϱ� ���ؼ��� L-value �� ��ü�� �޾ƿ;� �ϱ� ������ int&�� ����ؾ� �Ѵ� ���� int���� ��ȯ �� ��� R_value�̱⿡ �� ���� X


};

// Point2D�� ��� �Լ��� �ƴ� �����Լ��̴� ���� ���� ������ �̴�.
std::ostream& operator << (std::ostream& os, const Point2D& pt) // os��� ��ü�� ����� ���� ���Ƴ����Ƿ� ������ �ؾ��Ѵ�. 
{
	os << "(" << pt.mX << ", " << pt.mY << ")" << std::endl;
	return os;
}

int main()
{
	Point2D pt1{ 2,3 };
	Point2D pt2{ 4,5 };
	Point2D pt3{ 0,0 };


	pt3 = pt1 + pt2;	// pt1 + pt2���� ����ü ����
	//pt3.Print();

	++pt3;
	//pt3.Print();

	pt3++;
	//pt3.Print();
	pt3 = ++(pt1 + pt2); // �̰�� ����ü�� ����

	std::cout << pt1 << pt2 << pt3 << std::endl;

	float length = pt3;
	std::cout << length << std::endl;

}



//#include <iostream>
//
//class MyClass
//{
//public:
//	int mValue;
//	MyClass(int value) : mValue{ value }
//	{
//		std::cout << "[ Myclass() ]" << mValue << std::endl;
//	}
//};
//
//MyClass operator +(MyClass c1, MyClass c2)
//{
//	return MyClass(c1.mValue + c2.mValue);
//}
//
//int Square(MyClass c) // (const MyClass c) ����ü�� ���� �Ҷ��� ������ const�� ����ؾ��Ѵ� - ������ ����
//{
//	return c.mValue * c.mValue;
//}
//
//int main()
//{
//	MyClass c1{ 1 }, c2{ 2 };
//	Square(c1 + c2);	// �����ڸ� ���� ��������� ������ �̸��� �����Ƿ� ��� �Ұ�
//
//	
//}