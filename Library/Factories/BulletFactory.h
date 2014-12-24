/*
 * BulletFactory.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_FACTORIES_BULLETFACTORY_H_
#define LIBRARY_FACTORIES_BULLETFACTORY_H_

class World;

#include "../Models/World.h"
#include "../Models/Bullet.h"

/**
 * @brief A factory for constructing Bullets
 */
class BulletFactory {
public:
	/**
	 * @brief Construct a BulletFactory
	 */
	BulletFactory(World* worldPtr, Ship* from);

	/**
	 * @brief Build a blue bullet
	 */
	Bullet* blue(Point location);

	virtual ~BulletFactory();
private:
	World* fWorld;

	Ship* fFrom;
};

#endif /* LIBRARY_FACTORIES_BULLETFACTORY_H_ */
