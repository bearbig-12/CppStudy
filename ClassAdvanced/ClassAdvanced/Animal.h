#pragma once
class Animal
{
protected: // - ��� ĸ��ȭ, �Ļ� Ŭ���������� ���� ����
    int mAge;
    int mWeight;
public:
    Animal();
    Animal(int age, int weight);

    ~Animal();

    int GetAge() const;
    void SetAge(int age);
    int GetWeight() const;
    void SetWeight(int weight);

    void Sound();
};

