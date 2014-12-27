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
	Bullet(Point location, Size size, double speed, double damage, Ship* from);

	/**
	 * @brief Moves a Bullet to a certain Direction
	 */
	void move(Direction const direction);

	/**
	 * @brief Get a pointer to the ship where this Bullet was shot from
	 */
	Ship* getFrom();

	/**
	 * @brief Damage a ship
	 */
	void explode(Ship* ship);

	virtual ~Bullet();
private:
	double fSpeed;
	double fDamage;
	Ship* fFrom;
};

}

#endif /* LIBRARY_MODELS_BULLET_H_ */
