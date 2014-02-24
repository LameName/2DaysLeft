#include "PlayerPadMulti.h"
#include "Game.h"

PlayerPadMulti::PlayerPadMulti() : velocity(0), maxVelocity(600.0f)
{
	SetTexture("images/Pad2.png");

	GetSprite().setOrigin(15, 50);
}

PlayerPadMulti::~PlayerPadMulti()
{}

void PlayerPadMulti::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		velocity -= 15;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		velocity += 15;
	}
	else
	{
		velocity = 0;
	}

	if (velocity > maxVelocity)
	{
		velocity = maxVelocity;
	}
	if (velocity < -maxVelocity)
	{
		velocity = -maxVelocity;
	}

	sf::Vector2f pos = this->GetPosition();

	if (pos.y < 0 + GetHeight() / 2)
	{
		GetSprite().move(0, +1);
		velocity = 0;
	}
	if (pos.y + GetHeight() / 2 >(Game::SCREEN_HEIGHT))
	{
		GetSprite().move(0, -1);
		velocity = 0;
	}

	GetSprite().move(0, velocity * elapsedTime);
}

void PlayerPadMulti::Draw(sf::RenderWindow& renderWindow)
{
	Sprite::Draw(renderWindow);
}

float PlayerPadMulti::GetVelocity() const
{
	return velocity;
}
std::string PlayerPadMulti::GetCount() const
{
    return count.str();
}
void PlayerPadMulti::IncreaseCount()
{
    count << 'I';
}