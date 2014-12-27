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


namespace tyLib{

class BulletFactory;


/**
 * @brief Model representing a Gun
 */
class Gun : public Entity {
public:
	/**
	 * Construct a Gun with a given Point as location and a Bulletfactory for shooting bullets
	 */
	Gun(Point location, BulletFactory* bulletFactory);

	virtual void move(Direction direction){};

	/**
	 * @brief Shoot a bullet from the gun
	 */
	void shoot();

	virtual ~Gun();
private:
	BulletFactory* fBulletFactory;
};

}

#endif /* LIBRARY_MODELS_GUN_H_ */
