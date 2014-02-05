#include "Sprite.h"

Sprite::Sprite(){}

Sprite::~Sprite(){}

void Sprite::SetTexture(std::string textureFile)
{
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);
}

void Sprite::SetPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

sf::Vector2f Sprite::GetPosition() const
{
    return sprite.getPosition();
}

sf::Sprite& Sprite::GetSprite()
{
    return sprite;
}

float Sprite::GetWidth() const
{
    return sprite.getGlobalBounds().width;
}

float Sprite::GetHeight() const
{
    return sprite.getGlobalBounds().height;
}

sf::Rect<float> Sprite::GetBoundingRect() const
{
    sf::Vector2f size(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
    sf::Vector2f position = sprite.getPosition();
    
    return sf::Rect<float>(
            position.x - size.x/2,
            position.y - size.y/2,
            size.x,
            size.y
            );
}

void Sprite::Update(float elapsedTime)
{}

void Sprite::Draw(sf::RenderWindow &renderWindow)
{
    renderWindow.draw(sprite);
}