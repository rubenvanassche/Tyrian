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
		Vector location(i.x, i.y);
		std::string guntype = i.gun;

		// Find the ship we need to build and build it
		if(i.type == "standard"){
			ship = this->standard(location, guntype);
		}

		if(i.type == "fighter"){
			ship = this->fighter(location, guntype);
		}

		if(ship == nullptr){
			throw std::runtime_error("Something went wrong with the ship type, not being found");
		}else{
			// Add the ship to the ships list
			this->fWorld->addShip(ship);
		}
	}
}

Ship* ShipFactory::standard(Vector location, std::string guntype){
	Size size(40, 20);
	double speed = 1;
	double health = 2;

	Ship* shipPtr = new Ship(location, size, speed, health);
	shipPtr->setType("standard");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}

Ship* ShipFactory::fighter(Vector location, std::string guntype){
	Size size(17, 23);
	double speed = 4;
	double health = 10;

	Ship* shipPtr = new Ship(location, size, speed, health);
	shipPtr->setType("fighter");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}


ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

}
