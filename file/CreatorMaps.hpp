#include "SFML/Graphics.hpp"
#ifndef CreatorMaps_hpp
#define CreatorMaps_hpp

class CreatorMaps
{
    int X;
    int Y;
    int ** tab;
public:
    sf::Texture Texture;
    sf::Sprite Sprite;
    void create(int x, int y);
    void show();
    void reset();
    void reset(int number);
    void loadSprite();
    void setID(int x, int y,int ID);
    void setID(sf::Vector2i pos,int ID);
    int getX();
    int getY();
    int getID_on_the_Tab(sf::Vector2i pos);
    int getID_on_the_Tab(int x,int y);
    CreatorMaps(int xy = 10);
    CreatorMaps(int x,int y);
    CreatorMaps(int x,int y,std::string adres);

};

#endif
