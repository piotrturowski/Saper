#ifndef function_hpp
#define function_hpp
#include <cstdlib>
#include "CreatorMaps.hpp"
#include "Bomb.hpp"
#include "BaseArt.hpp"

namespace function
{
    int random(int maxRandom);
    int checkBomb(CreatorMaps& Map,sf::Vector2i pos);
    void setNumbers(CreatorMaps& Map);
    void drawGraphics(CreatorMaps& DisplayedMap, BaseArt& baseArt,sf::RenderWindow& window);
    void showAround(sf::Vector2i pos,CreatorMaps DisplayedMap,CreatorMaps Map);
    float translatePosFromIntToWindow(int x);
    float translatePosFromWindowToInt(float WindowPos);
    sf::Vector2f setGraphicsPos(sf::Sprite Sprite,sf::Vector2i pos);

}

#endif // function_hpp
