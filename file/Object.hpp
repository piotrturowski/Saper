#include  <SFML/Graphics.hpp>
#ifndef Object_hpp
#define Object_hpp

class Object
{
protected:
    sf::Vector2i pos;
    int ID;
public:
    sf::Vector2i getPos();
    int getID();
};

#endif // Object_hpp
