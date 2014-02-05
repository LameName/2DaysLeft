#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow)
{
	sf::Texture texture;
	texture.loadFromFile("images/Mainmenu.png");

	sf::Sprite sprite(texture);

	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.rect.height = 235;
	playButton.action = Play;

	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.height = 235;
	exitButton.action = Exit;

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);

	renderWindow.draw(sprite);
	renderWindow.display();

	return GetMenuResponse(renderWindow);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    for (std::list<MenuItem>::const_iterator it = menuItems.begin(); it != menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = it->rect;

        if (menuItemRect.contains(sf::Vector2<int>(x, y)))
        {
            return it->action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& renderWindow)
{
    sf::Event menuEvent;

    while (true)
    {
        while (renderWindow.pollEvent(menuEvent))
        {
            if (menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if (menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}