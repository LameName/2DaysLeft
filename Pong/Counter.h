#ifndef __COUNTER_H
#define __COUNTER_H

#include "Sprite.h"
#include <SFML/System/String.hpp>

class Counter : public Sprite
{
public:
    Counter();
    ~Counter();
    
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow& renderWindow);
    
private:
    sf::String tmp;
    int count1;
    int count2;
    
};
#endif