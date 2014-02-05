#ifndef __PUCK_H
#define	__PUCK_H

#include "Sprite.h"

class Puck : public Sprite
{
public:
    Puck();
    virtual ~Puck();
    void Update(float);
    float RandomFloat(float, float);
    sf::Vector2f GetRandomVelocity();

private:
    float moveByX, moveByY;
    float velocity;
    float angle;
    float elapsedTimeSinceStart;   
};


#endif

