#ifndef __MAINMENU_H
#define __MAINMENU_H

#include <list>
#include "SFML/Graphics.hpp"

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, PlaySingle, PlayMulti };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> menuItems;
};

#endif