#ifndef __SPRITE_H
#define	__SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite
{
public:
    Sprite();
    virtual ~Sprite();
    
    virtual void SetTexture(std::string textureFile);
    virtual void Update(float elapsedTime);
    virtual void Draw(sf::RenderWindow &renderWindow);
    
    virtual void SetPosition(float x, float y);
    virtual sf::Vector2f GetPosition() const;    
    virtual float GetWidth() const;
    virtual float GetHeight() const;
    virtual sf::Rect<float> GetBoundingRect() const;
    void Disable();
    bool IsDisabled();    
    
protected:
    sf::Sprite& GetSprite();
private:
    bool disabled;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
};

#endif