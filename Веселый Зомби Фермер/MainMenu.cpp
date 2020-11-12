#include <iostream>
#include "MainMenu.h"
#include "kbhit.h"
#include <unistd.h>
#include "keys.h"
#include "GameMenu.h"
#include "texts_1.h"
using namespace std;

MainMenu::MainMenu(int i, int j):
x(i),
y(j),
start(false),
loading(false)
{
    screen = new char * [x];
    for(int i = 0; i<x; i++)
    {
        screen[i] = new char [y];
    }
    clear();
    screen[0][0]   = ' ';
    screen[0][y-1] = ' ';
    
    framer(0, x, 0, y);
    
}
void MainMenu::print()
{
    cout<<endl<<endl;
    for(int i = 0; i<x; i++)
    {
//        cout<<"\t\t\t\t";
        for(int j = 0; j<y; j++)
        {
            if(screen[i][j] == 30)
            {
                cout<<"☼";
            }
            else if(screen[i][j] == 31)
            {
                cout<<"⚇";
            }
            else if(screen[i][j] == '#')
            {
                cout<<"√";
            }
            else if(screen[i][j] == '$')
            {
                cout<<"❦";
            }
            else if(screen[i][j] == '^')
            {
                cout<<"✖";
            }
            else if(screen[i][j] == 9)
            {
                cout<<"☽";
            }
            else if(screen[i][j] == 1)
            {
                cout<<"✙";
            }
            else if(screen[i][j] == 2)
            {
                cout<<"◕";
            }
            else if(screen[i][j] == 3)
            {
                cout<<"☩";
            }
            else if(screen[i][j] == 4)
            {
                cout<<"◣";
            }
            else if(screen[i][j] == 5)
            {
                cout<<"◢";
            }
            else if(screen[i][j] == 6)
            {
                cout<<"☐";
            }
            else if(screen[i][j] == 7)
            {
                cout<<"●";
            }
            else if(screen[i][j] == 8)
            {
                cout<<"◼";
            }
            else
            {
                cout<<screen[i][j];
            }
        }
        cout<<endl;
    }
}

void MainMenu::clear()
{
    for(int i = 1; i<x-1; i++)
    {
        for(int j = 1; j<y-1; j++)
        {
            screen[i][j] = ' ';
        }
    }
}

void MainMenu::show(int selection)
{
    while(!start)
    {
    
    while(!kbhit())
    {
    switch (selection)
    {
        case 1:
            selector(25,texts_1::game);
            break;
        case 2:
            selector(27,texts_1::load);
            break;
        case 3:
            selector(29,texts_1::quit);
            break;
    }
    midler(10,texts_1::welcome);
    midler(11,texts_1::name);
    midler(25,texts_1::game);
    midler(27,texts_1::load);
    midler(29,texts_1::quit);
    for (int i = 0; i<strlen(texts_1::credits); i++)
    {
        screen[x-2][i+y-strlen(texts_1::credits)-2] = texts_1::credits[i];
    }
    print();
    clear();
    usleep(500000);
    }
    int g = getchar();
    if(g == keys::W||g == keys::w)
    {
        
        --selection;
        
        if(selection < game)
        {
            selection = quit;
        }
    }
    
    if (g == keys::S|| g == keys::s)
    {
        
        ++selection;
        
        if(selection > quit)
        {
            selection = game;
        }
    }
    
    if ((g == keys::f||g == keys::F) && selection == quit)
    {
        exit(0);
    }

    if ((g == keys::f||g == keys::F) && selection == load)
    {
        clear();
        start   = true;
        loading = true;
    }
    if ((g == keys::f||g == keys::F) && selection == game)
    {
        clear();
        start   = true;
        loading = false;
    }

    show(selection);
}
        GameMenu obj2 (x,y,SidePlank,BottomPlank, loading);
        obj2.show();
}

void MainMenu::midler(const int position, const char * name)
{
    for (int i = 0; i<strlen(name); i++)
    {
        screen[position][i+(y/2-unsigned(strlen(name))/2)] = name[i];
    }
 
}

void MainMenu::framer(int from_v, int to_v, int from_h, int to_h)
{
    clear();
    for(int i = from_h+1; i<to_h-1;i++)
    {
        screen[from_v][i] = '_';
    }
    
    for(int i = from_h; i<to_h;i++)
    {
        screen[to_v-1][i] = '_';
    }
    
    
    for(int i = from_v+1; i<to_v;i++)
    {
        screen[i][from_h] = '|';
    }
    
    for(int i = from_v+1; i<to_v;i++)
    {
        screen[i][to_h-1] = '|';
    }

}

void MainMenu::selector(const int position,const char * name)
{
    if(strlen(name)%2 == 1)
    {
        screen[position][(y/2-unsigned(strlen(name))/2)-1] = '<';
        screen[position][(y/2+unsigned(strlen(name))/2)+1] = '>';
    }
    else
    {
    screen[position][(y/2-unsigned(strlen(name))/2)-1] = '<';
    screen[position][(y/2+unsigned(strlen(name))/2)]   = '>';
    }
}

MainMenu::~MainMenu()
{
    for(int i = 0; i < x; i++)
    {
        delete [] screen[i];
    }
    delete [] screen;
}