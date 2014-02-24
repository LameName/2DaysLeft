#ifndef __PLAYERPADMULTI_H
#define	__PLAYERPADMULTI_H

#include "Sprite.h"
#include <sstream>

class PlayerPadMulti : public Sprite
{
public:
	PlayerPadMulti();
	~PlayerPadMulti();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& renderWindow);
        std::string GetCount() const;
        void IncreaseCount();
	float GetVelocity() const;

private:
	float velocity;
	float maxVelocity;
        int tmp;
        std::stringstream count;
};

#endif