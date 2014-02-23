#include "Puck.h"
#include "Game.h"
#include "PlayerPad.h"
#include "AIPad.h"
#include <stdlib.h>


float Puck::RandomFloat(float min, float max)
{
    return ((float(rand()) / float(RAND_MAX)) * (max - min)) + min;
}

void Puck::Initialize()
{
    this->velocity = 200.f;
    this->elapsedTimeSinceStart = 0.f;
    
    SetTexture("images/puck.png");
    GetSprite().setOrigin(15, 15);
    
    sf::Vector2f velocity = GetRandomVelocity();
    
    SetVelocity(velocity);
}

void Puck::SetVelocity(sf::Vector2f velocity)
{
    moveByX = velocity.x;
    moveByY = velocity.y;
}

Puck::Puck()
{
    //this->Initialize();
}

Puck::~Puck()
{}

sf::Vector2f Puck::GetRandomVelocity()
{
    sf::Vector2f vel;

    static std::default_random_engine engine;
    engine.seed(time(NULL));
    static std::bernoulli_distribution distribution;

    if (distribution(engine))
        vel.x = -1;
    else 
        vel.x = 1;

    if (distribution(engine))
        vel.y = -1;
    else
        vel.y = 1;

    return vel;
}

void Puck::Update(float elapsedTime)
{
    elapsedTimeSinceStart += elapsedTime;
    
    if (elapsedTimeSinceStart <= 3.f)
    {
        return;
    }
    
    if ((GetPosition().y + moveByY <= 0 + GetHeight() / 2)
            || (GetPosition().y + GetHeight()/2 + moveByY >= Game::SCREEN_HEIGHT))
    {
        moveByY = -moveByY;                  
    }
            
    PlayerPad* player1 = dynamic_cast<PlayerPad*>(Game::GetSpriteManager().Get("Player1"));
    AIPad* player2 = dynamic_cast<AIPad*>(Game::GetSpriteManager().Get("Player2"));
    
    if (player1 != NULL)
    {
        sf::Rect<float> player1BB = player1->GetBoundingRect();
        sf::Rect<float> puckBB = GetBoundingRect();
        
        if (player1BB.intersects(puckBB))
        {
            moveByX = -moveByX;
            
            if (puckBB.left + puckBB.width > player1BB.left)
            {
                SetPosition(player1BB.left - GetWidth()/2, GetPosition().y);
            }            
        }  
        
        if (GetPosition().x + GetWidth() / 2 + moveByY >= Game::SCREEN_WIDTH)
        {
            GetSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
            velocity = 200.f;
            elapsedTimeSinceStart = 0.f;
            Game::elapsedTimeSinceLastUpgrade = 0.f;
            player2->IncreaseCount();
            ClearUpgrades();
        }        
    }
    
    
    
    if (player2 != NULL)
    {
        sf::Rect<float> player2BB = player2->GetBoundingRect();
        sf::Rect<float> puckBB = GetBoundingRect();
        
        if (player2BB.intersects(puckBB))
        {
            moveByX = -moveByX;
            
            if (puckBB.left < player2BB.left + player2BB.width)
            {
                SetPosition(player2BB.left + player2BB.width + GetWidth()/2, GetPosition().y);
            }            
        }  
        
        if (GetPosition().x + moveByY <= 0)
        {
            GetSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
            velocity = 200.f;
            elapsedTimeSinceStart = 0.f;
            Game::elapsedTimeSinceLastUpgrade = 0.f;
            player1->IncreaseCount();
            ClearUpgrades();
        }        
    }
    
    float moveAmount = velocity * elapsedTime;
    
    GetSprite().move(moveByX * moveAmount, moveByY * moveAmount);
}

void Puck::SetVelocity(float velocity)
{
    this->velocity = velocity;
}

void Puck::ChangeVelocity(float amount)
{
    this->velocity += amount;
    
    if (this->velocity > 500)
        SetVelocity(500);
    if (this->velocity < 100)
        SetVelocity(100);
}

void Puck::ClearUpgrades()
{
    for (int i = 0; i < Game::NextSpriteKey; i++)
    {
        std::string key = std::to_string(i);
        Game::GetUpgradeManager().Remove(key);
    }
    
    Game::NextSpriteKey = 0;
}