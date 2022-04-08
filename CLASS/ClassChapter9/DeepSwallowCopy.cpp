class DogOwner
{
public:
	int age;
	int weight;
	int color;

};
class DogHouse
{
	DogOwner* Owner;

public:
	DogHouse()
	{
		Owner = new DogOwner();
	}

	DogHouse(const DogHouse& house)
	{
		// 얕은 복사(swallow copy) - default
		Owner = house.Owner;		// 복사된 인스턴스의 포인터가 예전 복사 되기전 인스턴트를 가르키게 되는 문제가 발생
									// 먼저 생성된 인스턴스가 삭제될 경우 댕글링 포인터 발생
									
		// 깊은 복사(deep copy)
		Owner = new DogOwner();
		Owner->age = house.Owner->age;
		Owner->weight = house.Owner->weight;
		Owner->color = house.Owner->color;

	}

};



DogHouse::DogHouse()
{
}

DogHouse::~DogHouse()
{
}