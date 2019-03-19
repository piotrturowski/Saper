#include "PrepareArt.hpp"
#include <iostream>
#include <string>
#include "Button.hpp"
#ifndef BaseArt_hpp
#define BaseArt_hpp

class BaseArt
{
public:
    BaseArt();
    PrepareArt hide;
    PrepareArt number0;
    PrepareArt number1;
    PrepareArt number2;
    PrepareArt number3;
    PrepareArt number4;
    PrepareArt number5;
    PrepareArt number6;
    PrepareArt number7;
    PrepareArt number8;
    PrepareArt bomb;
    PrepareArt mark;
    Button restart;
    Button exit;
};

#endif
