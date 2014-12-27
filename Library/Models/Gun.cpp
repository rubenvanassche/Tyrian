/*
 * Gun.cpp
 *
 *  Created on: 24-dec.-2014
 *      Author: Ruben
 */

#include "Gun.h"

namespace tyLib{

Gun::Gun(Point location, BulletFactory* bulletFactory) {
	this->fPoint = location;
	this->fSize = Size(0,0);
	this->fBulletFactory = bulletFactory;
}

void Gun::shoot(){
	this->fBulletFactory->blue(this->fPoint);
}


Gun::~Gun() {
	// Delete the bulletfactory
	delete this->fBulletFactory;
}

}
