/*
 * GunFactory.h
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_FACTORIES_GUNFACTORY_H_
#define LIBRARY_FACTORIES_GUNFACTORY_H_

#include <string>
#include "../Models/World.h"
#include "../Models/Gun.h"
#include "BulletFactory.h"


/**
 * @brief A factory for constructing Guns
 */
class GunFactory {
public:
	/**
	 * @brief Construct a GunFactory
	 */
	GunFactory(World* worldPtr);

	/**
	 * Build a basic gun
	 */
	Gun* basic(Point location, Ship* ship);

	/**
	 * Build a gun based upon an given name and Point
	 */
	Gun* build(std::string, Point location, Ship* ship);

	virtual ~GunFactory();
private:
	World* fWorld;
	Ship* fShip;
};

#endif /* LIBRARY_FACTORIES_GUNFACTORY_H_ */
