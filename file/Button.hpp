#ifndef Button_hpp
#define Button_hpp
#include "PrepareArt.hpp"
#include <iostream>
#include <string>

class Button : public PrepareArt
{
private:
    bool isHidden;
public:
    Button(std::string name);
    void Hidden(bool status);
    void setPosition(int x,int y);
    bool isActive(sf::RenderWindow& window);
    bool getisHidden();
};

#endif
