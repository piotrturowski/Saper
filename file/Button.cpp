#include "Button.hpp"

Button::Button(std::string name)
:PrepareArt(name)
{
    isHidden = true;
}

void Button::setPosition(int x,int y)
{
    sprite.setPosition(x,y);
}

bool Button::isActive(sf::RenderWindow& window)
{
    if(    sf::Mouse::getPosition(window).x > sprite.getPosition().x
        && sf::Mouse::getPosition(window).x < sprite.getPosition().x + sprite.getGlobalBounds().width
        && sf::Mouse::getPosition(window).y > sprite.getPosition().y
        && sf::Mouse::getPosition(window).y < sprite.getPosition().y + sprite.getGlobalBounds().height)
    {
        return true;
    }
    return false;
}

void Button::Hidden(bool status)
{
    isHidden = status;
}

bool Button::getisHidden()
{
    return isHidden;
}
