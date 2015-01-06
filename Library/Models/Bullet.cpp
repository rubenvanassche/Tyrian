/*
 * Bullet.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Bullet.h"

namespace tyLib{

Bullet::Bullet(Vector location, Size size, double speed, double damage, Ship* from) {
	this->fPoint = location;
	this->fSize = size;
	this->fSpeed = speed;
	this->fDamage = damage;
	this->fFrom = from;
}

void Bullet::move(Direction const direction){
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

Ship* Bullet::getFrom(){
	return this->fFrom;
}

void Bullet::explode(Ship* ship){
	ship->reduceHealth(this->fDamage);
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

}
