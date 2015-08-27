/*
 * SFMLBridge.cpp
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#include "SFMLBridge.h"

namespace tySFML {

void SFMLBridge::createShip(tyLib::Ship* const shipPtr){
	tySFML::Ship* ship = new tySFML::Ship(window, shipPtr);
	this->ships.push_back(ship);
}
void SFMLBridge::createBullet(tyLib::Bullet* const bulletPtr){
	tySFML::Bullet* bullet = new tySFML::Bullet(window, bulletPtr);
	this->bullets.push_back(bullet);
}
void SFMLBridge::removeShip(tyLib::Ship* const shipPtr){
	std::list<tySFML::Ship*>::iterator it = ships.begin();
	while(it != this->ships.end()){
		if((*it)->is(shipPtr)){
			this->ships.erase(it++);
		}else{
			if(it != this->ships.end()){
				it++;
			}
		}
	}
}
void SFMLBridge::removeBullet(tyLib::Bullet* const bulletPtr){
	std::list<tySFML::Bullet*>::iterator it = bullets.begin();
	while(it != this->bullets.end()){
		if((*it)->is(bulletPtr)){
			this->bullets.erase(it++);
		}else{
			if(it != this->bullets.end()){
				it++;
			}
		}
	}
}

} /* namespace tySFML */
