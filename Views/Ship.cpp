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
	if(!this->fShip->isVisible()){
		// Ship is not visible so don't draw
		return;
	}

	if(this->fShip->getType() == "fighter"){
		this->drawFighter();
		return;
	}

	if(this->fShip->getType() == "standard"){
		this->drawStandard();
		return;
	}

	if(this->fShip->getType() == "longue"){
		this->drawLongue();
		return;
	}

	sf::RectangleShape rectangle(toVector2(this->fShip->getSize()));
	rectangle.setPosition(toVector2(this->fShip->getLocation()));
	rectangle.setFillColor(sf::Color::Green);

	if(this->fShip->isVisible()){
		this->fWindow->draw(rectangle);
	}
}

void Ship::drawFighter(){
	int textureOffsetX = 0;
	int textureOffsetY = 0;

	this->drawSprite("fighter.png", this->fShip->getLocation(), this->fShip->getSize(), textureOffsetX, textureOffsetY);
}

void Ship::drawStandard(){
	if(this->fTick > 7){
		this->fTick = 0;
	}

	int textureOffsetX = 1 + this->fTick*24;
	int textureOffsetY = 171;

	this->drawSprite("ships2.png", this->fShip->getLocation(), this->fShip->getSize(), textureOffsetX, textureOffsetY);

	this->fTick++;
}

void Ship::drawLongue(){
	if(this->fTick > 7){
		this->fTick = 0;
	}

	int textureOffsetX = 4 + this->fTick*25;
	int textureOffsetY = 140;

	this->drawSprite("ships2.png", this->fShip->getLocation(), this->fShip->getSize(), textureOffsetX, textureOffsetY);

	this->fTick++;
}

bool Ship::is(tyLib::Ship* ship){
	return this->fShip == ship;
}

} /* namespace tySFML */
