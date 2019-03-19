#include "Bomb.hpp"
#include <iostream>

int Bomb::number = -1;

Bomb::Bomb()
{
    number++;
    ID = 9;
}

void Bomb::setPosition(int maxRandomX, int maxRandomY)
{
    pos.x = function::random(maxRandomX);
    pos.y = function::random(maxRandomY);
}

