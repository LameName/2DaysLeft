#ifndef __PLAYERPAD_H
#define	__PLAYERPAD_H

#include "Sprite.h"

class PlayerPad : public Sprite
{
public:
    PlayerPad();
    ~PlayerPad();
    
    void Update(float elapsedTime);
    void Draw(sf::RenderWindow& renderWindow);
    
    float GetVelocity() const;
    
private:
    float velocity;
    float maxVelocity;        
};

#endif