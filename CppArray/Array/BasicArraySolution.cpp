#include <iostream>

int main()
{
	//1번 문제 문자열을 입력받아 거꾸로 출력해 보세요.

	//int size{ 20 }; //- 문자열 사이즈
	//std::cout << "Insert the word : ";

	//char input[20]{};

	//std::cin >> input;

	//for (int i = size - 1; i >= 0; --i)// 배열은 0에서부터 카운팅.
	//{
	//	std::cout << input[i];
	//}


    //2번   두 문자열을 입력하여 하나의 문자열로 만들고 출력해 보세요.
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


    //3번 문자열을 입력받아 모두 대문자로 변환해 보세요
    char string[10]{};
    

    std::cout << "Please insert the word to change it to Upper Case : ";
    std::cin >> string;

    for (int i = 0; i < sizeof(string); ++i)
    {
        if (string[i] == '\0')  // 공백을 만날시, 문자에 대한 입력이 끝났음을 가정하고 반복을 멈춤.
        {
            break;
        }
        if (64 < string[i] && string[i] < 91) //문자가 이미 대문자 일시에는 무시
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