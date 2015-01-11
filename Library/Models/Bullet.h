/*
 * Bullet.h
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_BULLET_H_
#define LIBRARY_MODELS_BULLET_H_

#include "Entity.h"
#include "Ship.h"

namespace tyLib{

class Ship;

/**
 * @brief Model representing a Bullet
 */
class Bullet : public Entity {
public:
	/**
	 * @brief Construct a Bullet
	 */
	Bullet(Vector location, Size size, Vector velocity, double damage, Ship* from);

	/**
	 * @brief Moves a Bullet to a certain Direction
	 */
	void move(Direction const direction, double const delta);

	/**
	 * @brief Get a pointer to the ship where this Bullet was shot from
	 */
	Ship* getFrom();

	/**
	 * @brief Damage a ship
	 */
	void explode(Ship* ship);

	/**
	 * @brief Returns a boolean telling if the ship is dead
	 */
	bool isDead();

	virtual ~Bullet();
private:
	bool fDead = false;
	double fDamage;
	Ship* fFrom;
};

}

#endif /* LIBRARY_MODELS_BULLET_H_ */
