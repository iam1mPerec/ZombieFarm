#include <iostream>
#include "Healer.h"

using namespace std;

healer::healer():
unit(title::healer)
{
    create();
    lvl = 1;
    stat();
    hp = maxHp;
    draw();
    maxTurns = 2;
    turn = 2;
}

healer::healer(const int LVL, const int HP):
unit(title::healer)
{
    create();
    lvl = LVL;
    if (lvl > maxLVL)
    {
        lvl = maxLVL;
    }
    stat();
    hp  = HP;
    if (hp > maxHp)
    {
        hp = maxHp;
    }
    draw();
    maxTurns = 2;
    turn = 2;
}

void healer::revive()
{
    hp = 10;
    alive = true;
    stat();
    draw();
    pic[3][9]  = '\2';
    pic[3][11] = '\2';
}

void healer::create()
{
    priority = 6;
    maxLVL = 25;
    maxExp = 100;
    char troop[3][22] =
    {
        "|        ___        |",
        "|       (\2_\2)       |",
        "|        /\1\\        |"
    };
    
    for (int j = 0; j<3; j++)
    {
        for (int i = 0; i<21; i++)
        {
            pic[j+2][i] = troop[j][i];
        }
    }
    char name[] = {"Medic"};
    for (int i = 0; i<5; i++)
    {
        pic[1][12+i] = name[i];
    }
}

void healer::stat()
{
    if (shilds)
    {
        deff    = (lvl/4+5)*2;
    }
    else
    {
        deff   = lvl/4+5;
    }
    atk    = 3*lvl+20;
    maxHp  = 10*lvl+150;
    maxExp = 100;
    for (int i = 1; i<lvl; i++)
    {
        maxExp *= 1.25;
    }
    maxTurns = 2;
    priority = 6;
    addBuff();
}