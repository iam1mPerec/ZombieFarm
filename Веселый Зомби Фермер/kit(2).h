#pragma once
#include "consumables.h"

class kit : public consumables
{
    const int hp;
    
public:
    kit(const int Hp, const int Price);
};