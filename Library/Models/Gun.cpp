/*
 * Gun.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "Gun.h"

namespace tyLib{

Gun::Gun(Ship* ship, Direction& direction, BulletFactory* bulletFactory) : fDirection(direction) {
	this->fPoint = Vector(0,0);
	this->fSize = Size(0,0);
	this->fFrom = ship;
	this->fBulletFactory = bulletFactory;
}

void Gun::shoot(){
	// Let' calculate the position to shoot our bullet
	Size shipSize = this->fFrom->getSize();
	Vector shipLocation = this->fFrom->getLocation();

	Vector gunPoint;

	if(this->fDirection.isUp()){
		gunPoint.x = shipLocation.x + shipSize.width/2;
		gunPoint.y = shipLocation.y;
	}

	if(this->fDirection.isDown()){
		gunPoint.x = shipLocation.x + shipSize.width/2;
		gunPoint.y = shipLocation.y - shipSize.height;
	}

	if(this->fDirection.isLeft()){
		gunPoint.x = shipLocation.x;
		gunPoint.y = shipLocation.y + shipSize.height/2;
	}

	if(this->fDirection.isRight()){
		gunPoint.x = shipLocation.x + shipSize.width;
		gunPoint.y = shipLocation.y + shipSize.height/2;
	}

	this->fBulletFactory->blue(gunPoint);
}


Gun::~Gun() {
	// Delete the bulletfactory
	delete this->fBulletFactory;
}

}
