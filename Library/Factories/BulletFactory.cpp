/*
 * BulletFactory.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "BulletFactory.h"
namespace tyLib{

BulletFactory::BulletFactory(World* worldPtr, Ship* from) {
	this->fWorld = worldPtr;
	this->fFrom = from;
}

Bullet* BulletFactory::blue(Vector location){
	Size size(5,5);
	Vector velocity = Vector(50,50);
	Bullet* bullet = new Bullet(location, size, velocity, 10, this->fFrom);
	bullet->setType("blue");

	this->fWorld->addBullet(bullet);

	return bullet;
}

BulletFactory::~BulletFactory() {
	// TODO Auto-generated destructor stub
}

}
