#pragma once
#include "farmer.h"
#include "DialogBox.h"

class BadList
{
    farmer * Head;
    farmer * Current;
    DialogBox &Box;
    int count;
    
public:
        BadList(DialogBox &Box);
        void hire();
};