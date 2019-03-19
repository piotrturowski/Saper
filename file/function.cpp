#include "function.hpp"
#include <iostream>

int function::random(int maxRandom)
{
   return rand() % maxRandom;
}

int function::checkBomb(CreatorMaps& Map,sf::Vector2i pos)
{
    int number = 0;
    for(int j = pos.y-1; j<=pos.y+1; j++)
    {
        for(int i = pos.x-1; i<=pos.x+1; i++)
        {
            if(i >= 0 && j >= 0 && i <= Map.getX() && j <= Map.getY())
            {
                if(Map.getID_on_the_Tab(i,j) == 9)
                {
                    number++;
                }
            }

        }
    }

    //std::cout << number << std::endl;
    return number;
}

void function::setNumbers(CreatorMaps& Map)
{
    for(int i = 0;i<=Map.getX();i++)
    {
        for(int j = 0;j<=Map.getY();j++)
        {
            if(Map.getID_on_the_Tab(i,j) != 9)
            {
                Map.setID(i,j,function::checkBomb(Map,sf::Vector2i(i,j)));
            }
        }
    }
}



void function::drawGraphics(CreatorMaps& DisplayedMap,BaseArt& baseArt,sf::RenderWindow& window)
{
    sf::Sprite sprite;
    for(int j = 0 ; j<=DisplayedMap.getY(); j++)
    {
        for(int i = 0 ; i<=DisplayedMap.getX(); i++)
        {
            switch(DisplayedMap.getID_on_the_Tab(i,j))
            {
            case 0:
                {
                    sprite = baseArt.number0.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 1:
                {
                    sprite = baseArt.number1.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 2:
                {
                    sprite = baseArt.number2.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 3:
                {
                    sprite = baseArt.number3.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 4:
                {
                    sprite = baseArt.number4.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 5:
                {
                    sprite = baseArt.number5.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 6:
                {
                    sprite = baseArt.number6.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 7:
                {
                    sprite = baseArt.number7.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 8:
                {
                    sprite = baseArt.number8.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 9:
                {
                    sprite = baseArt.bomb.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 10:
                {
                    sprite = baseArt.hide.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }
            case 11:
                {
                    sprite = baseArt.mark.getSprite();
                    sprite.setPosition(i*32,j*32);
                    window.draw(sprite);
                    break;
                }

            }
        }
    }
    if(!baseArt.restart.getisHidden())
    {
        sprite = baseArt.restart.getSprite();
        window.draw(sprite);
    }
    if(!baseArt.exit.getisHidden())
    {
        sprite = baseArt.exit.getSprite();
        window.draw(sprite);
    }
}

sf::Vector2f function::setGraphicsPos(sf::Sprite Sprite,sf::Vector2i pos)
{
    sf::Vector2f(pos.x*Sprite.getGlobalBounds().width,pos.y*Sprite.getGlobalBounds().height);
}

float function::translatePosFromIntToWindow(int x)
{
    return x*32;
}

float function::translatePosFromWindowToInt(float WindowPos)
{
    return WindowPos/32;
}

void function::showAround(sf::Vector2i pos,CreatorMaps DisplayedMap,CreatorMaps Map)
{
    for(int j = pos.y-1; j<=pos.y+1; j++)
    {
        for(int i = pos.x-1; i<=pos.x+1; i++)
        {
            if(i >= 0 && j >= 0 && i <= DisplayedMap.getX() && j <= DisplayedMap.getY())
            {
                DisplayedMap.setID(i,j,Map.getID_on_the_Tab(i,j));
            }
        }
    }
}

