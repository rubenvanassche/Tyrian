/*
 * Bullet.cpp
 *
 *  Created on: 13-dec.-2014
 *      Author: Ruben
 */

#include "Bullet.h"

namespace tyLib{

Bullet::Bullet(Vector location, Ship* from, XMLBulletBlueprint const blueprint) {
	this->fLocation = location;
	this->fSize = blueprint.size;
	this->fVelocity = blueprint.velocity;
	this->fDamage = blueprint.damage;
	this->fType = blueprint.type;
	this->fFrom = from;

	this->addTexture(blueprint.texture);
}

void Bullet::move(Direction const direction, double const delta){
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

Ship* Bullet::getFrom(){
	return this->fFrom;
}

void Bullet::explode(Ship* ship){
	ship->reduceHealth(this->fDamage);
	this->fDead = true;
	this->hide();
}

bool Bullet::isDead(){
	return this->fDead;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

}
