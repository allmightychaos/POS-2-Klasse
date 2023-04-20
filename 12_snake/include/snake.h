#ifndef SNAKE_H
#define SNAKE_H

#include "part.h"

enum Direction
{
    East,
    North,
    West,
    South
};

class Snake
{
private:
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    Direction dir = South;
    Part *border = nullptr;
    Part *food = nullptr;
    Part *body = nullptr;

public:
    Snake();
    ~Snake();
    void draw();
    int update();
    inline void set_direction(Direction d) { dir = d; }
};

#endif