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
#include "../Lib/Direction.h"
#include "../Lib/FileLoader.h"

namespace tyLib{

class World;
class Gun;

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
	 * Build a gun based upon an given name and Point and if it's the player
	 */
	Gun* build(std::string, Ship* ship, bool isPlayer);

	virtual ~GunFactory();
private:
	World* fWorld;
};

}

#endif /* LIBRARY_FACTORIES_GUNFACTORY_H_ */
