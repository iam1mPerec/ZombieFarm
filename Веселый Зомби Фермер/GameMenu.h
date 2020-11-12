#pragma once
#include "MainMenu.h"
#include "ptime.h"
#include "field.h"
#include "SideMenu.h"
#include "resources.h"
#include "DialogBox.h"
#include "GoodList.h"
#include "BadList.h"
#include "ProgressMenu.h"
#include "plant.h"
#include "plants.h"
#include "work.h"
#include "building.h"
#include "events_list.h"
#include "constructions.h"
#include "Shop.h"
#include "Unit.h"
#include "Tank.h"
#include "Healer.h"
#include "Zombie.h"
#include "UpGrade.h"
#include "Party.h"
#include "Horde.h"
#include "Animation.h"
#include "Inventory.h"
#include "ItemLoader.h"

class GameMenu: public MainMenu
{
    int SidePlank;
    int BottomPlank;
    int x1;
    int x2;
    int y1;
    int y2;
    item* usable;
    bool battle;
    bool animate;
    bool capture;
    bool selling;
    bool win;
    bool revive;
    bool NightRaid;
    
    events_list   list;
    field         MyField;
    SideMenu      side;
    resources     Res;
    DialogBox     Dial;
    GoodList      farmers;
    BadList       stock;
    ProgressMenu  progress;
    constructions possession;
    animation     Animation;
    inventory     items;
    itemLoader    loader;
    
    Horde horde;
    UpGrade upgrade;
    party troops;

    enum plants plant;
    enum shop store;
    
public:
    GameMenu(int x, int y, int k, int l, bool loading);
    static ptime GlobalTime;
    void showWaves();
    void deleteWaves();
    void show();
    void seeder();
    void ZombieStunnedAnimation();
    void ZombieCritAnimation();
    void ZombiePirsAnimation();
    void ZombieBuffAnimation();
    void ZombieBiteAninmation();
    void healingAnimation();
    void winScreen();
    void loseScreen();
    void showTime();
    void showSide();
    int  checkSpase();
    void showDialog();
    void showFarmers();
    void mapResources();
    void infoScreen();
    void functional();
    void scaterShot(const int DMG);
    void heal();
    void stun();
    void crit();
    void pirs();
    void massHealAnimation();
    void massHeal(const int factor);
    void massExp(const int factor);
    void equip(item * item, char * name, unit* unit, bool &exit);
    void use  (item * item, char * name, unit* unit, bool &exit);
    void save();
    void load();
    void clear();
    void hide();
    void attack();
    void splash(const int dmg, const int splash);
    void drawInventory();
    void drawStats();
    void swapCards(const int y1,const int x1,const int y2,const int x2);
    void fight();
    int  allMissingHp();
    void drawUpgrade();
    void reveal();
    void addUnit();
    void drawAll();
    void drawUndead();
    void massAttack(const int Dmg);
    void whosTurn();
    void drawDescription();
    void setUndead();
    bool checkWasted()         const;
    int  humanToSlash()        const;
    int  humanToSlash_revers() const;
    void itemSelector();
    void blink(const int position, bool present);
    void slashedAnimation(const int dmg);
    void zombieSelector();
    void choose(const int row,const int card);
    int  cardsInRow(const int row) const;
    int  buildingExpenses(const enum structures type);
    void Building(const enum structures);
    void mapping(int &position,const int num);
    void setPlants(enum plants p);
    void CharOut(const char ch, const int y,const int x);
    void CharOut(const int,const int,const int);
    void plantSelector();
    void selector();
    void upgradeHouse();
    void Zselector(const int position);
    void choosing2lvl(const int x2);
    void setLoading(bool set);
    void manipulator_Main();
    void HumanSlashedAnimation(const int position);
    void resetVariables();
    void resetTurns();
    void manipulator_equip();
    void manipulator_Plants();
    void manipulator_Building();
    void manipulator_Work();
    void manipulator_Exit();
    void manipulator_Select();
    void manipulator_Capture();
    void manipulator_Attack();
    void manipulator_Battle();
    void manipulator_lvling();
    void manipulator_upgrading();
    void manipulator_Choosing();
    void manipulator_firstAid();
    void manipulator_Shop();
    void manipulator_Buy();
    void manipulator_Sell();
    void manipulator_Amount();
    void manipulator_Abilities();
    void manipulator_Slashing();
    void manipulator_Inventory();
    void manipulator_Bombing();
    void traiding(const int num);
    bool isBuilding(const char * name) const;
    bool isPlant(const char * name) const;
    bool isJob(const char * name) const;
    ~GameMenu();
};
