/*
 symbols of Table

 number  0|1|2|3|4|5|6|7|8|9|10|11
  -is-   -------------------------
 object  E|1|2|3|4|5|6|7|8|B|H |M

The Legend
E - empty
B - The Bomb
H - hide
M - Mark
1,2,3...,8 - numbers
*/

#ifndef Saper_hpp
#define Saper_hpp
#include "system.hpp"
#include "CreatorMaps.hpp"
#include "Bomb.hpp"
#include "function.hpp"
#include "BaseArt.hpp"
#include "Button.hpp"

class Saper
{
private:
    CreatorMaps Map;
    CreatorMaps DisplayedMap;
    BaseArt baseArt;
    Bomb Bomb[10];
public:
    Saper(int z);
    void run(System& sys);
    void include(System& sys);
    void logic(System& sys);
    void draw(System& sys);
    void setup(System& sys);
};

#endif
