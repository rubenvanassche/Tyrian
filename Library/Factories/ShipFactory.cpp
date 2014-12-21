/*
 * ShipFactory.cpp
 *
 *  Created on: 21-dec.-2014
 *      Author: Ruben
 */

#include "ShipFactory.h"

ShipFactory::ShipFactory(std::list<Ship*> *shipsPtr) {
	this->fShips = shipsPtr;

}

void ShipFactory::build(XMLStage stage){
	for(auto i : stage.ships){
		Ship* ship = nullptr;

		// Build a standard ship
		if(i.type == "standard"){
			ship = this->standard(i);
		}

		if(ship == nullptr){
			throw std::runtime_error("Something went wrong with the ship type, not being found");
		}else{
			// Add the ship to the ships list
			this->fShips->push_back(ship);
		}
	}
}


Ship* ShipFactory::standard(XMLShip ship){
	Ship* shipPtr = new Ship();

	return shipPtr;
}

ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

