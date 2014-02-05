#include "../header/SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	sf::Texture texture;

	if (!texture.loadFromFile("images/splash.png"))
	{
		return;
	}
	
	sf::Sprite sprite(texture);
	
	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;

	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed
				|| event.type == sf::Event::MouseButtonPressed
				|| event.type == sf::Event::Closed)
			{
				return;
			}
		}
	}
}