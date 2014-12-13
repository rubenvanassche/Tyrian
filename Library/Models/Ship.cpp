/*
 * Ship.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

Ship::Ship() {
	// TODO Auto-generated constructor stub

}

void Ship::move(Direction const direction){
	if(direction.isLeft()){
		this->fPoint.x -= this->fSpeed;
	}

	if(direction.isRight()){
		this->fPoint.x += this->fSpeed;
	}

	if(direction.isUp()){
		this->fPoint.y += this->fSpeed;
	}

	if(direction.isDown()){
		this->fPoint.y -= this->fSpeed;
	}

}

Point Ship::getLocation() const{
	return this->fPoint;
}

Size Ship::getSize() const{
	return this->fSize;
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

