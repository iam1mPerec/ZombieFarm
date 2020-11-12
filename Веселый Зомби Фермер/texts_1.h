#pragma once
class texts_1
{
    texts_1();
public:
    const static char welcome[];
    const static char name[];
    const static char credits[];
    const static char game[];
    const static char load[];
    const static char quit[];
    const static char error[];
    const static char accept[];
    const static char time[];
    const static char day[];
};
const char texts_1::welcome[]("Welcome to the game");
const char texts_1::name[]("Zombie's Farm Frenzy");
const char texts_1::credits[]("Deadly Spirit");
const char texts_1::game[]("New Game");
const char texts_1::load[]("Load");
const char texts_1::quit[]("Exit");
const char texts_1::error[]("This option is not yet available");
const char texts_1::accept[]("<ok>");
const char texts_1::time[]("Time:");
const char texts_1::day[]("Day:");