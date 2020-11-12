#include <iostream>
#include "DialogBox.h"
#include "screen.h"
#include "GameMenu.h"

DialogBox::DialogBox():
px(ScreenSize::x - BottomPlank),
py(SidePlank),
NumberOfLines(px/2)
{
    Box = new char * [px];
    for (int i = 0; i<px; i++)
    {
        Box[i] = new char [py];
    }
    clearBox();
}

void DialogBox::lineDown(const int line)
{
    for (int i = 0; i<py; i++)
    {
        Box[line*2-1][i] = Box[line*2-3][i];
    }
}

void DialogBox::AddQuote(const char * quote)
{
    for (int j = NumberOfLines; j>1; --j)
    {
        lineDown(j);
    }

    for (int i = 11, j = 0; i<strlen(quote)+11; i++,j++)
    {
        Box[1][i+1] = quote[j];
    }
    
    for (int i = unsigned(strlen(quote))+12; i<py; i++)
    {
        Box[1][i] = ' ';
    }
    Box[1][1] = '[';
    Box[1][2] = (char)((int)'0')+GameMenu::GlobalTime.getDay()/10;
    Box[1][3] = (char)((int)'0')+GameMenu::GlobalTime.getDay()%10;
    Box[1][4] = '/';
    Box[1][5] = (char)((int)'0')+GameMenu::GlobalTime.getHour()/10;
    Box[1][6] = (char)((int)'0')+GameMenu::GlobalTime.getHour()%10;
    Box[1][7] = '/';
    Box[1][8] = (char)((int)'0')+GameMenu::GlobalTime.getMin()/10;
    Box[1][9] = (char)((int)'0')+GameMenu::GlobalTime.getMin()%10;
    Box[1][10] = ']';
}

void DialogBox::clearBox()
{
    {
        for(int j = 1; j<px; j++)
        {
            for (int i = 1; i<py; i++)
            {
                    Box[j][i] = ' ';
            }
        }
    }
}

int DialogBox::getPy() const
{
    return py;
}
int DialogBox::getPx() const
{
    return px;
}
char** DialogBox::getBox() const
{
    return Box;
}