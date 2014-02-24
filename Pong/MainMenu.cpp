#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& renderWindow)
{
	sf::Texture texture;
	texture.loadFromFile("images/Mainmenu.png");

	sf::Sprite sprite(texture);

	MenuItem playSingleButton;
	playSingleButton.rect.top = 109;
	playSingleButton.rect.left = 0;
	playSingleButton.rect.width = 1023;
	playSingleButton.rect.height = 174;
	playSingleButton.action = PlaySingle;

	MenuItem playMultiButton;
	playMultiButton.rect.top = 285;
	playMultiButton.rect.left = 0;
	playMultiButton.rect.width = 1023;
	playMultiButton.rect.height = 173;
	playMultiButton.action = PlayMulti;

	MenuItem exitButton;
	exitButton.rect.top = 460;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.height = 158;
	exitButton.action = Exit;

	menuItems.push_back(playSingleButton);
	menuItems.push_back(playMultiButton);
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