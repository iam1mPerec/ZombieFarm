#pragma once
#include "Farmer.h"
#include "screen.h"
#include "DialogBox.h"

class event
{
protected:
    char * name;
    char header[y-SidePlank-3] = {};
    int pSec;
    int pDay;
    int pHour;
    int pMin;
    int priority;
    bool done;
    bool plant;
    event * Next;


public:
    event();
    virtual void triger() = 0;
    virtual void Del();
    virtual int getReward();
    virtual int getCost();
    virtual int getAmmount();
    virtual int getOption() const;
    virtual char ** getMatrix();
    virtual bool show_progress() const;
    void in_progress();
    void setNext(event* new_event);
    char * getHeader();
    event * getNext();
    int getTime() const;
    char *getName();
    int getDay() const;
    int getHour() const;
    int getMin() const;
    int getSec() const;
    int getPriority();
};