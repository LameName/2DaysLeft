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
    void SetVelocity(sf::Vector2f);
    void ChangeVelocity(float);    
    void ClearUpgrades();
    float moveByX, moveByY;
    
protected:    
    float velocity;
    float angle;
    float elapsedTimeSinceStart;
};


#endif

