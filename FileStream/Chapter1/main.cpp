#include <iostream>
#include <fstream>
#include <exception>

// 1. ���� ��Ʈ�� ��ü ����
//		1.1 ��带 ���� (�б�/����/�ؽ�Ʈ/���̳ʸ� ���)
//		1.2 ������ (�����̸�)
//		1.3 �� ������Ʈ ���� -> ���� ����

// 2. ���� �۾�
//		2.1 ��Ʈ��������
//		2.2 ��� �Լ�

// 3. ���� �ݱ�

bool LoadFile(const std::string& filename)
{

	std::ifstream ifs(filename);
	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	
	
	//���� �б�
	ifs.open(filename);

	// 2. ���� �۾�
	char ch;
	while (ifs.get(ch))
	{
		std::cout << ch;
	}

	//3.���� �ݱ�
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
		std::cout << "���� �۾� ���� ������ �߻��߽��ϴ�" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
}