#ifndef __AIPAD_H
#define	__AIPAD_H

#include "Sprite.h"
#include <sstream>
        
class AIPad : public Sprite
{
public:
    AIPad();
    ~AIPad();
    
    void Update(float);
    void Draw(sf::RenderWindow&);
    float GetVelocity() const;
    std::string GetCount() const;
    void IncreaseCount();
    
private:
    float velocity;
    float maxVelocity;
    int tmp;
    std::stringstream count;
};

#endif