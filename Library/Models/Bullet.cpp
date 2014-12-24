/*
 * Bullet.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Bullet.h"

Bullet::Bullet() {
	// TODO Auto-generated constructor stub

}

void Bullet::move(Direction const direction){
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

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

