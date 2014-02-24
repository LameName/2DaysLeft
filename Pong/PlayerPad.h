#ifndef __PLAYERPAD_H
#define	__PLAYERPAD_H

#include "Sprite.h"
#include <sstream>

class PlayerPad : public Sprite
{
public:
    PlayerPad();
    ~PlayerPad();
    
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow& renderWindow);
    std::string GetCount() const;
    float GetVelocity() const;
    void IncreaseCount();
    
private:
    float velocity;
    float maxVelocity;
     int tmp;
    std::stringstream count;
};

#endif