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
	void build(XMLStage stage);

	/**
	 * @brief build a standard ship with a given Point and guntype
	 */
	Ship* standard(Point location, std::string guntype);

	virtual ~ShipFactory();
private:
	/**
	 * @brief build a standard ship with a given XMLShip
	 */
	Ship* standard(XMLShip ship);

	/**
	 * @brief If the player in World isn't set on time, things can go wrong so do this if this isn't done yet
	 */
	void checkIfPlayerSet(Ship* player);

	World *fWorld;

	GunFactory* fGunFactory;

};

}

#endif /* LIBRARY_FACTORIES_SHIPFACTORY_H_ */
