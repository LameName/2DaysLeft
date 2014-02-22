#ifndef __PUCK_H
#define	__PUCK_H

#include "Sprite.h"

class Puck : public Sprite
{
public:
    Puck();
    virtual ~Puck();
    virtual void Initialize();
    virtual void Update(float);
    float RandomFloat(float, float);
    sf::Vector2f GetRandomVelocity();
    void SetVelocity(float);
    void ChangeVelocity(float);
    void SetVelocity(sf::Vector2f);
    
protected:
    float moveByX, moveByY;
    float velocity;
    float angle;
    float elapsedTimeSinceStart;
};


#endif

