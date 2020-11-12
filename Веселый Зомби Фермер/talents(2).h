#pragma once
#include <iostream>

enum talents
{
    potato,
    wheat,
    tomato,
    carrot,
    pumpkin,
    strawberry,
    numberOfPlants
};

class text_talents
{
    text_talents();
public:
    const static char plants[numberOfPlants][20];
};
const static char plants[numberOfPlants][20] =
{
    "Potatos",
    "Wheat",
    "Tomatos",
    "Carrots",
    "Pumpkins",
    "Strawberrys"
};