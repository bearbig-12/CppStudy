#include <iostream>


//CompileTime Variables

//		Automatic Memory Allocation
//			��������, �Ű�����
//			'{' ��Ͽ��� �¾�� '}' ��Ͽ��� ���

//		Static Memory Allocation
//			��������, ��������
//			�ѹ� ����� �� ������� ��Ƴ���

//		Runtime Variables
//			Dynamic Memory Allocation
//				�츮�� ���Ҷ� �����, ���� ����


//	Dynamic Allocation Memory.
//		C - Style
			void* calloc(size_t num, size_t size);
//			 contiguous memory allocation
//			 ���� �ϳ��� ũ�Ⱑ size, ���� num�� = num * size
//			 �Ҵ�� �޸𸮴� ��� 0���� �ʱ�ȭ�մϴ�.
//			 �޸𸮰� �����ϰų� ������ �߻��ϸ� nullptr ��ȯ

			void* malloc(size_t size);
//			 memory allocation
//			 ����Ʈ�� �Ҵ�
//			 �ʱ�ȭ x
//			 �޸𸮰� �����ϰų� ������ �߻��ϸ� nullptr ��ȯ

			void free(void* ptr);
//			 �Ҵ�� �޸� ����

//		C++ Style
//			������(Operator)
// 
//			 new
//			  �־��� Ÿ������ �Ҵ� �� �����ش�. 
//		
//			 delete
//			  �Ҵ�� �޸� ����
//			
// 			  ������ ���� = new Ÿ��;
// 			  delete ������ ����;
// 
//			  ������ ���� = new Ÿ��[ũ��];
//			  delete[] ������ ����;


int main()
{
	{
		int* buffer1;
		int* buffer2;

		// 1. �Ҵ�
		buffer1 = (int*)calloc(100, sizeof(int));
		buffer2 = (int*)malloc(100 * sizeof(int));
		// 2. Ȯ��
		if (buffer1 != nullptr && buffer2 != nullptr)
		{
			std::cout << buffer1[0] << std::endl;
			std::cout << buffer2[0] << std::endl;
			//3. ���� (�޸𸮸� �Ҵ��Ҷ� ���ð� ���� �ױ� ������ ������ �������� ����)
			free(buffer2);
			free(buffer1);


		}
		else
		{
			//���� ó��
		}
	} //C - Style

	{
		// 1. �Ҵ�
		int* buffer3;
		//buffer3 = new int;
		buffer3 = new int[100];

		// 2. Ȯ��
		if (buffer3 != nullptr)
		{
			std::cout << buffer3[0] << std::endl;

			// 3. ����
			//delete buffer3;
			delete[] buffer3;
		}
		else
		{
			// ���� ó��
		}
	} //C++ Style

	
}