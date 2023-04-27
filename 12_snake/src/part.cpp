#include <iostream>

#include "part.h"

using namespace std;

std::string Part::unicode_letters[26] = {"🅐", "🅑", "🅒", "🅓", "🅔", "🅕", "🅖", "🅗", "🅘", "🅙", "🅚", "🅛", "🅜", "🅝", "🅞", "🅟", "🅠", "🅡", "🅢", "🅣", "🅤", "🅥", "🅦", "🅧", "🅨", "🅩"};
    
Part::Part(int x, int y, std::string d, int value)
{
    this->x = x;
    this->y = y;
    this->data = d;
    this->value = value;
    if(value < 0 || value > 25)
    {
        value = 0;
    }
}

void Part::eat()
{
    x = 0;
    y = 0;
}

Part::~Part()
{
    delete next;
}

void Part::draw()
{
    if(x != 0 && y != 0)
    {
        cout << "\033[" << y << ";" << x << "H" << data;
    }
    if(next)
    {
        next->draw();
    }
}

void Part::move(int x, int y)
{
    if (next && x) // Wenn der nächste Teil existiert und die x-Koordinate existiert
    {
        next->move(this->x, this->y); // Rekursiver Aufruf mit den aktuellen Koordinaten
    }
    this->x = x;
    this->y = y;
}

bool Part::contains(int x, int y)
{
    if (x == this->x && y == this->y)
    {
        return true;
    }
    if (next)
    {
        return next->contains(x, y); // Rekursiver Aufruf mit dem nächsten Teil
    }
    return false;
}

Part* Part::add(Part* p)
{
    if (next)
    {
        next->add(p); // Rekursiver Aufruf mit dem nächsten Teil
    }
    else
    {
        next = p;
    }
    return this;
}

Part* Part::get(int x, int y)
{
    if (x == this->x && y == this->y)
    {
        return this;
    }
    if (next)
    {
        return next->get(x, y);
    }
    return nullptr;
}

Part* Part::remove(int x, int y)
{
    Part* p = nullptr;

    if (x == this->x && y == this->y)
    {
        p = next;
        next = nullptr;
        return p;
    }
    else
    {
        if (next)
        {
            next = next->remove(x, y);
        }
        return this;
    }
}