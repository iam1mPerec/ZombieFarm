#include <iostream>
#include "SideMenu.h"
#include "screen.h"
#include "keys.h"
#include "GameMenu.h"
#include "plants.h"
#include "buildings.h"
#include "jobs.h"

using namespace std;

SideMenu::SideMenu():
sx(ScreenSize::x - ScreenSize::BottomPlank-1),
sy(ScreenSize::y - ScreenSize::SidePlank-1),
option(0),
NumberOfOptions(6),
menuOption(1),
CurentNumberOfOptions(6)
{
    options = new char * [NumberOfOptions];
    for (int i = 0; i<NumberOfOptions; i++)
    {
        options[i] = new char [sy];
    }
    
    ar = new char * [sx];
    for (int i = 0; i<sx; i++)
    {
        ar[i] = new char [sy];
    }
    clear();
}

void SideMenu::addLvl(char *text, const int lvl)
{
    int l = unsigned(strlen(text));
    text[l]   = '(';
    text[l+1] = lvl + (char)((int)'0');
    text[l+2] = ')';
    text[l+3] = '\0';
}

void SideMenu::option_abilities(const int type, const int ability_1, const int ability_2,
                                const int ability_3, const int ability_4, const int ability_5)
{
    switch (type)
    {
        case sniper:
            clearOptions();
            strcpy(options[0],talents[ScaterShot]);
            strcpy(options[1],talents[AimedShot]);
            strcpy(options[2],talents[SharpEye]);
            strcpy(options[3],talents[BurstingShot]);
            strcpy(options[4],talents[DeathBlow]);
            break;
        case healer:
            clearOptions();
            strcpy(options[0],talents[Gorge]);
            strcpy(options[1],talents[QuickHands]);
            strcpy(options[2],talents[Heal]);
            strcpy(options[3],talents[MassHeal]);
            strcpy(options[4],talents[Revive]);
            break;
        case tank:
            clearOptions();
            strcpy(options[0],talents[Bash]);
            strcpy(options[1],talents[Smash]);
            strcpy(options[2],talents[Toughness]);
            strcpy(options[3],talents[Stamina]);
            strcpy(options[4],talents[Strength]);
            break;
            
        default:
            break;
    }
    
    addLvl(options[0], ability_1);
    addLvl(options[1], ability_2);
    addLvl(options[2], ability_3);
    addLvl(options[3], ability_4);
    addLvl(options[4], ability_5);
    
    strcpy(options[5],"Exit");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::clearOptions()
{
    for (int j = 0; j<NumberOfOptions; j++)
    {
        for (int i = 0; i<sy; i++)
        {
            options[j][i] = ' ';
        }
    }
    
    for (int i = 0; i<NumberOfOptions; i++)
    {
        options[i][0] = '$';
    }
}

void SideMenu::setCurentNumberOfOptions()
{
    int j = 0;
    for (int i = 0; i<NumberOfOptions; i++)
    {
        if(options[i][0] != '$')
        {
            j++;
        }
    }
    CurentNumberOfOptions = j;
}

void SideMenu::option_main()
{
    clearOptions();
    strcpy(options[0],"Planting");
    strcpy(options[1],"Building");
    strcpy(options[2],"Activities");
    strcpy(options[3],"Troops");
    strcpy(options[4],"Save");
    strcpy(options[5],"Exit");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
        selector(option);
}

void SideMenu::setOption(const int i)
{
    option = i;
}

void SideMenu::option_attack()
{
    clearOptions();
    strcpy(options[0],"Attack");
    strcpy(options[1],"Skills");
    strcpy(options[2],"Items");
    strcpy(options[3],"Protect");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_planting()
{
    clearOptions();
    strcpy(options[0],plants[0]);
    strcpy(options[1],plants[1]);
    strcpy(options[2],plants[2]);
    strcpy(options[3],plants[3]);
    strcpy(options[4],plants[4]);
    strcpy(options[5],plants[5]);
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}
void SideMenu::option_building()
{
    clearOptions();
    strcpy(options[0],buildings[fence]);
    strcpy(options[1],buildings[tunel]);
    strcpy(options[2],buildings[house]);
    strcpy(options[3],buildings[tent]);
    strcpy(options[4],buildings[barracks]);
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}
void SideMenu::option_working()
{
    clearOptions();
    strcpy(options[0],jobs[chop]);
    strcpy(options[1],jobs[adventure]);
    strcpy(options[2],jobs[collect]);
    strcpy(options[3],jobs[shop]);
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_healing()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1],"Choose");
    strcpy(options[2],"who would you like");
    strcpy(options[3],"to heal");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_quiting()
{
    clearOptions();
    strcpy(options[0],"Yes");
    strcpy(options[1],"No");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_shop()
{
    clearOptions();
    strcpy(options[0],"Buy");
    strcpy(options[1],"Sell");
    strcpy(options[2], "Hire Farmers");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_amount()
{
    clearOptions();
    strcpy(options[0],"100"   );
    strcpy(options[1],"250"   );
    strcpy(options[2],"500"   );
    strcpy(options[3],"1 000" );
    strcpy(options[4],"5 000" );
    strcpy(options[5],"10 000");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_buy()
{
    clearOptions();
    strcpy(options[0],"Wood"   );
    strcpy(options[1],"Seeds"  );
    strcpy(options[2],"Food"   );
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_sell()
{
    clearOptions();
    strcpy(options[0],"Wood" );
    strcpy(options[1],"Seeds");
    strcpy(options[2],"Food" );
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_equip()
{
    clearOptions();
    strcpy(options[0]," " );
    strcpy(options[1],"Select");
    strcpy(options[2],"A unit" );
    strcpy(options[3],"That you wish");
    strcpy(options[4],"To equip");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_battle()
{
    clearOptions();
    strcpy(options[0],"Find Zombies" );
    strcpy(options[1],"Rearrange");
    strcpy(options[2],"lvl Up" );
    strcpy(options[3],"Feed Units");
    strcpy(options[4],"Hire Units");
    strcpy(options[5],"Equip");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
    selector(option);
}

void SideMenu::option_selecting()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1]," ");
    strcpy(options[2],"Selection is in");
    strcpy(options[3],"progress");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_swap()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1],"Select 2 cards");
    strcpy(options[2],"To swap them");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_slashing()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1],"select an enemy.");
    strcpy(options[2],"the one you");
    strcpy(options[3],"dislike");
    strcpy(options[4],"The most");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_upgrading()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1],"Select a unit     ");
    strcpy(options[2],"With a skill point");
    strcpy(options[3],"To upgrade him    ");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

void SideMenu::option_lvling()
{
    clearOptions();
    strcpy(options[0]," ");
    strcpy(options[1],"Select new class");
    strcpy(options[2],"Tank sniper");
    strcpy(options[3],"Or Medic");
    setCurentNumberOfOptions();
    for (int i = 0; i<CurentNumberOfOptions; i++)
    {
        midler(i, options);
    }
}

int SideMenu::getMenuOption() const
{
    return menuOption;
}

void SideMenu::clear()
{
    for(int j = 0; j<sx; j++)
    {
        for (int i = 0; i<sy; i++)
        {
            ar[j][i] = ' ';
        }
    }
}

int SideMenu::get_sx() const
{
    return sx;
}
int SideMenu::get_sy() const
{
    return sy;
}
char** SideMenu::get_screen() const
{
    return ar;
}

void SideMenu::midler(const int position, const char * name)
{
    for (int i = 0; i<strlen(name); i++)
    {
        ar[position][i+(sy/2-unsigned(strlen(name))/2)] = name[i];
    }
}



void SideMenu::midler(const int num, char **name)
{
    for (int i = 0; i<strlen(name[num]); i++)
    {
        ar[num*2+2][(sy-unsigned(strlen(name[num])))/2+i] = name[num][i];
    }
}

void SideMenu::selector(const int num)
{
    clearSelector();
    
    if(strlen(options[num])%2 == 1)
    {
        ar[num*2+2][(sy/2-unsigned(strlen(options[num]))/2)-1] = '<';
        ar[num*2+2][(sy/2+unsigned(strlen(options[num]))/2)+1] = '>';
    }
    else
    {
        ar[num*2+2][(sy/2-unsigned(strlen(options[num]))/2)-1] = '<';
        ar[num*2+2][(sy/2+unsigned(strlen(options[num]))/2)]   = '>';
    }
}

void SideMenu::clearSelector()
{
    for (int j = 1; j<sy-1; j++)
    {
        for(int i  = 1; i<sx-1; i++)
        {
            if(ar[i][j] == '<'||ar[i][j] == '>')
            {
                ar[i][j] = ' ';
            }
        }
    }
}

void SideMenu::slider(const char s)
{
    if(s == keys::W||s == keys::w)
    {
        
        --option;
    
        if(option < 0)
        {
            option = CurentNumberOfOptions-1;
        }
        selector(option);
    }
    
    if (s == keys::S|| s == keys::s)
    {
        
        ++option;
        
        if(option > CurentNumberOfOptions-1)
        {
            option = 0;
        }
        selector(option);
    }
}

void SideMenu::setMenuOption(const int i)
{
    setOption(0);
    menuOption = i;
}

int SideMenu::getOption() const
{
    return option;
}