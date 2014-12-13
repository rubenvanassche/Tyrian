/*
 * World.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_WORLD_H_
#define LIBRARY_MODELS_WORLD_H_

#include <list>
#include "Bullet.h"
#include "Ship.h"

class World {
public:
	World();
	virtual ~World();
private:
	std::list<Bullet> fBullets;
	std::list<Ship> fShips;
};

#endif /* LIBRARY_MODELS_WORLD_H_ */
