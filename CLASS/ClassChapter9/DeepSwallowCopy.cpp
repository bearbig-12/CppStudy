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
		// ���� ����(swallow copy) - default
		Owner = house.Owner;		// ����� �ν��Ͻ��� �����Ͱ� ���� ���� �Ǳ��� �ν���Ʈ�� ����Ű�� �Ǵ� ������ �߻�
									// ���� ������ �ν��Ͻ��� ������ ��� ��۸� ������ �߻�
									
		// ���� ����(deep copy)
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