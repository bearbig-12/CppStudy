#include <iostream>
#include <fstream>


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
	if (!ifs)
	{
		std::cout << filename << "not found " << std::endl;
		return false;
	}

	// 2. ���� �۾�
	char ch;
	while (ifs >> ch)
	{
		if (ifs.bad())
		{
			std::cout << "������ �ջ� �Ǿ����ϴ�" << std::endl;
			ifs.close();
			return false;
		}
		std::cout << ch;

		if (ifs.fail())
		{
			std::cout << "�ǵ�ġ ���� �۾��Դϴ�." << std::endl;
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


	// 3. ���� �ݱ�
	ifs.close();
	return true;
}

int main()
{
	//LoadFile("Data/SimpleData.txt");
	LoadFile("D:\\Git hub\\CppStudy\\FileStream\\Data\\SimpleData.txt");
}