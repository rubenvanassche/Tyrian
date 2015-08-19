/*
 * Ship.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

namespace tyLib{

Ship::Ship(Vector location, Size size, Vector velocity, double health) {
	this->fLocation = location;
	this->fSize = size;
	this->fVelocity = velocity;
	this->fGun = nullptr;
	this->fHealth = health;
	this->fScore = 0;
}

void Ship::move(Direction const direction, double const delta){
	if(direction.isLeft()){
		this->fLocation.x -= this->fVelocity.x * delta;
	}

	if(direction.isRight()){
		this->fLocation.x += this->fVelocity.x * delta;
	}

	if(direction.isUp()){
		this->fLocation.y += this->fVelocity.y * delta;
	}

	if(direction.isDown()){
		this->fLocation.y -= this->fVelocity.y * delta;
	}

}

void Ship::shoot() const{
	if(this->fGun == nullptr){
		throw std::runtime_error("No gun was set");
	}

	this->fGun->shoot();
}

void Ship::addScore(const double score){
	this->fScore += score;
}

double Ship::getScore() const{
	return this->fScore;
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

}
