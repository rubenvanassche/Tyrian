/*
 * World.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_WORLD_H_
#define LIBRARY_MODELS_WORLD_H_

class Ship;
class Bullet;

#include <list>
#include "Bullet.h"
#include "Ship.h"
#include "Entity.h"

/**
 * @brief The world class, containing the whole battlefield(all the Entities)
 */
class World : public Entity {
public:
	/**
	 * @brief World Constructor
	 */
	World(int width, int height);

	virtual void move(Direction const direction);

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

	/**
	 * @brief The Height of the world
	 */
	int height;

	/**
	 * @brief The Width of the world
	 */
	int width;
};

#endif /* LIBRARY_MODELS_WORLD_H_ */
