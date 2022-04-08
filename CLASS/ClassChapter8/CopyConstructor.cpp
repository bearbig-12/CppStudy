#include <iostream>

//		���� ������
//			�޸� ���� ����
//			�����ϴµ� �ð� ���� �ɸ�
//				��� ������ ������ ������ ���� ���
//					Swallow Copy vs Deep Copy
class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value }
	{
		std::cout << "�Ϲ� ������" << std::endl;
	}

	//���� ������ - default = ���� ����
	MyClass(const MyClass& from)
	{
		this->mValue = from.mValue;
		std::cout << " ���� ������ " << std::endl;

	}
	MyClass& operator =(const MyClass& from)
	{
		this->mValue = from.mValue;
		std::cout << " ���� ���� ������" << std::endl;
		return *this;
	}
	friend std::ostream& operator << (std::ostream& os, const MyClass& pt);

};
std::ostream& operator << (std::ostream& os, const MyClass& mc) // os��� ��ü�� ����� ���� ���Ƴ����Ƿ� ������ �ؾ��Ѵ�. 
{
	os << "(" << mc.mValue << ")" << std::endl;
	return os;
}

int main()
{
	MyClass c1 = 5; // ����ȯ�� ���� 5�� Ŭ������ ����
	MyClass c2(c1);	// ���� �ʱ�ȭ

	MyClass c3{ MyClass{1} }; // �� ���� �Ϲ� �����ڸ� ȣ��ȴ�. 
							  // �ֳ��ϸ� MyClass{1}�� ����ü �̱� ������ �� ����ü�� c3��� �̸��� ���δ�.

	MyClass c4{10};
	c4 = c3 = c1;
	std::cout << c4 << std::endl;
}





