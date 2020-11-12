#pragma once
class MainMenu
{
private:
    bool start;
protected:
    bool loading;
    const int x;
    const int y;
    char** screen;
    void print();
    virtual void clear();
    void selector(const int, const char*);
    void midler(const int, const char*);
    void framer(const int,const int,const int,const int);
public:
    MainMenu(int i,int j);
    void show(int selector = 1);
    ~MainMenu();
};