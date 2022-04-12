#pragma once
#include "Character.h"
class Warrior :
    public Character
{

public:
    Warrior();
    ~Warrior();

    void Attack() const override;
};

