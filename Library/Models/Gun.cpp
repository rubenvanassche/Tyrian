/*
 * Gun.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "Gun.h"

Gun::Gun(Point location, BulletFactory* bulletFactory, Ship* ship) {
	this->fPoint = location;
	this->fSize = Size(0,0);
	this->fShip = ship;
	this->fBulletFactory = bulletFactory;
}

void Gun::shoot(){
	this->fBulletFactory->blue(this->fPoint);
}


Gun::~Gun() {
	// Delete the bulletfactory
	delete this->fBulletFactory;
}

