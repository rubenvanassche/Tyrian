/*
 * GunFactory.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "GunFactory.h"

GunFactory::GunFactory(World* worldPtr) {
	this->fWorld = worldPtr;
}

Gun* GunFactory::basic(Point location, Ship* ship){
	// TODO Find a better place for this
	BulletFactory* bulletFactory = new BulletFactory(this->fWorld, ship);
	Gun* gun = new Gun(location, bulletFactory, ship);
	gun->setType("basic");

	return gun;
}

Gun* GunFactory::build(std::string gunType, Point location, Ship* ship){
	if(gunType == "basic"){
		return this->basic(location, ship);
	}

	throw std::runtime_error("Can't build a gun with this name");
}

GunFactory::~GunFactory() {
	// TODO Auto-generated destructor stub
}

