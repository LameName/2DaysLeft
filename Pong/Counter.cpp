#include "Counter.h"
#include "Game.h"
#include <SFML/Graphics/Text.hpp>



Counter::Counter(): count1(0), count2(0)
{
    tmp = sf::String("Test");
    sf::Text(tmp);
    GetSprite().setOrigin(15,0);
}

Counter::~Counter()
{}

void Counter::Update(float elapsedTime)
{
    
}
void Counter::Draw(sf::RenderWindow& renderWindow)
{
    Sprite::Draw(renderWindow);
}