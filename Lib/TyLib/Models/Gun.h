/*
 * Gun.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_MODELS_GUN_H_
#define LIBRARY_MODELS_GUN_H_


#include "Entity.h"
#include "../Factories/BulletFactory.h"
#include "Ship.h"
#include "../Lib/Direction.h"
#include "../Lib/FileLoader.h"


namespace tyLib{

class BulletFactory;

class Ship;

/**
 * @brief Model representing a Gun
 */
class Gun : public Entity {
public:
	/**
	 * Construct a Gun with a given Direction as location and a Bulletfactory for shooting bullets
	 */
	Gun(Ship* ship, Direction& direction,  BulletFactory* bulletFactory, XMLGunBlueprint const blueprint);

	virtual void move(Direction const direction, double const delta){};

	/**
	 * @brief Shoot a bullet from the gun
	 */
	void shoot();

	virtual ~Gun();
private:
	BulletFactory* fBulletFactory;
	Ship const * const fFrom;
	Direction fDirection;
};

}

#endif /* LIBRARY_MODELS_GUN_H_ */
