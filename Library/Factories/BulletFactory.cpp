/*
 * BulletFactory.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "BulletFactory.h"

BulletFactory::BulletFactory(World* worldPtr, Ship* from) {
	this->fWorld = worldPtr;
	this->fFrom = from;
}

Bullet* BulletFactory::blue(Point location){
	Size size(5,5);
	Bullet* bullet = new Bullet(location, size, 0.5, 1, this->fFrom);
	bullet->setType("blue");

	this->fWorld->addBullet(bullet);

	return bullet;
}

BulletFactory::~BulletFactory() {
	// TODO Auto-generated destructor stub
}
