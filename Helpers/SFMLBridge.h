/*
 * SFMLBridge.h
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#ifndef HELPERS_SFMLBRIDGE_H_
#define HELPERS_SFMLBRIDGE_H_

#include "../Library/Controllers/Game.h"
#include "../Views/Bullet.h"
#include "../Views/Ship.h"
#include "Window.h"

namespace tySFML {

class SFMLBridge : public tyLib::Bridge {
public:
	virtual void createShip(tyLib::Ship* shipPtr);

	virtual void createBullet(tyLib::Bullet* bulletPtr);

	virtual void removeShip(tyLib::Ship* shipPtr);

	virtual void removeBullet(tyLib::Bullet* bulletPtr);

	std::list<tySFML::Ship*> ships;
	std::list<tySFML::Bullet*> bullets;

	Window* window;
};

} /* namespace tySFML */

#endif /* HELPERS_SFMLBRIDGE_H_ */
