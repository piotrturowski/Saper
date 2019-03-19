#include  <SFML/Graphics.hpp>
#include "function.hpp"
#include "Object.hpp"
#ifndef Bomb_hpp
#define Bomb_hpp

class Bomb : public Object
{
public:
    Bomb();
    static int number;
    void setPosition(int maxRandomX, int maxRandomY);
};

#endif
