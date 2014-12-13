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

/**
 * @brief The world class, containing the whole battlefield(all the Entities)
 */
class World {
public:
	/**
	 * @brief World Constructor
	 */
	World();

	virtual ~World();

	/**
	 * @brief Container for Bullets
	 */
	std::list<Bullet*> bullets;

	/**
	 * @brief Container for Ships
	 */
	std::list<Ship*> ships;

	/**
	 * @brief The ship of the player
	 */
	Ship* player;
};

#endif /* LIBRARY_MODELS_WORLD_H_ */
