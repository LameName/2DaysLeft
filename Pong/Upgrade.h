#ifndef __UPGRADE_H
#define	__UPGRADE_H

#include "Puck.h"
#include "Game.h"

class Upgrade : public Puck
{
public:
    void Initialize(Game::UpgradeEffect effect);
    void Update(float);
    
private:
    Game::UpgradeEffect upgradeEffect;
};

#endif