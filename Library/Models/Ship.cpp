/*
 * Ship.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

Ship::Ship(Point location, Size size, double speed, double health) {
	this->fPoint = location;
	this->fSize = size;
	this->fGun = nullptr;
	this->fSpeed = speed;
	this->fHealth = health;
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

void Ship::shoot() const{
	if(this->fGun == nullptr){
		throw std::runtime_error("No gun was set");
	}

	this->fGun->shoot();
}

void Ship::setGun(Gun* gun){
	this->fGun = gun;
}

void Ship::reduceHealth(double points){
	if(points < 0){
		throw std::runtime_error("Can't reduce health of a ship by a number lower then zero");
	}

	this->fHealth -= points;
}

bool Ship::isDead(){
	if(this->fHealth <= 0){
		return true;
	}else{
		return false;
	}
}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

