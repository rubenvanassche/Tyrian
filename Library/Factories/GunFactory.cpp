/*
 * GunFactory.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "GunFactory.h"

namespace tyLib{

GunFactory::GunFactory(World* worldPtr) {
	this->fWorld = worldPtr;
}

Gun* GunFactory::basic(Ship* ship){
	// TODO Find a better place for this
	BulletFactory* bulletFactory = new BulletFactory(this->fWorld, ship);
	Gun* gun;
	// The direction the gun is pointed to
	std::cout << "Ship: " << ship  <<std::endl;
			std::cout << "player: " << this->fWorld->getPlayer()  <<std::endl;
	if(ship == this->fWorld->getPlayer()){
		// The player is up
		Direction direction("up");
		gun = new Gun(ship, direction,  bulletFactory);
	}else{
		// Enemies are down
		Direction direction("down");
		gun = new Gun(ship, direction,  bulletFactory);
	}

	// Give it a type
	gun->setType("basic");

	return gun;
}

Gun* GunFactory::build(std::string gunType, Ship* ship){
	if(gunType == "basic"){
		return this->basic(ship);
	}

	throw std::runtime_error("Can't build a gun with this name");
}

GunFactory::~GunFactory() {
	// TODO Auto-generated destructor stub
}

}
