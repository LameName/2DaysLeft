#include "AIPad.h"
#include "Game.h"
#include "Puck.h"

//#include <string>

AIPad::AIPad() : velocity(0), maxVelocity(600)
{
    SetTexture("images/Pad2.png");
    
    GetSprite().setOrigin(15, 50);
}

AIPad::~AIPad()
{}

void AIPad::Draw(sf::RenderWindow& renderWindow)
{
    Sprite::Draw(renderWindow);
}

void AIPad::Update(float elapsedTime)
{
    Puck* puck = dynamic_cast<Puck*>(Game::GetSpriteManager().Get("Puck"));
    
    if (puck != NULL)
    {
        sf::Vector2f puckPos = puck->GetPosition();

        if(GetPosition().y -20 < puckPos.y)
        {
            velocity += 15;
        }
        else if(GetPosition().y +20 > puckPos.y)
        {
            velocity -= 15;
        }
        else
        {
            velocity = 0.0f;
        }

        if(velocity > maxVelocity)
        {
            velocity = maxVelocity;
        }
        if(velocity < -maxVelocity)
        {
          velocity = -maxVelocity;
        }

        sf::Vector2f pos = this->GetPosition();

        if (pos.y < 0 + GetHeight() / 2)
        {
            GetSprite().move(0, +1);
            velocity = 0;
        }
        if (pos.y + GetHeight() / 2 > (Game::SCREEN_HEIGHT))
        {
            GetSprite().move(0, -1);
            velocity = 0;
        }
    }
  
    GetSprite().move(0, velocity * elapsedTime);
}
std::string AIPad::GetCount() const
{
    return count.str();
}

void AIPad::IncreaseCount()
{
    count << 'I';
}