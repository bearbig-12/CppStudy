#include <iostream>
#include <fstream>


// 1. 파일 스트림 객체 생성
//		1.1 모드를 지정 (읽기/쓰기/텍스트/바이너리 모드)
//		1.2 생성자 (파일이름)
//		1.3 빈 오브젝트 생성 -> 파일 열기

// 2. 파일 작업
//		2.1 스트림연산자
//		2.2 멤버 함수

// 3. 파일 닫기

bool LoadFile(const std::string& filename)
{

	std::ifstream ifs(filename);
	if (!ifs)
	{
		std::cout << filename << "not found " << std::endl;
		return false;
	}

	// 2. 파일 작업
	char ch;
	while (ifs >> ch)
	{
		if (ifs.bad())
		{
			std::cout << "파일이 손상 되었습니다" << std::endl;
			ifs.close();
			return false;
		}
		std::cout << ch;

		if (ifs.fail())
		{
			std::cout << "의도치 않은 작업입니다." << std::endl;
			ifs.close();
			return false;
		}

		std::cout << ch;
	}
	//while (ifs)
	//{
	//	ifs.get(ch);
	//	std::cout << ch;
	//}


	// 3. 파일 닫기
	ifs.close();
	return true;
}

int main()
{
	//LoadFile("Data/SimpleData.txt");
	LoadFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt");
}