#ifndef __SPRITEMANAGER_H
#define	__SPRITEMANAGER_H

#include "Sprite.h"

class SpriteManager
{
public:
    SpriteManager();
    ~SpriteManager();
    
    void Add(std::string name, Sprite* sprite);
    void Remove(std::string name);
    int GetSpriteCount() const;
    Sprite* Get(std::string name) const;
    
    void Update(sf::Time timeDelta);
    void Draw(sf::RenderWindow& renderWindow);
    
private:
    std::map<std::string, Sprite*> sprites;
    
    struct SpriteDeallocator
    {
        void operator() (const std::pair<std::string, Sprite*> & p) const
        {
            delete p.second;
        }
    };
    
};

#endif

