#include <iostream>


// Smart Pointer

//	OwnerShip (������)
//
//		std::unique_ptr - 1��1
//			��ü�� �������� ����
//			����X (���� ������, �������), �̵��� ����			
//
//		std::shared_ptr - 1��N
//			��ü�� �������� ����
// 
//		std::weak_ptr
//			�⺻������ shared_ptr + �������� �������� ����
//

class MyClass
{
public:
	~MyClass()
	{
		std::cout << "Delete" << std::endl;
	}
};

class Song
{
public:
	int mTrackNo;
	std::string mTitle;

	Song(int trackNo, std::string title) : mTrackNo{ trackNo }, mTitle{ title }
	{

	}
};

void DoSomething(Song* p)
{

}

int main()
{
	/*std::unique_ptr<MyClass> sp{ new MyClass };

	std::unique_ptr<MyClass> sp2{ std::make_unique<MyClass>() };*/

	std::unique_ptr<Song> spSong = std::make_unique<Song>(1, "BattleBgm");

	DoSomething(spSong.get()); // �Ϲ� �����͸� �Ѱ��ֱ�

	std::cout << spSong->mTrackNo << " : " << spSong->mTitle << std::endl;

	//spSong.release(); delete��
	//spSong.reset(); delete and spSong = nullptr
}