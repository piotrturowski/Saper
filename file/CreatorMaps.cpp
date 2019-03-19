#include "CreatorMaps.hpp"
#include <iostream>
#include <string>

CreatorMaps::CreatorMaps(int xy)
{
    this->create(xy,xy);
}

CreatorMaps::CreatorMaps(int x,int y)
{
    this->create(x,y);
}

CreatorMaps::CreatorMaps(int x,int y,std::string adres)
{
    this->create(x,y);
    this->loadSprite();
}

void CreatorMaps::create(int x, int y)
{
    this->tab = new int * [x];
    x--;
    for(int i=0; i<=x; i++)
    {
        this->tab[i] = new int [y];
    }
    y--;
    this->Y = y;
    this->X = x;
    this->reset();
}

void CreatorMaps::show()
{
    for(int i=0; i<=X;i++)
    {
        for(int j=0; j<=Y;j++)
        {
            std::cout << this->tab[j][i];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void CreatorMaps::reset()
{
    for(int i=0; i<=X;i++)
    {
        for(int j=0; j<=Y;j++)
        {
           this->tab[i][j] = 0;
        }
    }
}

void CreatorMaps::reset(int number)
{
    for(int i=0; i<=X;i++)
    {
        for(int j=0; j<=Y;j++)
        {
           this->tab[i][j] = number;
        }
    }
}

void CreatorMaps::loadSprite()
{
    if(!this->Texture.loadFromFile("file/art/sciana.png"))
    {
        std::cout << "brak obrazka: file/art/sciana.png" << std::endl;
    }
    this->Sprite.setTexture(this->Texture);
}

int CreatorMaps::getX()
{
    return X;
}

int CreatorMaps::getY()
{
    return Y;
}

int CreatorMaps::getID_on_the_Tab(sf::Vector2i pos)
{
    if(pos.x>=0&&pos.x<=X&&pos.y>=0&&pos.y<=Y)
    {
        return tab[pos.x][pos.y];
    }
    return 0;
}

int CreatorMaps::getID_on_the_Tab(int x,int y)
{
    if(x>=0&&x<=X&&y>=0&&y<=Y)
    {
        return tab[x][y];
    }

    return 0;
}

void CreatorMaps::setID(int x, int y,int ID)
{
    tab[x][y] = ID;
}

void CreatorMaps::setID(sf::Vector2i pos,int ID)
{
    tab[pos.x][pos.y] = ID;
}

