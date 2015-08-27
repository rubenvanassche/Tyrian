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

Gun* GunFactory::build(std::string const gunType, Ship* const ship, bool const isPlayer){
	FileLoader loader;
	std::map<std::string, XMLGunBlueprint> blueprints = loader.getGunBlueprints();

	if ( blueprints.find(gunType) == blueprints.end()) {
		std::runtime_error("Not an valid gun type");
	}

	XMLGunBlueprint blueprint = blueprints[gunType];
	BulletFactory* bulletFactory = new BulletFactory(this->fWorld, ship, blueprint.bullets);

	Gun* gun;
	// The direction the gun is pointed to
	if(isPlayer == true){
		// The player is up
		Direction direction("up");
		gun = new Gun(ship, direction, bulletFactory, blueprint);
	}else{
		// Enemies are down
		Direction direction("down");
		gun = new Gun(ship, direction, bulletFactory, blueprint);
	}

	return gun;
}


GunFactory::~GunFactory() {
	// TODO Auto-generated destructor stub
}

}
