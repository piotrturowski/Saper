#include "PrepareArt.hpp"

PrepareArt::PrepareArt(std::string name)
{
    this->name="art/" + name + ".png";
    setTexture();
}

void PrepareArt::setTexture()
{
    if(!texture.loadFromFile(name))
    {
        std::cout << name << std::endl;
    }
    sprite.setTexture(texture);
}

sf::Sprite PrepareArt::getSprite() const
{
    return sprite;
}

sf::Texture PrepareArt::getTexture() const
{
    return texture;
}

