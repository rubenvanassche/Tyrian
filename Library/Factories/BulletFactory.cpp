/*
 * BulletFactory.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "BulletFactory.h"
namespace tyLib{

BulletFactory::BulletFactory(World* worldPtr, Ship* const from, std::string const bulletType) {
	this->fWorld = worldPtr;
	this->fFrom = from;

	// Generate the blueprint
	FileLoader loader;
	std::map<std::string, XMLBulletBlueprint> blueprints = loader.getBulletBlueprints();

	if (blueprints.find(bulletType) == blueprints.end()) {
		std::runtime_error("Not an valid gun type");
	}
	this->fBlueprint = blueprints[bulletType];
}

Bullet* BulletFactory::build(Vector location){
	Bullet* bullet = new Bullet(location, this->fFrom, this->fBlueprint);
	this->fWorld->addBullet(bullet);
	return bullet;

}

BulletFactory::~BulletFactory() {
	// TODO Auto-generated destructor stub
}

}
