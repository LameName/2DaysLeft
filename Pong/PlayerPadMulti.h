#ifndef __PLAYERPADMULTI_H
#define	__PLAYERPADMULTI_H

#include "Sprite.h"

class PlayerPadMulti : public Sprite
{
public:
	PlayerPadMulti();
	~PlayerPadMulti();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& renderWindow);

	float GetVelocity() const;

private:
	float velocity;
	float maxVelocity;
};

#endif