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
	 * @brief Construct a ShipFactory to be used to create seperate ships
	 */
	ShipFactory();

	/**
	 * @brief Build the ships based upon an xml stage
	 */
	void build(XMLStage stage);

	/**
	 * @brief build a standard ship with a given Point
	 */
	Ship* standard(Point location);

	virtual ~ShipFactory();
private:
	/**
	 * @brief build a standard ship with a given XMLShip
	 */
	Ship* standard(XMLShip ship);

	World *fWorld;

};

}

#endif /* LIBRARY_FACTORIES_SHIPFACTORY_H_ */
