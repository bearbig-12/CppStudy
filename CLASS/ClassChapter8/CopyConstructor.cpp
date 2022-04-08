#include <iostream>

//		복사 생성자
//			메모리 많이 먹음
//			복사하는데 시간 많이 걸림
//				멤버 변수에 포인터 변수가 있을 경우
//					Swallow Copy vs Deep Copy
class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value }
	{
		std::cout << "일반 생성자" << std::endl;
	}

	//복사 생성자 - default = 얕은 복사
	MyClass(const MyClass& from)
	{
		this->mValue = from.mValue;
		std::cout << " 복사 생성자 " << std::endl;

	}
	MyClass& operator =(const MyClass& from)
	{
		this->mValue = from.mValue;
		std::cout << " 복사 대입 연산자" << std::endl;
		return *this;
	}
	friend std::ostream& operator << (std::ostream& os, const MyClass& pt);

};
std::ostream& operator << (std::ostream& os, const MyClass& mc) // os라는 객체를 만들수 없게 막아놨으므로 참조를 해야한다. 
{
	os << "(" << mc.mValue << ")" << std::endl;
	return os;
}

int main()
{
	MyClass c1 = 5; // 형변환을 통해 5를 클래스로 만듬
	MyClass c2(c1);	// 복사 초기화

	MyClass c3{ MyClass{1} }; // 이 경우는 일반 생성자만 호출된다. 
							  // 왜냐하면 MyClass{1}는 무명객체 이기 때문에 저 무명객체에 c3라는 이름만 붙인다.

	MyClass c4{10};
	c4 = c3 = c1;
	std::cout << c4 << std::endl;
}





