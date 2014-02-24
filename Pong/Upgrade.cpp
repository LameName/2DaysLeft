#include "Upgrade.h"
#include "Game.h"
#include "PlayerPad.h"
#include "AIPad.h"

void Upgrade::Initialize(Game::UpgradeEffect effect)
{
    switch (effect)
    {
        case Game::UpgradeEffect::SpeedPuck:
            SetTexture("images/orb1.png");
            break;
        case Game::UpgradeEffect::SlowPuck:
            SetTexture("images/orb5.png");
            break;
        case Game::UpgradeEffect::ChangePuckDirection:
            SetTexture("images/orb3.png");
            break;            
    }
    
    this->velocity = 300.f;
    this->upgradeEffect = effect;
    
    GetSprite().setOrigin(37.5, 37.5);
    
    sf::Vector2f velocity = GetRandomVelocity();
    
    this->moveByX = velocity.x;
    this->moveByY = velocity.y;
}

void Upgrade::Update(float elapsedTime)
{
    elapsedTimeSinceStart += elapsedTime;
    
    if ((GetPosition().y + moveByY <= 0 + GetHeight() / 2)
            || (GetPosition().y + GetHeight()/2 + moveByY >= Game::SCREEN_HEIGHT))
    {
        moveByY = -moveByY;                 
    }
    
    /*if (GetPosition().y + moveByY <= 0 + GetHeight() / 2)
    {
        moveByY = -moveByY;
        this->SetPosition(0, this->GetPosition().y + 1);
    }
    if (GetPosition().y + GetHeight() / 2 + moveByY >= Game::SCREEN_HEIGHT)
    {
        moveByY = -moveByY;
        this->SetPosition(0, this->GetPosition().y - 1);
    }*/
    
    /*if ((GetPosition().x + moveByX <= 0 + GetWidth() / 2)
            || (GetPosition().x + GetWidth()/2 + moveByX >= Game::SCREEN_WIDTH))
    {
        moveByX = -moveByX;                  
    }*/
    
    for (int i = 0; i < Game::NextSpriteKey; i++)
    {
        std::string key = std::to_string(i);
        Upgrade* up = dynamic_cast<Upgrade*>(Game::GetUpgradeManager().Get(key));
        
        if (up != NULL)
        {
            sf::Rect<float> upBB = up->GetBoundingRect();
            sf::Rect<float> thisBB = GetBoundingRect();
            
            if (upBB != thisBB)
            {
                if(upBB.intersects(thisBB))
                {
                    moveByX = -moveByX;
                    moveByY = -moveByY;
                    
                    up->moveByX = -up->moveByX;
                    up->moveByY = -up->moveByY;
                }
            }
        }
    }
            
    PlayerPad* player1 = dynamic_cast<PlayerPad*>(Game::GetSpriteManager().Get("Player1"));
    
    if (player1 != NULL)
    {
        sf::Rect<float> player1BB = player1->GetBoundingRect();
        sf::Rect<float> upgradeBB = GetBoundingRect();
        
        if (player1BB.intersects(upgradeBB))
        {
            moveByX = -moveByX;
            
            if (upgradeBB.left + upgradeBB.width > player1BB.left)
            {
                SetPosition(player1BB.left - GetWidth()/2, GetPosition().y);
            }            
        }  
        
        if (GetPosition().x + GetWidth() / 2 + moveByY >= Game::SCREEN_WIDTH)
        {
            this->Disable();
        }        
    }
    
    AIPad* player2 = dynamic_cast<AIPad*>(Game::GetSpriteManager().Get("Player2"));
    
    if (player2 != NULL)
    {
        sf::Rect<float> player2BB = player2->GetBoundingRect();
        sf::Rect<float> upgradeBB = GetBoundingRect();
        
        if (player2BB.intersects(upgradeBB))
        {
            moveByX = -moveByX;
            
            if (upgradeBB.left + upgradeBB.width > player2BB.left)
            {
                SetPosition(player2BB.left + player2BB.width + GetWidth()/2, GetPosition().y);
            }            
        }  
        
        if (GetPosition().x + GetWidth() / 2 + moveByY >= Game::SCREEN_WIDTH)
        {
            this->Disable();
        }     
    }
    
    Puck* puck = dynamic_cast<Puck*>(Game::GetSpriteManager().Get("Puck"));
    
    if (puck != NULL)
    {
        sf::Rect<float> puckBB = puck->GetBoundingRect();
        sf::Rect<float> upgradeBB = GetBoundingRect();
        
        if (puckBB.intersects(upgradeBB))
        {
            Game::ApplyUpgrade(this->upgradeEffect);
            
            if (this->upgradeEffect == Game::UpgradeEffect::ChangePuckDirection)
            {
                moveByX = -puck->moveByX;
                moveByY = -puck->moveByY;
            }
            else
            {
                this->Disable();
            }
        }
    }
    
    float moveAmount = velocity * elapsedTime;
    
    GetSprite().move(moveByX * moveAmount, moveByY * moveAmount);
}