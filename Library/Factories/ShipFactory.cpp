/*
 * ShipFactory.cpp
 *
 *  Created on: 21-dec.-2014
 *      Author: Ruben
 */

#include "ShipFactory.h"

namespace tyLib{

ShipFactory::ShipFactory(World *worldPtr) {
	this->fWorld = worldPtr;
	this->fGunFactory = new GunFactory(this->fWorld);

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
			this->fWorld->addShip(ship);
		}
	}
}

Ship* ShipFactory::standard(Point location, std::string guntype){
	Size size(40, 20);
	double speed = 1;
	double health = 10;
	Ship* shipPtr = new Ship(location, size, speed, health);
	this->checkIfPlayerSet(shipPtr);
	shipPtr->setType("standard");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}


Ship* ShipFactory::standard(XMLShip ship){
	Point point(ship.x, ship.y);

	return this->standard(point, ship.gun);
}

void ShipFactory::checkIfPlayerSet(Ship* player){
	if(this->fWorld->getPlayer() == nullptr){
		this->fWorld->setPlayer(player);
	}
}

ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

}
