#include <iostream>
#include "Inventory.h"

using namespace std;

inventory::inventory():
Head(nullptr),
Tail(nullptr),
count(0)
{
    
}

item* inventory::getItem(const int Position)
{
    item* aloc = Head;
    
    int position = Position;
    
    if (position < 0)
    {
        position = 0;
    }
    if (position > count)
    {
        position = count;
    }
    
    for (int i = 0; i<position; i++)
    {
        aloc = aloc->getNext();
    }
    
    return aloc;
}

void inventory::addItem(item *aloc)
{
    if (!count)
    {
        Head = aloc;
        Tail = Head;
    }
    else
    {
        Tail->setNext(aloc);
        Tail = Tail->getNext();
    }
    count++;
}

int inventory::getNumberOfPages() const
{
    bool remainder = count%18;
    int pages = (count/18 + remainder)-1;
    
    if (pages == -1)
    {
        pages = 0;
    }
    return pages;
}

void inventory::removeItem(const int COUNT)
{
    item* aloc = Head;
    if (!COUNT)
    {
        Head = Head->getNext();
        delete aloc;
    }
    else if(COUNT>0 && COUNT < count)
    {
        for (int i = 0; i<COUNT-1; i++)
        {
            aloc = aloc->getNext();
        }
        item* remove = aloc->getNext();
        aloc->setNext(remove->getNext());
        delete remove;
        
        if (count == COUNT+1)
        {
            Tail = aloc;
        }
    }
    else
    {
    
    }
    count--;
}

void inventory::replaceItem(item *ITEM, const int COUNT)
{
    if (ITEM != nullptr)
    {
        item* aloc = Head;
        if (!COUNT)
        {
            ITEM->setNext(aloc->getNext());
            Head = ITEM;
            delete aloc;
        }
        else if(COUNT>0 && COUNT <= count)
        {
            for (int i = 0; i<COUNT-1; i++)
            {
                aloc = aloc->getNext();
            }
            item* remove = aloc->getNext();
            aloc->setNext(ITEM);
            ITEM->setNext(remove->getNext());
            delete remove;
            
            if (count == COUNT)
            {
                Tail = ITEM;
            }
        }
    }
    else
    {
        removeItem(COUNT);
    }
}

int inventory::getCount() const
{
    return count;
}