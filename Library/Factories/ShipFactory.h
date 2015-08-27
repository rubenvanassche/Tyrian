/*
 * ShipFactory.h
 *
 *  Created on: 21-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_FACTORIES_SHIPFACTORY_H_
#define LIBRARY_FACTORIES_SHIPFACTORY_H_

#include "../Lib/FileLoader.h"
#include "../Models/World.h"
#include "GunFactory.h"
#include <list>

namespace tyLib{

class World;
class GunFactory;

/**
 * @brief A factory for constructing Ships
 */
class ShipFactory {
public:
	/**
	 * @brief Construct a ShipFactory to be used with the build function
	 */
	ShipFactory(World *worldPtr);

	/**
	 * @brief Build the ships based upon an xml stage
	 */
	void buildStage(XMLStage const stage);

	Ship* buildShip(Vector const location, XMLShipBlueprint const blueprint, bool const isPlayer);

	virtual ~ShipFactory();
private:
	World *fWorld;

	GunFactory* fGunFactory;

};

}

#endif /* LIBRARY_FACTORIES_SHIPFACTORY_H_ */
