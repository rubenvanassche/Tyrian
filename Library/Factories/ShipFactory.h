/*
 * ShipFactory.h
 *
 *  Created on: 21-dec.-2014
 *      Author: Ruben
 */

#ifndef LIBRARY_FACTORIES_SHIPFACTORY_H_
#define LIBRARY_FACTORIES_SHIPFACTORY_H_

#include "../Lib/FileLoader.h"
#include "../Models/Ship.h"
#include <list>

class ShipFactory {
public:
	ShipFactory(std::list<Ship*> *shipsPtr);

	/**
	 * @brief Build the ships based upon an xml stage
	 */
	void build(XMLStage stage);

	virtual ~ShipFactory();
private:
	std::list<Ship*> *fShips;

	/**
	 * @brief build a standard ship
	 */
	Ship* standard(XMLShip ship);
};

#endif /* LIBRARY_FACTORIES_SHIPFACTORY_H_ */
