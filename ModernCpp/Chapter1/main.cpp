#include <iostream>


// ���� ���� ���ø�
class Character
{
public:
	enum Type
	{
		WARRIOR=1,
		ARCHER,
		WIZARD,
		THIEF
	};

	
};
//Factory Pattern
template<typename T, typename...Types>
T* Make(Types...args)
{
	return new T(args...);
}
int main()
{
	
}