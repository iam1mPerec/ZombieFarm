#pragma once
#include "event.h"
#include "buildings.h"
#include "constructions.h"
#include "events_list.h"

class building: public event
{
    structures option;
    
    char** screen;
    farmer * farmboy;
    field &MField;
    event * first;
    constructions &possession;
    DialogBox &Box;
    
public:
    building(field &MField, farmer * f, DialogBox &Box,
             structures building_type, constructions &possession, char** ar);
    building(field &MField, farmer * f, DialogBox &Box,
             structures building_type, constructions &possession, char** ar, int day, int hour, int minute);
    void create(field &MField, farmer * f, DialogBox &Box,
                        structures building_type, constructions &possession, char** ar, int day, int hour, int minute);
    void set_option(structures i);
    void Del();
    farmer * getFarmer();
    structures get_option();
    int getOption() const;
    void triger();
};