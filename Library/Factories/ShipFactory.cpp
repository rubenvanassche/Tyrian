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

void ShipFactory::buildStage(XMLStage stage){
	if(this->fWorld == nullptr){
		throw std::runtime_error("Can't build any ships because there is no World* avaible");
	}

	FileLoader loader;
	std::map<std::string, XMLShipBlueprint> blueprints = loader.getShipBlueprints();

	for(auto i : stage.ships){
		if ( blueprints.find(i.type) == blueprints.end()) {
			std::runtime_error("Not an valid ship type");
		}

		XMLShipBlueprint blueprint = blueprints.at(i.type);
		Vector location(i.x, i.y);

		Ship* ship = this->buildShip(location, blueprint, false);

		// Add the ship to the ships list
		this->fWorld->addShip(ship);
	}
}

Ship* ShipFactory::buildShip(Vector const location, XMLShipBlueprint const blueprint, bool const isPlayer){
	Ship* ship = new Ship(location, blueprint);
	ship->setGun(this->fGunFactory->build(blueprint.gun, ship, isPlayer));
	return ship;
}


ShipFactory::~ShipFactory() {
	// TODO Auto-generated destructor stub
}

}
