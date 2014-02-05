#include "Game.h"
#include "Puck.h"
#include "PlayerPad.h"
#include "AIPad.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::Start()
{
    if (gameState != Uninitialized)
       return;

    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Pong");
    gameState = Game::ShowingSplash;

    PlayerPad* player1 = new PlayerPad();
    player1->SetPosition(SCREEN_WIDTH-45, (SCREEN_HEIGHT/2));        
    spriteManager.Add("Player1", player1);

    AIPad* player2 = new AIPad();
    player2->SetPosition(45, (SCREEN_HEIGHT/2));
    spriteManager.Add("Player2", player2);

    Puck* puck = new Puck();
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
            
            spriteManager.Update(clock);
            spriteManager.Draw(mainWindow);
            
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
    }
}

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
sf::Clock Game::clock;
SpriteManager Game::spriteManager;