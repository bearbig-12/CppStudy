#pragma once
class Animal
{
protected: // - 상속 캡슐화, 파생 클래스에서만 접근 가능
    int mAge;
    int mWeight;
public:
    Animal();
    Animal(int age, int weight);

    virtual ~Animal();

    int GetAge() const;
    void SetAge(int age);
    int GetWeight() const;
    void SetWeight(int weight);

    virtual void Sound();       // 가상함수 덮어쓰기(override) - 파생 클래스에서 재정의 가능. 
    virtual Animal* Clone();
};

