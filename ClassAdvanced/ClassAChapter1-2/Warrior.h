
#pragma once
#include "Character.h"
class Warrior :
    public Character
{

public:
    Warrior();
    ~Warrior();

    void Attack() const override;
    void DoubleSwing() const;
    void Dead() const override;
};