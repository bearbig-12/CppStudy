#include <iostream>
#include <fstream>
#include <exception>

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
	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	
	
	//파일 읽기
	ifs.open(filename);

	// 2. 파일 작업
	char ch;
	while (ifs.get(ch))
	{
		std::cout << ch;
	}

	//3.파일 닫기
	ifs.close();


}

int main()
{
	//LoadFile("Data/SimpleData.txt");
	try 
	{
		LoadFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt");

	}
	catch (std::exception e)
	{ 
		std::cout << "파일 작업 도중 문제가 발생했습니다" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
}