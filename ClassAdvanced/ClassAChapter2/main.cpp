#include <iostream>

//						함수포인터(정적멤버함수)				vs				멤버함수의 포인터
//	표현식				ret-type (*)(param-list)								ret-type(class-name::*)(param-list)
//	예제				using fptr = int (*)(int x)								using fptr = int (Myclass::*)(int x)
//	사용				fptr(3);												(intance.*fptr)(3);



class MyFunction
{
public:
	static int NormalFunction(int x)	// 인스턴스가 아닌 클래스의 함수에 접근하기 위해서 static을 붙인다
	{
		return x;
	}
	int SquareFunction(int x)
	{
		return x * x;
	}
};

using FunctionPtr = int (*)(int);


int Sigma(FunctionPtr f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}
	return sum;
}

using FunctionPtr2 = int (MyFunction::*)(int);

int Sigma2(MyFunction& instance, FunctionPtr2 f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += (instance.*f)(k); // 역참조 필요
	}
	return sum;
}

int main()
{
	MyFunction mf;

	std::cout << Sigma(MyFunction::NormalFunction, 1, 10) << std::endl;
	std::cout << Sigma2(mf, &MyFunction::SquareFunction, 1, 10) << std::endl;

}

