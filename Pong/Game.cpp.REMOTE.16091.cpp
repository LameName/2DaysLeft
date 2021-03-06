#include "Game.h"
#include "Puck.h"
#include "Upgrade.h"
#include "PlayerPad.h"
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

    AIPad* player2 = new AIPad();
    player2->SetPosition(45, (SCREEN_HEIGHT/2));
    spriteManager.Add("Player2", player2);
    counterManager.Add("Player2", player2);
    
    Puck* puck = new Puck();
    puck->Initialize();
    puck->SetPosition(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2)-15);
    spriteManager.Add("Puck", puck);

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
        case Game::Playing:
        {
            mainWindow.clear(sf::Color(0, 0, 0));
            sf::Time timeDelta = clock.restart();
            
            elapsedTimeSinceLastUpgrade += timeDelta.asSeconds();
            
            if (elapsedTimeSinceLastUpgrade >= 5.f)
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
                
                std::string key = std::to_string(NextSpriteKey++);
                
                upgradeManager.Add(key, upgrade);
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
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(mainWindow);

    switch (result)
    {
        case MainMenu::Exit:
            gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            gameState = Game::Playing;
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
            puck->SetVelocity(600.f);
            break;
        case UpgradeEffect::SlowPuck:
            puck->SetVelocity(150.f);
            break;
        case UpgradeEffect::ChangePuckDirection:
            puck->SetVelocity(puck->GetRandomVelocity());
            break;
        default:
            break;
    }
}

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
sf::Clock Game::clock;
SpriteManager Game::spriteManager;
SpriteManager Game::upgradeManager;
CounterManager Game::counterManager;
float Game::elapsedTimeSinceLastUpgrade = 0.f;
int Game::NextSpriteKey = 0;