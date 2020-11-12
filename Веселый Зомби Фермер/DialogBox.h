#pragma once

class DialogBox
{
    int py;
    int px;
    int NumberOfLines;
    
    char ** Box;
    
    void lineDown(const int line);
    
public:
    DialogBox();
    void AddQuote(const char* quote);
    void clearBox();
    int getPy() const;
    int getPx() const;
    char** getBox() const;
};