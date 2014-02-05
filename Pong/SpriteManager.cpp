#include "SpriteManager.h"

SpriteManager::SpriteManager()
{}

SpriteManager::~SpriteManager()
{
    std::for_each(sprites.begin(), sprites.end(), SpriteDeallocator());
}

void SpriteManager::Add(std::string name, Sprite* sprite)
{
    sprites.insert(std::pair<std::string, Sprite*>(name, sprite));
}

void SpriteManager::Remove(std::string name)
{
    std::map<std::string, Sprite*>::iterator result = sprites.find(name);
    if (result != sprites.end())
    {
        delete result->second;
        sprites.erase(result);
    }
}

Sprite* SpriteManager::Get(std::string name) const
{
    std::map<std::string, Sprite*>::const_iterator results = sprites.find(name);
    if (results == sprites.end())
    {
        return NULL;
    }
    return results->second;
}

int SpriteManager::GetSpriteCount() const
{
    return sprites.size();
}

void SpriteManager::Update(sf::Clock& clock)
{    
    sf::Time timeDelta = clock.restart();
    for (std::map<std::string, Sprite*>::const_iterator it = sprites.begin(); it != sprites.end(); it++)
    {
        it->second->Update(timeDelta.asSeconds());
    }
}

void SpriteManager::Draw(sf::RenderWindow& renderWindow)
{
    for (std::map<std::string, Sprite*>::const_iterator it = sprites.begin(); it != sprites.end(); it++)
    {
        it->second->Draw(renderWindow);
    }
}