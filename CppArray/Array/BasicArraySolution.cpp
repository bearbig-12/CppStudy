#include <iostream>

int main()
{
	//1�� ���� ���ڿ��� �Է¹޾� �Ųٷ� ����� ������.

	//int size{ 20 }; //- ���ڿ� ������
	//std::cout << "Insert the word : ";

	//char input[20]{};

	//std::cin >> input;

	//for (int i = size - 1; i >= 0; --i)// �迭�� 0�������� ī����.
	//{
	//	std::cout << input[i];
	//}


    //2��   �� ���ڿ��� �Է��Ͽ� �ϳ��� ���ڿ��� ����� ����� ������.
    //char first[10]{};
    //char second[10]{};
    //char sum[20]{};
    //std::cout << "Fisrt Word : " << std::endl;

    //std::cin >> first;

    //std::cout << std::endl;

    //std::cout << "Second Word : " << std::endl;

    //std::cin >> second;

    //for (int i = 0; i < 10; ++i)
    //{
    //    if (first[i] == '\0')
    //    {
    //        break;
    //    }
    //    sum[i] = first[i];
    //}
    //for (int j = 10; j < 20; ++j)
    //{
    //    if (second[j] == '\0')
    //    {
    //        break;
    //    }
    //    sum[j] = second[j - 10];
    //}
    //for (int i = 0; i < 20; ++i)
    //{
    //    if (sum[i] == '\0')
    //    {
    //        break;
    //    }
    //    std::cout << sum[i];
    //}


    //3�� ���ڿ��� �Է¹޾� ��� �빮�ڷ� ��ȯ�� ������
    char string[10]{};
    

    std::cout << "Please insert the word to change it to Upper Case : ";
    std::cin >> string;

    for (int i = 0; i < sizeof(string); ++i)
    {
        if (string[i] == '\0')  // ������ ������, ���ڿ� ���� �Է��� �������� �����ϰ� �ݺ��� ����.
        {
            break;
        }
        if (64 < string[i] && string[i] < 91) //���ڰ� �̹� �빮�� �Ͻÿ��� ����
        {
            continue;
        }
        else
        {
            string[i] = string[i] - 32;

        }
    }

    for (int i = 0; i < sizeof(string); ++i)
    {
        if (string[i] == '\0')
        {
            break;
        }
        std::cout << string[i];
    }

}