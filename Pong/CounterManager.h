#ifndef __COUNTERMANAGER_H
#define __COUNTERMANAGER_H

#include "Sprite.h"
#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>

class CounterManager
{
public:
    CounterManager();
    ~CounterManager();
    
    void Init(sf::Font font, int size, sf::Color color);
    
    void Add(std::string name, Sprite* sprite);
    void Remove(std::string name);
    int GetSpriteCount() const;
    Sprite* Get(std::string name) const;
    
    void Update(sf::Time timeDelta);
    void Draw(sf::RenderWindow& renderWindow);
    
private:
    sf::Text text;
    sf::Font font;
    std::map<std::string, Sprite*> counter;
    
    struct SpriteDeallocator
    {
        void operator() (const std::pair<std::string, Sprite*> & p) const
        {
            delete p.second;
        }
    };
};
#endif