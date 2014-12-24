/*
 * Ship.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

Ship::Ship(Point location, Size size) {
	this->fPoint = location;
	this->fSize = size;
}

void Ship::move(Direction const direction){
	if(direction.isLeft()){
		this->fPoint.x -= this->fSpeed;
	}

	if(direction.isRight()){
		this->fPoint.x += this->fSpeed;
	}

	if(direction.isUp()){
		this->fPoint.y -= this->fSpeed;
	}

	if(direction.isDown()){
		this->fPoint.y += this->fSpeed;
	}

}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

