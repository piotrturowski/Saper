#include "Saper.hpp"
#include <cstdlib>
#include <iostream>

Saper::Saper(int z = 10)
: Map(z,z)
, DisplayedMap(z,z)
, baseArt()
, Bomb()
{}

void Saper::setup(System& sys)
{
    srand( time( NULL ) );
    DisplayedMap.reset(10);
    for(int i = 0; i<=Bomb::number; i++)
    {
        Bomb[i].setPosition(Map.getX(),Map.getY());
        Map.setID(Bomb[i].getPos(),Bomb[i].getID());
    }
    function::setNumbers(Map);
    sys.window.create(sf::VideoMode(function::translatePosFromIntToWindow(Map.getX()+1),function::translatePosFromIntToWindow(Map.getY()+1)),"Saper!");
    sys.window.setFramerateLimit(60);
    baseArt.restart.setPosition(sys.window.getSize().x/2-baseArt.restart.getSprite().getGlobalBounds().width/2
                                ,sys.window.getSize().y/2-baseArt.restart.getSprite().getGlobalBounds().height);
    baseArt.exit.setPosition(sys.window.getSize().x/2-baseArt.exit.getSprite().getGlobalBounds().width/2
                             ,sys.window.getSize().y/2-baseArt.exit.getSprite().getGlobalBounds().height/2+baseArt.exit.getSprite().getGlobalBounds().height);
}

void Saper::run(System& sys)
{
    while(sys.window.isOpen())
    {
        include(sys);
        logic(sys);
        draw(sys);
    }
}

void Saper::include(System& sys)
{
    while (sys.window.pollEvent(sys.event))
        {
            if(sys.event.type == sf::Event::MouseButtonPressed)
            {
                switch(sys.event.key.code)
                {
                case sf::Mouse::Left:
                    {
                        if(baseArt.restart.getisHidden() || baseArt.exit.getisHidden())
                        {
                            int i = sf::Mouse::getPosition(sys.window).x/32;
                            int j = sf::Mouse::getPosition(sys.window).y/32;
                            DisplayedMap.setID(i,j,Map.getID_on_the_Tab(i,j));
                        }
                        else
                        {
                            if(baseArt.restart.isActive(sys.window))
                            {
                                DisplayedMap.reset(10);
                                Map.reset();
                                for(int i = 0; i<=Bomb::number; i++)
                                {
                                    Bomb[i].setPosition(Map.getX(),Map.getY());
                                    Map.setID(Bomb[i].getPos(),Bomb[i].getID());
                                }
                                function::setNumbers(Map);
                                baseArt.restart.Hidden(true);
                                baseArt.exit.Hidden(true);
                            }
                            if(baseArt.exit.isActive(sys.window))
                            {
                                sys.window.close();
                            }

                        }
                        break;
                    }
                case sf::Mouse::Right:
                    {
                        int i = sf::Mouse::getPosition(sys.window).x/32;
                        int j = sf::Mouse::getPosition(sys.window).y/32;
                        if(DisplayedMap.getID_on_the_Tab(i,j) == 10)
                        {
                            DisplayedMap.setID(i,j,11);
                        }
                        else if(DisplayedMap.getID_on_the_Tab(i,j) == 11)
                        {
                            DisplayedMap.setID(i,j,10);
                        }

                        break;
                    }
                }
            }

            if (sys.event.type == sf::Event::Closed)
                sys.window.close();

        }
}

void Saper::logic(System& sys)
{
    int hiddenBlock = (Map.getX()+1)*(Map.getY()+1);
    for(int j = 0 ; j<=DisplayedMap.getX(); j++)
    {
        for(int i = 0 ; i<=DisplayedMap.getY(); i++)
        {
            if(0 == DisplayedMap.getID_on_the_Tab(i,j))
            {
                function::showAround(sf::Vector2i(i,j),DisplayedMap,Map);
            }
            if(9 == DisplayedMap.getID_on_the_Tab(i,j))
            {
                for(int k = 0; k<=Bomb::number;k++)
                {
                    DisplayedMap.setID(Bomb[k].getPos().x,Bomb[k].getPos().y,Bomb[k].getID());
                }
                baseArt.restart.Hidden(false);
                baseArt.exit.Hidden(false);
            }
            if(10 != DisplayedMap.getID_on_the_Tab(i,j))
            {
                hiddenBlock--;
            }
            if(hiddenBlock <= Bomb::number+1)
            {

                for(int k = 0; k<=Bomb::number;k++)
                {
                    DisplayedMap.setID(Bomb[k].getPos().x,Bomb[k].getPos().y,Bomb[k].getID());
                }
                baseArt.restart.Hidden(false);
                baseArt.exit.Hidden(false);
            }
        }
    }

}

void Saper::draw(System& sys)
{
    sys.window.clear(sf::Color::White);
    function::drawGraphics(DisplayedMap,baseArt,sys.window);
    sys.window.display();
}






