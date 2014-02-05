#ifndef __AIPAD_H
#define	__AIPAD_H

#include "Sprite.h"
        
class AIPad : public Sprite
{
public:
    AIPad();
    ~AIPad();
    
    void Update(float);
    void Draw(sf::RenderWindow&);
    float GetVelocity() const;
    
private:
    float velocity;
    float maxVelocity;
};

#endif