#include <iostream>
#include "kit.h"

using namespace std;

kit::kit(const int Hp, const int Price):
consumables(consume::kit,Price),
hp(Hp)
{
    fillTitle("Kit");
}

