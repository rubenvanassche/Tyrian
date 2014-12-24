/*
 * ShipFactory.cpp
 *
 *  Created on: 21-dec.-2014
 *      Author: Ruben
 */

#include "ShipFactory.h"

ShipFactory::ShipFactory(){
	this->fWorld = nullptr;
}

ShipFactory::ShipFactory(World *worldPtr) {
	this->fWorld = worldPtr;

}

void ShipFactory::build(XMLStage stage){
	if(this->fWorld == nullptr){
		throw std::runtime_error("Can't build any ships because there is no World* avaible");
	}

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
			this->fWorld->ships.push_back(ship);
		}
	}
}

Ship* ShipFactory::standard(Point location){
	Size size(40, 20);

	Ship* shipPtr = new Ship(location, size);
	return shipPtr;
}


Ship* ShipFactory::standard(XMLShip ship){
	Point point(ship.x, ship.y);

	return this->standard(point);
}

ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

