/*
 * SFMLBridge.cpp
 *
 *  Created on: 30-dec.-2014
 *      Author: Ruben
 */

#include "SFMLBridge.h"

namespace tySFML {

void SFMLBridge::createShip(tyLib::Ship* shipPtr){
	tySFML::Ship* ship = new tySFML::Ship(window, shipPtr);
	this->ships.push_back(ship);
}
void SFMLBridge::createBullet(tyLib::Bullet* bulletPtr){
	tySFML::Bullet* bullet = new tySFML::Bullet(window, bulletPtr);
	this->bullets.push_back(bullet);
}
void SFMLBridge::removeShip(tyLib::Ship* shipPtr){
	std::cout << "Removed Ship" << std::endl;
}
void SFMLBridge::removeBullet(tyLib::Bullet* bulletPtr){
	std::cout << "Removed Bullet" << std::endl;
}

} /* namespace tySFML */
