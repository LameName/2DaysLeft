#ifndef __GAME_H
#define __GAME_H

#include "SFML/Window.hpp"

#include "SpriteManager.h"
#include "CounterManager.h"

class Game
{
public:
    static const int SCREEN_WIDTH = 1024;
    static const int SCREEN_HEIGHT = 668;

    static void Start();
    static sf::RenderWindow& GetWindow();    
    static SpriteManager& GetSpriteManager();
    static SpriteManager& GetUpgradeManager();
    
    static CounterManager& GetCounterManager();
    
    enum UpgradeEffect { SpeedPuck, SlowPuck, ChangePuckDirection };
    static void ApplyUpgrade(UpgradeEffect effect);
    
    static int NextSpriteKey;
    static float elapsedTimeSinceLastUpgrade;  
    
    static void SetPlayerAI();
    static void SetPlayer2();

private:
    static sf::Clock clock;    
    static bool IsExiting();
    static void GameLoop();

    static void ShowSplashScreen();
    static void ShowMenuScreen();

    enum GameState { Uninitialized, ShowingSplash, ShowingMenu, PlayingSingle, PlayingMulti, Exiting };

    static GameState gameState;
    static sf::RenderWindow mainWindow;        
    static SpriteManager spriteManager;
    static SpriteManager upgradeManager;  
    
    static sf::Texture backgroundImage;
    static sf::Sprite backgroundSprite;        
    static CounterManager counterManager;
};

#endif