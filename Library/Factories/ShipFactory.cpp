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

		if(i.type == "longue"){
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
	Size size(19, 21);
	Vector velocity = Vector(50,50);
	double health = 2;

	Ship* shipPtr = new Ship(location, size, velocity, health);
	shipPtr->setType("standard");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}

Ship* ShipFactory::fighter(Vector location, std::string guntype){
	Size size(21, 24);
	Vector velocity = Vector(350,350);
	double health = 10;

	Ship* shipPtr = new Ship(location, size, velocity, health);
	shipPtr->setType("fighter");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}

Ship* ShipFactory::longue(Vector location, std::string guntype){
	Size size(15, 19);
	Vector velocity = Vector(50,50);
	double health = 3;

	Ship* shipPtr = new Ship(location, size, velocity, health);
	shipPtr->setType("longue");

	// Build the gun
	shipPtr->setGun(this->fGunFactory->build(guntype, shipPtr));

	return shipPtr;
}


ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

}
