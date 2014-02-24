#include "Game.h"
#include "Puck.h"
#include "Upgrade.h"
#include "PlayerPad.h"
#include "PlayerPadMulti.h"
#include "AIPad.h"
#include "SplashScreen.h"
#include "MainMenu.h"


#include <SFML/Graphics.hpp>


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


void Game::Start()
{
    if (gameState != Uninitialized)
       return;

    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pong");
    gameState = Game::ShowingSplash;
    sf::Font font;
    font.loadFromFile("orange_juice.ttf");
    int size = 30;
    
    
    counterManager.Init(font, size, sf::Color::Red);
    
    PlayerPad* player1 = new PlayerPad();
    player1->SetPosition(SCREEN_WIDTH-45, (SCREEN_HEIGHT/2));        
    spriteManager.Add("Player1", player1);
    counterManager.Add("Player1", player1);

    /*AIPad* player2 = new AIPad();
    player2->SetPosition(45, (SCREEN_HEIGHT/2));
    spriteManager.Add("Player2", player2);
    counterManager.Add("Player2", player2);*/  
    
    
    Puck* puck = new Puck();
    puck->Initialize();
    puck->SetPosition(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2)-15);
    spriteManager.Add("Puck", puck);
    
    backgroundImage.loadFromFile("images/GameplayScreen2.png");
    backgroundSprite.setTexture(backgroundImage);   

    while (!IsExiting())
    {
        GameLoop();
    }

    mainWindow.close();
}

sf::RenderWindow& Game::GetWindow()
{
    return mainWindow;
}

SpriteManager& Game::GetSpriteManager()
{
    return spriteManager;
}

SpriteManager& Game::GetUpgradeManager()
{
    return upgradeManager;
}

CounterManager& Game::GetCounterManager()
{
    return counterManager;
}

bool Game::IsExiting()
{
    return gameState == Game::Exiting;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    mainWindow.pollEvent(currentEvent);
    
    switch (gameState)
    {
        case Game::Uninitialized:
        {
            break;
        }
        case Game::Exiting:
        {
            break;
        }
        case Game::ShowingMenu:
        {
            ShowMenuScreen();
            break;
        }
        case Game::ShowingSplash:
        {
            ShowSplashScreen();
            break;
        }
        case Game::PlayingMulti:
		{
			//AIPad* playerAI = dynamic_cast<AIPad*>(Game::GetSpriteManager().Get("PlayerAI"));
			PlayerPadMulti* player2 = dynamic_cast<PlayerPadMulti*>(Game::GetSpriteManager().Get("Player2"));

                        spriteManager.Remove("PlayerAI");
                        
			/*if (playerAI != NULL)
			{
                                spriteManager.Remove("PlayerAI");
			}*/
			if (player2 == NULL)
			{
				SetPlayer2();
			}

			mainWindow.clear(sf::Color(0, 0, 0));
                        mainWindow.draw(backgroundSprite);
                        
			sf::Time timeDelta = clock.restart();

			elapsedTimeSinceLastUpgrade += timeDelta.asSeconds();

			if (elapsedTimeSinceLastUpgrade >= 5.f)
			{
				srand(time(NULL));
				int randomValue = rand() % 3;
				Game::UpgradeEffect effect;

				switch (randomValue)
				{
				case 0:
					effect = Game::UpgradeEffect::SlowPuck;
					break;
				case 1:
					effect = Game::UpgradeEffect::SpeedPuck;
					break;
				case 2:
					effect = Game::UpgradeEffect::ChangePuckDirection;
					break;
				}

				elapsedTimeSinceLastUpgrade = 0;
				Upgrade* upgrade = new Upgrade();
				upgrade->Initialize(effect);
				upgrade->SetPosition(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 15);

				std::string key = std::to_string(NextSpriteKey++);

				upgradeManager.Add(key, upgrade);
			}

			spriteManager.Update(timeDelta);
			upgradeManager.Update(timeDelta);

			spriteManager.Draw(mainWindow);
			upgradeManager.Draw(mainWindow);

			mainWindow.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				{
					ShowMenuScreen();
				}
			}
			break;
		}
        
        case Game::PlayingSingle:
        {
            AIPad* playerAI = dynamic_cast<AIPad*>(Game::GetSpriteManager().Get("PlayerAI"));
            PlayerPadMulti* player2 = dynamic_cast<PlayerPadMulti*>(Game::GetSpriteManager().Get("Player2"));

            if (playerAI == NULL)
            {
                    SetPlayerAI();
            }
            if (player2 != NULL)
            {
                    spriteManager.Remove("Player2");
            }  
            
            mainWindow.clear(sf::Color(0, 0, 0));
            mainWindow.draw(backgroundSprite);
            
            sf::Time timeDelta = clock.restart();
            
            elapsedTimeSinceLastUpgrade += timeDelta.asSeconds();
            
            if (elapsedTimeSinceLastUpgrade >= 3.5f)
            {
                srand(time(NULL));
                int randomValue = rand() % 3;
                Game::UpgradeEffect effect;
                
                switch(randomValue)
                {
                    case 0:
                        effect = Game::UpgradeEffect::SlowPuck;
                        break;
                    case 1:
                        effect = Game::UpgradeEffect::SpeedPuck;
                        break;
                    case 2:
                        effect = Game::UpgradeEffect::ChangePuckDirection;
                        break;
                }
                
                elapsedTimeSinceLastUpgrade = 0;
                Upgrade* upgrade = new Upgrade();
                upgrade->Initialize(effect);
                upgrade->SetPosition(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2)-15);               
                
                bool canAdd = true;
                
                if (Game::NextSpriteKey > 1)
                {                    
                    for (int i = 0; i < Game::NextSpriteKey; i++)
                    {
                        std::string key = std::to_string(i);
                        Upgrade* up = dynamic_cast<Upgrade*>(Game::GetUpgradeManager().Get(key));

                        if (up != NULL)
                        {
                            sf::Rect<float> upBB = up->GetBoundingRect();
                            sf::Rect<float> thisBB = upgrade->GetBoundingRect();

                            if (upBB != thisBB)
                            {
                                if(upBB.intersects(thisBB))
                                {
                                   canAdd = false; 
                                }
                            }
                        }
                    }
                }
                
                if (canAdd)
                {
                    Puck* puck = dynamic_cast<Puck*>(Game::GetSpriteManager().Get("Puck"));

                    if (puck != NULL)
                    {
                        if (!(upgrade->GetBoundingRect().intersects(puck->GetBoundingRect())))
                        {
                            std::string key = std::to_string(NextSpriteKey++);                
                            upgradeManager.Add(key, upgrade);
                        }
                    }
                }
            }
            
            //counter.Update(timeDelta.asMilliseconds());
            spriteManager.Update(timeDelta);
            upgradeManager.Update(timeDelta);
            
            counterManager.Draw(mainWindow);
            spriteManager.Draw(mainWindow);
            upgradeManager.Draw(mainWindow);
            
            mainWindow.display();

            if (currentEvent.type == sf::Event::Closed)
            {
                gameState = Game::Exiting;
            }
            if (currentEvent.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                {
                    ShowMenuScreen();
                }
            }
            break;
        }
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(mainWindow);
    gameState = Game::ShowingMenu;
}

void Game::ShowMenuScreen()
{MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(mainWindow);

    switch (result)
    {
        case MainMenu::Exit:
            gameState = Game::Exiting;
            break;
        case MainMenu::PlaySingle:
            gameState = Game::PlayingSingle;
            break;
        case MainMenu::PlayMulti:
            gameState = Game::PlayingMulti;
            break;
        case MainMenu::Nothing:
            break;
    }
}

void Game::ApplyUpgrade(UpgradeEffect effect)
{
    Puck* puck = dynamic_cast<Puck*>(spriteManager.Get("Puck"));
    
    switch (effect)
    {
        case UpgradeEffect::SpeedPuck:            
            puck->SetVelocity(500.f);
            break;
        case UpgradeEffect::SlowPuck:
            puck->SetVelocity(200.f);
            break;
        case UpgradeEffect::ChangePuckDirection:
            puck->moveByX = -puck->moveByX;
            puck->moveByY = -puck->moveByY;
            break;
        default:
            break;
    }
}

void Game::SetPlayerAI()
{
	AIPad* playerAI = new AIPad();
	playerAI->SetPosition(45, (SCREEN_HEIGHT / 2));
	spriteManager.Add("PlayerAI", playerAI);
        counterManager.Add("PlayerAI", playerAI);
}

void Game::SetPlayer2()
{
	PlayerPadMulti* player2 = new PlayerPadMulti();
	player2->SetPosition(45, (SCREEN_HEIGHT / 2));
	spriteManager.Add("Player2", player2);
        counterManager.Add("Player2", player2);
}


Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
sf::Clock Game::clock;
SpriteManager Game::spriteManager;
SpriteManager Game::upgradeManager;
CounterManager Game::counterManager;
float Game::elapsedTimeSinceLastUpgrade = 0.f;
int Game::NextSpriteKey = 0;
sf::Texture Game::backgroundImage;
sf::Sprite Game::backgroundSprite; 
