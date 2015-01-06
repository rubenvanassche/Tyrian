/*
 * Ship.cpp
 *
 *  Created on: 27-dec.-2014
 *      Author: Ruben
 */

#include "Ship.h"

namespace tySFML {

Ship::Ship(Window* window, tyLib::Ship* ship) : View(window){
	this->fShip = ship;
}

void Ship::draw(){
	sf::RectangleShape rectangle(toVector2(this->fShip->getSize()));
	rectangle.setPosition(toVector2(this->fShip->getLocation()));
	rectangle.setFillColor(sf::Color::Green);

	if(this->fShip->isVisible()){
		this->fWindow->draw(rectangle);
	}
}

bool Ship::is(tyLib::Ship* ship){
	return this->fShip == ship;
}

} /* namespace tySFML */
