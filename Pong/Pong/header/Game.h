#ifndef __GAME_H
#define __GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "SplashScreen.h"
#include "MainMenu.h"

class Game
{
public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();

	static void ShowSplashScreen();
	static void ShowMenuScreen();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState gameState;
	static sf::RenderWindow mainWindow;
};

#endif

