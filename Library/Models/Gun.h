/*
 * Gun.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_GUN_H_
#define LIBRARY_MODELS_GUN_H_

class BulletFactory;

#include "Entity.h"
#include "../Factories/BulletFactory.h"

/**
 * @brief Model representing a Gun
 */
class Gun : public Entity {
public:
	/**
	 * Construct a Gun with a given Point as location and a Bulletfactory for shooting bullets
	 */
	Gun(Point location, BulletFactory* bulletFactory, Ship* ship);

	virtual void move(Direction direction){};

	/**
	 * @brief Shoot a bullet from the gun
	 */
	void shoot();

	virtual ~Gun();
private:
	BulletFactory* fBulletFactory;
	Ship* fShip;
};

#endif /* LIBRARY_MODELS_GUN_H_ */
