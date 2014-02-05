#include "../header/Game.h"

void Game::Start()
{
	if (gameState != Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1024, 768, 32), "Pong");
	gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	mainWindow.close();
}

bool Game::IsExiting()
{
	return gameState == Game::Exiting;
}

void Game::GameLoop()
{	
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
			sf::Event currentEvent;

			while (mainWindow.pollEvent(currentEvent))
			{
				mainWindow.clear(sf::Color(0, 0, 0));
				mainWindow.display();

				if (currentEvent.type == sf::Event::Closed)
				{
					gameState = Game::Exiting;
				}
				if (currentEvent.type == sf::Event::KeyPressed)
				{
					/*if (currentEvent.key.code == sf::Keyboard::key::Escape)
					{
						ShowMenuScreen();
					}*/
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