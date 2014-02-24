#include "CounterManager.h"
#include <iostream>
#include <sstream>


CounterManager::CounterManager(){}

CounterManager::~CounterManager()
{
    std::for_each(counter.begin(), counter.end(), SpriteDeallocator());
}

void CounterManager::Init(sf::Font fonts, int size, sf::Color color)
{
    font = fonts;
    text.setFont(font);
    text.setCharacterSize(size);
    text.setColor(color);
    text.setString("Test");
}

void CounterManager::Add(std::string name, Sprite* sprite)
{
    counter.insert(std::pair<std::string, Sprite*>(name, sprite));
}
void CounterManager::Remove(std::string name)
{
    std::map<std::string, Sprite*>::iterator result = counter.find(name);
    if (result != counter.end())
    {
        delete result->second;
        counter.erase(result);
    }
}

int CounterManager::GetSpriteCount() const
{
    return counter.size();
}
Sprite* CounterManager::Get(std::string name) const
{
    std::map<std::string, Sprite*>::const_iterator results = counter.find(name);
    if (results == counter.end())
    {
        return NULL;
    }
    return results->second;
}

void CounterManager::Draw(sf::RenderWindow& renderWindow)
{
    std::string tmp1;
    std::string tmp2;
    std::string together;
    int i = 0;
    
    //text.setString("TEST");
    //renderWindow.draw(text);
    for (std::map<std::string, Sprite*>::const_iterator it = counter.begin(); it != counter.end(); it++)
    {
        tmp1 = it->first;
        tmp2 = it->second->GetCount();
        //tmp2 = "test";
        together = tmp1+tmp2;
        text.setString(together);
        text.setPosition(i,0);
        renderWindow.draw(text);
        i += 150;
    }
}