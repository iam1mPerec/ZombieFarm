#include <iostream>
#include <fstream>
#include "str.h"
#include "ItemLoader.h"

using namespace std;

itemLoader::itemLoader()
{
}

item* itemLoader::getRandomEquip()
{
    
    int random = rand()%5;
    item* aloc = nullptr;
    
    switch (random)
    {
        case 0:
            random = rand()%5;
            aloc = chest(random);
            break;
        
        case 1:
            random = rand()%5;
            aloc = helmet(random);
            break;
        
        case 2:
            random = rand()%5;
            aloc = gloves(random);
            break;
            
        case 3:
            random = rand()%5;
            aloc = boots(random);
            break;
            
        case 4:
            random = rand()%5;
            aloc = weapon(random);
            break;
            
        default:
            break;
    }
    
    return aloc;
}

chest* itemLoader::chest(const int type)
{
    {
        ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Chests.txt");
        
        class chest* aloc;
        
        char buff[40] = {};
        
        int def      = 0;
        int hp       = 0;
        int price    = 0;
        
        for (int item = 0; item < type+1;)
        {
            LoadFile>>buff;
            
            if (!LoadFile.eof() && buff[0] == '$')
            {
                LoadFile>>buff;
                LoadFile>>def;
                LoadFile>>hp;
                LoadFile>>price;
                item++;
            }
        }
        
        aloc = new class chest(def, hp, price);
        inflation(buff);
        aloc->fillDescription(buff);
        aloc->fillName(buff);
        aloc->fillDescription(" ");
        LoadFile>>buff;
        while (!LoadFile.eof())
        {
            char add[30] = {};
            
            LoadFile>>add;
            
            if (add[0] == '^')
            {
                aloc->fillDescription(buff);
                clean(buff, 40);
            }
            
            else if(add[0] == '$')
            {
                clean(buff, 40);
                break;
            }
            else
            {
                addToString(buff, add);
            }
        }
        aloc->fillDescription(" ");
        aloc->fillDescription("Stats:");
        aloc->fillDescription(" ");
        
        if (def)
        {
            char descr[9] = {"Def    +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(def);
            int DEF = def;
            for (int i = len-1; i>-1; i--)
            {
                buff[i+l] = (char)((int)'0') + DEF%10;
                DEF /= 10;
            }
            aloc->fillDescription(buff);
        }
        if (hp)
        {
            char descr[9] = {"Hp     +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(hp);
            int HP = hp;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + HP%10;
                HP /= 10;
            }
            aloc->fillDescription(buff);
        }
        aloc->clearDescript();
        LoadFile.close();
        return aloc;
    }
}

chest* itemLoader::chest(const char* Name)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Chests.txt");
    char buff[30] = {};
    int TYPE = -1;
    while (!LoadFile.eof())
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            TYPE++;
            inflation(buff);
            if (equals(buff,Name))
            {
                break;
            }
        }
    }
    LoadFile.close();
    return chest(TYPE);
}

gloves* itemLoader::gloves(const int type)
{
    {
        ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Gloves.txt");
        
        class gloves* aloc;
        
        char buff[40] = {};
        
        clean(buff, 40);
        
        int def      = 0;
        int hp       = 0;
        int price    = 0;
        
        for (int item = 0; item < type+1;)
        {
            LoadFile>>buff;
            
            if (!LoadFile.eof() && buff[0] == '$')
            {
                LoadFile>>buff;
                LoadFile>>def;
                LoadFile>>hp;
                LoadFile>>price;
                item++;
            }
        }
        
        aloc = new class gloves(def, hp, price);
        inflation(buff);
        aloc->fillDescription(buff);
        aloc->fillName(buff);
        aloc->fillDescription(" ");
        LoadFile>>buff;
        while (!LoadFile.eof())
        {
            char add[30] = {};
            
            LoadFile>>add;
            
            if (add[0] == '^')
            {
                aloc->fillDescription(buff);
                clean(buff, 40);
            }
            
            else if(add[0] == '$')
            {
                clean(buff, 40);
                break;
            }
            else
            {
                addToString(buff, add);
            }
        }
        aloc->fillDescription(" ");
        aloc->fillDescription("Stats:");
        aloc->fillDescription(" ");
        
        if (def)
        {
            char descr[9] = {"Def    +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(def);
            int DEF = def;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[i+l] = (char)((int)'0') + DEF%10;
                DEF /= 10;
            }
            aloc->fillDescription(buff);
        }
        if (hp)
        {
            char descr[9] = {"Hp     +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(hp);
            int HP = hp;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + HP%10;
                HP /= 10;
            }
            aloc->fillDescription(buff);
        }
        aloc->clearDescript();
        LoadFile.close();
        return aloc;
    }
}

gloves* itemLoader::gloves(const char* Name)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Gloves.txt");
    char buff[30] = {};
    int TYPE = -1;
    while (!LoadFile.eof())
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            TYPE++;
            inflation(buff);
            if (equals(buff,Name))
            {
                break;
            }
        }
    }
    LoadFile.close();
    return gloves(TYPE);
}

boots* itemLoader::boots(const int type)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Boots.txt");
    
    class boots* aloc;
    
    char buff[40] = {};
    
    int def      = 0;
    int hp       = 0;
    int price    = 0;
    
    for (int item = 0; item < type+1;)
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            LoadFile>>def;
            LoadFile>>hp;
            LoadFile>>price;
            item++;
        }
    }
    
    aloc = new class boots(def, hp, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
    while (!LoadFile.eof())
    {
        char add[30] = {};
        
        LoadFile>>add;
        
        if (add[0] == '^')
        {
            aloc->fillDescription(buff);
            clean(buff, 40);
        }
        
        else if(add[0] == '$')
        {
            clean(buff, 40);
            break;
        }
        else
        {
            addToString(buff, add);
        }
    }
    aloc->fillDescription(" ");
    aloc->fillDescription("Stats:");
    aloc->fillDescription(" ");
    
    if (def)
    {
        char descr[9] = {"Def    +"};
        clean(buff, 40);
        int l = unsigned(strlen(descr));
        strcpy_s(buff, l, descr);
        int len = LenOfNumbers(def);
        int DEF = def;
        for (int i = len-1; i>-1; i--)
        {
            buff[i+l] = (char)((int)'0') + DEF%10;
            DEF /= 10;
        }
        aloc->fillDescription(buff);
    }
    if (hp)
    {
        char descr[9] = {"Hp     +"};
        clean(buff, 40);
        int l = unsigned(strlen(descr));
        strcpy_s(buff, l, descr);
        int len = LenOfNumbers(hp);
        int HP = hp;
        
        for (int i = len-1; i>-1; i--)
        {
            buff[l+i] = (char)((int)'0') + HP%10;
            HP /= 10;
        }
        aloc->fillDescription(buff);
    }
    aloc->clearDescript();
    LoadFile.close();
    return aloc;
}

boots* itemLoader::boots(const char* Name)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Boots.txt");
    char buff[30] = {};
    int TYPE = -1;
    while (!LoadFile.eof())
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            TYPE++;
            inflation(buff);
            if (equals(buff,Name))
            {
                break;
            }
        }
    }
    LoadFile.close();
    return boots(TYPE);
}

helmet* itemLoader::helmet(const char* Name)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Helmets.txt");
    char buff[30] = {};
    int TYPE = -1;
    while (!LoadFile.eof())
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            TYPE++;
            inflation(buff);
            if (equals(buff,Name))
            {
                break;
            }
        }
    }
    LoadFile.close();
    return helmet(TYPE);
}

helmet* itemLoader::helmet(const int type)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Helmets.txt");
    
    class helmet* aloc;
    
    char buff[40] = {};
    
    int def      = 0;
    int hp       = 0;
    int priority = 0;
    int price    = 0;
    
    for (int item = 0; item < type+1;)
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            LoadFile>>def;
            LoadFile>>hp;
            LoadFile>>priority;
            LoadFile>>price;
            item++;
        }
    }
    
    aloc = new class helmet(def, hp, priority, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
    while (!LoadFile.eof())
    {
        char add[30] = {};
        
        LoadFile>>add;
        
        if (add[0] == '^')
        {
            aloc->fillDescription(buff);
            clean(buff, 40);
        }
        
        else if(add[0] == '$')
        {
            clean(buff, 40);
            break;
        }
        else
        {
            addToString(buff, add);
        }
    }
    aloc->fillDescription(" ");
    aloc->fillDescription("Stats:");
    aloc->fillDescription(" ");
    
    if (def)
    {
        char descr[9] = {"Def     "};
        if (def>0)
        {
            descr[7] = '+';
        }
        else if(def<0)
        {
            descr[7] = '-';
            def *= (-1);
        }
        clean(buff, 40);
        int l = unsigned(strlen(descr));
        strcpy_s(buff, l, descr);
        int len = LenOfNumbers(def);
        int DEF = def;
        for (int i = len-1; i>-1; i--)
        {
            buff[i+l] = (char)((int)'0') + DEF%10;
            DEF /= 10;
        }
        aloc->fillDescription(buff);
    }
    if (hp)
    {
        char descr[9] = {"Hp      "};
        if (hp>0)
        {
            descr[7] = '+';
        }
        else if(hp<0)
        {
            descr[7] = '-';
            hp *= (-1);
        }
        clean(buff, 40);
        int l = unsigned(strlen(descr));
        strcpy_s(buff, l, descr);
        int len = LenOfNumbers(hp);
        int HP = hp;
        
        for (int i = len-1; i>-1; i--)
        {
            buff[l+i] = (char)((int)'0') + HP%10;
            HP /= 10;
        }
        aloc->fillDescription(buff);
    }
    if (priority)
    {
        char descr[9] = {"Prior   "};
        if (priority>0)
        {
            descr[7] = '+';
        }
        else if(priority<0)
        {
            descr[7] = '-';
            priority *= (-1);
        }
        clean(buff, 40);
        int l = unsigned(strlen(descr));
        strcpy_s(buff, l, descr);
        int len = LenOfNumbers(priority);
        int PRIORITY = priority;
        
        for (int i = len-1; i>-1; i--)
        {
            buff[l+i] = (char)((int)'0') + PRIORITY%10;
            PRIORITY /= 10;
        }
        aloc->fillDescription(buff);
    }
    aloc->clearDescript();
    LoadFile.close();
    return aloc;
}

weapon* itemLoader::weapon(const char* Name)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Weapons.txt");
    char buff[30] = {};
    int TYPE = -1;
    while (!LoadFile.eof())
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            TYPE++;
            inflation(buff);
            if (equals(buff,Name))
            {
                break;
            }
        }
    }
    LoadFile.close();
    return weapon(TYPE);
}

weapon* itemLoader::weapon(const int type)
{
ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Weapons.txt");

class weapon* aloc;

char buff[40] = {};

int dmg    = 0;
int turn   = 0;
int crit   = 0;
int splash = 0;
int stun   = 0;
int bleed  = 0;
int price  = 0;
    
for (int item = 0; item < type+1;)
{
    LoadFile>>buff;
    
    if (!LoadFile.eof() && buff[0] == '$')
    {
        LoadFile>>buff;
        LoadFile>>dmg;
        LoadFile>>turn;
        LoadFile>>crit;
        LoadFile>>splash;
        LoadFile>>stun;
        LoadFile>>bleed;
        LoadFile>>price;
        item++;
    }
}

    aloc = new class weapon(dmg, turn, crit, splash, stun, bleed, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
        while (!LoadFile.eof())
        {
            char add[30] = {};
            
            LoadFile>>add;
            
            if (add[0] == '^')
            {
                aloc->fillDescription(buff);
                clean(buff, 40);
            }
            
            else if(add[0] == '$')
            {
                clean(buff, 40);
                break;
            }
            else
            {
                addToString(buff, add);
            }
        }
    aloc->fillDescription(" ");
    aloc->fillDescription("Stats:");
    aloc->fillDescription(" ");
    
        if (dmg)
        {
            char descr[] = {"Dmg    +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(dmg);
            int DMG = dmg;
            for (int i = len-1; i>-1; i--)
            {
                buff[i+l] = (char)((int)'0') + DMG%10;
                DMG /= 10;
            }
            aloc->fillDescription(buff);
        }
        if (turn)
        {
            char descr[] = {"Turns  +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(turn);
            int TURN = turn;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + TURN%10;
                TURN /= 10;
            }
            aloc->fillDescription(buff);
        }
        if (bleed)
        {
            char descr[] = {"Pirs   +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(bleed);
            int BLEED = bleed;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + BLEED%10;
                BLEED /= 10;
            }
            aloc->fillDescription(buff);
        }
        if (crit)
        {
            char descr[] = {"Crit   +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(crit);
            int CRIT = crit;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + CRIT%10;
                CRIT /= 10;
            }
            addToString(buff, "%");
            aloc->fillDescription(buff);
        }
        if (splash)
        {
            char descr[] = {"Splash +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(splash);
            int SPLASH = splash;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + SPLASH%10;
                SPLASH /= 10;
            }
            addToString(buff, "%");
            aloc->fillDescription(buff);
        }
        if (stun)
        {
            char descr[] = {"Stun   +"};
            clean(buff, 40);
            int l = unsigned(strlen(descr));
            strcpy_s(buff, l, descr);
            int len = LenOfNumbers(stun);
            int STUN = stun;
            
            for (int i = len-1; i>-1; i--)
            {
                buff[l+i] = (char)((int)'0') + STUN%10;
                STUN /= 10;
            }
            addToString(buff, "%");
            aloc->fillDescription(buff);
        }
    aloc->clearDescript();
    LoadFile.close();
return aloc;
}

class potion* itemLoader::potion  (const int type)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Helmets.txt");
    
    class potion* aloc;
    
    char buff[40] = {};
    
    int hp      = 0;
    int price   = 0;
    
    for (int item = 0; item < type+1;)
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            LoadFile>>hp;
            LoadFile>>price;
            item++;
        }
    }

    aloc = new class potion(hp, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
    while (!LoadFile.eof())
    {
        char add[30] = {};
        
        LoadFile>>add;
        
        if (add[0] == '^')
        {
            aloc->fillDescription(buff);
            clean(buff, 40);
        }
        
        else if(add[0] == '$')
        {
            clean(buff, 40);
            break;
        }
        else
        {
            addToString(buff, add);
        }
    }
    aloc->clearDescript();
    LoadFile.close();
    return aloc;
}

class kit* itemLoader::kit     (const int type)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Kit.txt");
    
    class kit* aloc;
    
    char buff[40] = {};
    
    int hp      = 0;
    int price   = 0;
    
    for (int item = 0; item < type+1;)
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            LoadFile>>hp;
            LoadFile>>price;
            item++;
        }
    }
    
    aloc = new class kit(hp, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
    while (!LoadFile.eof())
    {
        char add[30] = {};
        
        LoadFile>>add;
        
        if (add[0] == '^')
        {
            aloc->fillDescription(buff);
            clean(buff, 40);
        }
        
        else if(add[0] == '$')
        {
            clean(buff, 40);
            break;
        }
        else
        {
            addToString(buff, add);
        }
    }
    aloc->clearDescript();
    LoadFile.close();
    return aloc;
}
class bandages* itemLoader::bandages(const int type)
{
    ifstream LoadFile("/Users/aleksandrlitvickij/Desktop/Веселый Зомби Фермер/Items/Equipment/Helmets.txt");
    
    class bandages* aloc;
    
    char buff[40] = {};
    
    int hp      = 0;
    int price   = 0;
    
    for (int item = 0; item < type+1;)
    {
        LoadFile>>buff;
        
        if (!LoadFile.eof() && buff[0] == '$')
        {
            LoadFile>>buff;
            LoadFile>>hp;
            LoadFile>>price;
            item++;
        }
    }
    
    aloc = new class bandages(hp, price);
    inflation(buff);
    aloc->fillDescription(buff);
    aloc->fillName(buff);
    aloc->fillDescription(" ");
    LoadFile>>buff;
    while (!LoadFile.eof())
    {
        char add[30] = {};
        
        LoadFile>>add;
        
        if (add[0] == '^')
        {
            aloc->fillDescription(buff);
            clean(buff, 40);
        }
        
        else if(add[0] == '$')
        {
            clean(buff, 40);
            break;
        }
        else
        {
            addToString(buff, add);
        }
    }
    aloc->clearDescript();
    LoadFile.close();
    return aloc;
}
class grenade* itemLoader::grenade (const int type)
{
    return 0;
}
class bomb* itemLoader::bomb    (const int type)
{
    return 0;
}
class revive* itemLoader::revive  (const int type)
{
    return 0;
}

class potion* itemLoader::potion  (const char* Name)
{
    return 0;
}
class kit* itemLoader::kit     (const char* Name)
{
    return 0;
}
class bandages* itemLoader::bandages(const char* Name)
{
    return 0;
}
class grenade* itemLoader::grenade (const char* Name)
{
    return 0;
}
class bomb* itemLoader::bomb    (const char* Name)
{
    return 0;
}
class revive* itemLoader::revive  (const char* Name)
{
    return 0;
}

item* itemLoader::getRandomConsumable()
{
    return 0;
}