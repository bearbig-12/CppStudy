#include "Monster.h"

std::ifstream& Monster::ReadBinary(std::ifstream& ifs)
{
    int len;
    ifs.read(reinterpret_cast<char*>(&len), sizeof(int));
    mName.resize(len);
    ifs.read(&mName[0], len);
    ifs.read(reinterpret_cast<char*>(&mLevel), sizeof(int));
    ifs.read(reinterpret_cast<char*>(&mHP), sizeof(int));
    ifs.read(reinterpret_cast<char*>(&mMP), sizeof(int));


    // TODO: 여기에 return 문을 삽입합니다.
    return ifs;
}

std::ofstream& Monster::WriteBinary(std::ofstream& ofs)
{

    //길이, 문자열 , 정수, 정수, 정수
    int len{ static_cast<int> (mName.size()) };
    ofs.write(reinterpret_cast<char*>(&len), sizeof(int));
    ofs.write(mName.c_str(), len);

    ofs.write(reinterpret_cast<char*>(&mLevel), sizeof(int));
    ofs.write(reinterpret_cast<char*>(&mHP), sizeof(int));
    ofs.write(reinterpret_cast<char*>(&mMP), sizeof(int));


    // TODO: 여기에 return 문을 삽입합니다.
    return ofs;
}
