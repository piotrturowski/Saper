#ifndef PrepareArt_hpp
#define PrepareArt_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class PrepareArt
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string name;
public:
    PrepareArt(std::string name);
    void setTexture();
    sf::Sprite getSprite() const;
    sf::Texture getTexture() const;

};

#endif
