#include <iostream>


// Smart Pointer

//	OwnerShip (소유권)
//
//		std::unique_ptr - 1대1
//			객체의 소유권을 가짐
//			복사X (복사 생성자, 복사대입), 이동은 가능			
//
//		std::shared_ptr - 1대N
//			객체의 소유권을 공유
// 
//		std::weak_ptr
//			기본적으로 shared_ptr + 소유권을 주장하지 않음
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

	DoSomething(spSong.get()); // 일반 포인터를 넘겨주기

	std::cout << spSong->mTrackNo << " : " << spSong->mTitle << std::endl;

	//spSong.release(); delete만
	//spSong.reset(); delete and spSong = nullptr
}