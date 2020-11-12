#pragma once
#include "event.h"
#include "jobs.h"
#include "Farmer.h"
#include "DialogBox.h"
#include "resources.h"


class work: public event
{
   enum jobs option;
   farmer * farmboy;
   DialogBox &Box;
   resources &Res;
    
public:
    farmer * getFarmer();
    work(farmer * f, DialogBox &Box, enum jobs type, resources &Res);
    work(farmer * f, DialogBox &Box, enum jobs type, resources &Res, int day, int hour, int min);
    void create(farmer * f, DialogBox &Box, enum jobs type, resources &Res);
    char** getName(const int i) const;
    void triger();
    void Del();
    int getOption() const;
};