#include <iostream>
#include <time.h>

enum Type
{
    FIND = 1,
    STOP = 2
};


int main()
{


    std::cout << "<Bingo>" << std::endl;
    std::cout << "[1] Find" << std::endl;
    std::cout << "[2] Stop" << std::endl;
    std::cout << "----------------" << std::endl;
    int mLines;
    std::cout << "Please Insert the Lines you want : ";
    std::cin >> mLines;

    int* mTable = new int[mLines * mLines]{};
    int mRight{}, mLeft{}, mTemp{};

    for (int i = 0; i < mLines * mLines; ++i)
    {

        mTable[i] = 0;

    }

    for (int i = 0; i < mLines * mLines; ++i)
    {

        mTable[i] = i + 1;

    }

    for (int i = 0; i < (mLines * mLines) * 10; ++i)
    {
        mRight = rand() % (mLines * mLines);
        mLeft = rand() % (mLines * mLines);

        mTemp = mTable[mRight];
        mTable[mRight] = mTable[mLeft];
        mTable[mLeft] = mTemp;


    }



    int command{ 0 };
    bool isExit{ false };
    int mBingos{ 0 };

    while (true)
    {


        system("cls");

        for (int i = 0; i < mLines * mLines; ++i)
        {

            if (mTable[i] == 0)
            {
                std::cout << "[ " << "*" << " ]" << "\t";
            }
            else
            {
                std::cout << "[ " << mTable[i] << " ]" << "\t";

            }
            if ((i + 1) % mLines == 0)
            {
                std::cout << std::endl;
            }

        }
        std::cout << "BingoLines : " << mBingos << std::endl;
        std::cout << "Option : ";
        std::cin >> command;

        switch (command)
        {
        case FIND:
        {
            int mValue{ 0 };
            std::cout << "      value >> ";
            std::cin >> mValue;
            if (1 > mValue || mValue > mLines * mLines)
            {
                break;
            }

            for (int i = 0; i < mLines * mLines; ++i)
            {

                if (mTable[i] == mValue)
                {
                    mTable[i] = 0;
                }

            }

            break;

        }
        case STOP:
            isExit = true;
            break;

        default:
            std::cout << "It is not valiad option" << std::endl;
            break;
        }

        //가로 세로
        int mRow{}, mCol{};
        mBingos = 0;
        for (int i = 0; i < mLines; ++i)
        {
            mRow = mCol = 0;
            for (int j = 0; j < mLines; ++j)
            {
                if (mTable[i * mLines + j] == 0)
                {
                    ++mRow;
                }
                if (mTable[j * mLines + i] == 0)
                {
                    ++mCol;
                }

            }
            if (mRow == mLines)
            {
                ++mBingos;
            }
            if (mCol == mLines)
            {
                ++mBingos;
            }
        }
        //왼쪽에서 오른쪽 아래로 대각선
        mRow = mCol = 0;
        for (int i = 0; i < mLines * mLines; ++i)
        {

            if (i % (mLines + 1) == 0)
            {
                if (mTable[i] == 0)
                {
                    ++mRow;

                }
            }

        }
        //오른쪽에서 왼쪽 아래로 대각선
        for (int i = 1; i < mLines * mLines - (mLines - 1); ++i)
        {
            if (i % (mLines - 1) == 0)
            {
                if (mTable[i] == 0)
                {
                    ++mCol;

                }

            }
        }
        if (mRow == mLines)
        {
            ++mBingos;
        }
        if (mCol == mLines)
        {
            ++mBingos;
        }

        if (isExit == true)
        {
            break;
        }
    }

    delete[] mTable;
    return 0;
}