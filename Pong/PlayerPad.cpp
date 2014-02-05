#include "PlayerPad.h"
#include "Game.h"

PlayerPad::PlayerPad() : velocity(0), maxVelocity(600.0f)
{
    SetTexture("images/Pad1.png");
    
    GetSprite().setOrigin(15, 50);
}

PlayerPad::~PlayerPad()
{}

void PlayerPad::Update(float elapsedTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        velocity -= 15;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        velocity += 15;
    }
    else
    {
        velocity = 0;
    }
    
    if (velocity > maxVelocity)
    {
        velocity = maxVelocity;
    }
    if (velocity < -maxVelocity)
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
    
    GetSprite().move(0, velocity * elapsedTime);
}

void PlayerPad::Draw(sf::RenderWindow& renderWindow)
{
    Sprite::Draw(renderWindow);
}

float PlayerPad::GetVelocity() const
{
    return velocity;
}